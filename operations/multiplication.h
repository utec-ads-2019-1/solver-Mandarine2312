//
// Created by alejandro on 16/05/19.
//

#ifndef SOLVER_MANDARINE2312_MULTIPLICATION_H
#define SOLVER_MANDARINE2312_MULTIPLICATION_H

#include "operation.h"

class Multiplication : public Operation {
public:
    Multiplication(): Operation() {};

    float operate(){
        return left->operate() * right->operate();
    }
};


#endif //SOLVER_MANDARINE2312_MULTIPLICATION_H
