//
// Created by alejandro on 16/05/19.
//

#ifndef SOLVER_MANDARINE2312_SUBSTRACTION_H
#define SOLVER_MANDARINE2312_SUBSTRACTION_H

#include "operation.h"

class Substraction : public Operation {
public:
    Substraction(): Operation() {};

    float operate(){
        return left->operate() - right->operate();
    }
};


#endif //SOLVER_MANDARINE2312_SUBSTRACTION_H
