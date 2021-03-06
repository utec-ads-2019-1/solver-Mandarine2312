//
// Created by alejandro on 16/05/19.
//

#ifndef SOLVER_MANDARINE2312_NUMBER_H
#define SOLVER_MANDARINE2312_NUMBER_H

#include "operation.h"

class Number : public Operation {
private:
    float value;

public:
    Number(float value): value(value), Operation() {};

    inline float operate() override { return value;}

    void fillVariables(map<string, float>*storedValues) override{
        if(left) left->fillVariables(storedValues);
        if(right) right->fillVariables(storedValues);
    }
};


#endif //SOLVER_MANDARINE2312_NUMBER_H
