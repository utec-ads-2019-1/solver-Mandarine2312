//
// Created by alejandro on 16/05/19.
//

#ifndef SOLVER_MANDARINE2312_DIVISION_H
#define SOLVER_MANDARINE2312_DIVISION_H

#include "operation.h"

class Division : public Operation {
public:
    Division(): Operation() {};

    float operate(){
        return left->operate() / right->operate();
    }
};


#endif //SOLVER_MANDARINE2312_DIVISION_H
