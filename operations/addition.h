//
// Created by alejandro on 16/05/19.
//

#ifndef SOLVER_MANDARINE2312_OPERAND_H
#define SOLVER_MANDARINE2312_OPERAND_H

#include "operation.h"

class Addition : public Operation {
public:
    Addition(): Operation() {};

    float operate() override {
        auto respuesta = left->operate() + right->operate();
        return left->operate() + right->operate();
    }

    void fillVariables(map<string, float>*storedValues) override {
        if(left) left->fillVariables(storedValues);
        if(right) right->fillVariables(storedValues);
    }

};

#endif //SOLVER_MANDARINE2312_OPERAND_H
