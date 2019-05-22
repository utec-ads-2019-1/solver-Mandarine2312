//
// Created by alejandro on 21/05/19.
//

#ifndef SOLVER_MANDARINE2312_GLOBALS_H
#define SOLVER_MANDARINE2312_GLOBALS_H

auto findPlus = [](string equation, int in) {return (equation[in] == '+');};
auto findMinus = [](string equation, int in){return (equation[in] == '-') and (equation[in - 1] != '/' and equation[in - 1] != '*');};
auto findMult = [](string equation, int in) { return equation[in] == '*'; };
auto findDiv = [](string equation, int in) { return equation[in] == '/'; };
auto findPotency = [](string equation, int in) { return equation[in] == '^'; };



#endif //SOLVER_MANDARINE2312_GLOBALS_H
