/************************************************************************
 * Copyright 2008, Strathclyde Planning Group,
 * Department of Computer and Information Sciences,
 * University of Strathclyde, Glasgow, UK
 * http://planning.cis.strath.ac.uk/
 *
 * Maria Fox, Richard Howey and Derek Long - VAL
 * Stephen Cresswell - PDDL Parser
 *
 * This file is part of VAL, the PDDL validator.
 *
 * VAL is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * VAL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with VAL.  If not, see <http://www.gnu.org/licenses/>.
 *
 ************************************************************************/

#include "DebugWriteController.h"
#include "SimpleEval.h"
#include "TIM.h"
#include "instantiation.h"
#include "ptree.h"
#include "typecheck.h"
#include "FlexLexer.h"
#include <cstdio>
#include <fstream>
#include <iostream>

#include "PartialPlan.h"
#include "SearchSpace.h"
#include "graphconstruct.h"

using std::cerr;
using std::ifstream;

using namespace TIM;
using namespace Inst;
using namespace VAL;
using namespace Planner;

namespace VAL
{
    bool ContinueAnyway;
    bool ErrorReport;
    bool InvariantWarnings;
    bool LaTeX;

};  // namespace VAL

int main(int argc, char* argv[])
{
    performTIMAnalysis(&argv[1]);

    SimpleEvaluator::setInitialState();
    for (operator_list::const_iterator os = current_analysis->the_domain->ops->begin();
         os != current_analysis->the_domain->ops->end(); ++os) {
        cout << (*os)->name->getName() << "\n";
        instantiatedOp::instantiate(*os, current_analysis->the_problem, *theTC);
        cout << instantiatedOp::howMany() << " so far\n";
    };
    cout << instantiatedOp::howMany() << "\n";
    //instantiatedOp::writeAll(cout);

    //cout << "\nList of all literals:\n";
    instantiatedOp::createAllLiterals(current_analysis->the_problem, theTC);
    //instantiatedOp::writeAllLiterals(cout);

    Inst::ActEntry::readDurations(argv[3]);

    SearchSpace::instance().setOrdering(new LongPlanHead);
    SearchSpace::instance().findPlan();
}
