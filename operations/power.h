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

    float operate(){
        return pow(left->operate(), right->operate());
    }
};


#endif //SOLVER_MANDARINE2312_SQUARE_H
