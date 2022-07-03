/**
 * This file describes the problem.
 */
#include <map>
#include <string>
#include <vector>

#include "z3++.h"

#include <piranha/math.hpp>
#include <piranha/piranha.hpp>

#ifndef KCL_problem_info
#define KCL_problem_info

// polynomials over R||Q
using pexpr = piranha::polynomial<piranha::rational, piranha::monomial<int>>;

namespace SMTPlan
{

    struct ProblemInfo
    {
        std::map<std::string, bool> staticPredicateMap;
        std::map<std::string, bool> staticFunctionMap;
        std::map<int, z3::expr> staticFunctionValues;
        std::map<int, pexpr> staticFunctionValuesPiranha;
    };

}  // namespace SMTPlan

#endif
