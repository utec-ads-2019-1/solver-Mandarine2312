//
// Created by alejandro on 16/05/19.
//

#ifndef SOLVER_MANDARINE2312_SQUARE_H
#define SOLVER_MANDARINE2312_SQUARE_H

#include "operation.h"
#include <cmath>

class Power : public Operation {
public:
    Power(): Operation() {};

    float operate() override {
        return pow(left->operate(), right->operate());
    }

    void fillVariables(map<string, float>*storedValues) override {
        if(left) left->fillVariables(storedValues);
        if(right) right->fillVariables(storedValues);
    }

};


#endif //SOLVER_MANDARINE2312_SQUARE_H
