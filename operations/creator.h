//
// Created by alejandro on 16/05/19.
//

#ifndef SOLVER_MANDARINE2312_CREATOR_H
#define SOLVER_MANDARINE2312_CREATOR_H


#include "operation.h"
#include "number.h"
#include "addition.h"
#include "substraction.h"
#include "multiplication.h"
#include "division.h"
#include "power.h"
#include "variable.h"

class Creator {
public:

    static Operation* buildFromEquation(string equation);

    static string stripExtraParenthesis(string equation);

    static int findInEquation(string equation, function<bool (string, int)>condition);

    static string showBackshow(string equation, int it);

    static int skipParentesis(string equation, int it);

    static int reduceSigns(string equation, int &in, bool &end);

    static bool isNumber(string& s);
};


#endif //SOLVER_MANDARINE2312_CREATOR_H
