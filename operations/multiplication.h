//
// Created by alejandro on 16/05/19.
//

#ifndef SOLVER_MANDARINE2312_MULTIPLICATION_H
#define SOLVER_MANDARINE2312_MULTIPLICATION_H

#include "operation.h"

class Multiplication : public Operation {
public:
    Multiplication(): Operation() {};

    float operate() override {
        return left->operate() * right->operate();
    }

    void fillVariables(map<string, float>*storedValues) override {
        if(left) left->fillVariables(storedValues);
        if(right) right->fillVariables(storedValues);
    }

};


#endif //SOLVER_MANDARINE2312_MULTIPLICATION_H
