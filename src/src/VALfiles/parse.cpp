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

/*
  main() for the PDDL2.2 parser

  $Date: 2009-02-05 10:50:26 $
  $Revision: 1.2 $

  This expects any number of filenames as arguments, although
  it probably doesn't ever make sense to supply more than two.

  stephen.cresswell@cis.strath.ac.uk

   Strathclyde Planning Group
 */

#include "FlexLexer.h"
#include "ptree.h"
#include <cstdio>
#include <fstream>
#include <iostream>

extern int yyparse();
extern int yydebug;

using std::ifstream;
using std::ofstream;

namespace VAL
{

    parse_category* top_thing = NULL;

    analysis an_analysis;
    analysis* current_analysis;

    yyFlexLexer* yfl;

};  // namespace VAL

char* current_filename;

using namespace VAL;

int main(int argc, char* argv[])
{
    current_analysis = &an_analysis;
    ifstream* current_in_stream;
    yydebug = 0;  // Set to 1 to output yacc trace

    yfl = new yyFlexLexer;

    // Loop over given args
    for (int a = 1; a < argc; ++a) {
        current_filename = argv[a];
        cout << "File: " << current_filename << '\n';
        current_in_stream = new ifstream(current_filename);
        if (current_in_stream->bad()) {
            // Output a message now
            cout << "Failed to open\n";

            // Log an error to be reported in summary later
            line_no = 0;
            log_error(E_FATAL, "Failed to open file");
        } else {
            line_no = 1;

            // Switch the tokeniser to the current input stream
            yfl->switch_streams(current_in_stream, &cout);
            yyparse();

            // Output syntax tree
            if (top_thing)
                top_thing->display(0);
        }
        delete current_in_stream;
    }
    // Output the errors from all input files
    current_analysis->error_list.report();
    delete yfl;
}
