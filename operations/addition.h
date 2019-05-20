//
// Created by alejandro on 16/05/19.
//

#ifndef SOLVER_MANDARINE2312_OPERAND_H
#define SOLVER_MANDARINE2312_OPERAND_H

#include "operation.h"

class Addition : public Operation {
public:
    Addition(): Operation() {};

    float operate(){

        auto respuesta = left->operate() + right->operate();
        return left->operate() + right->operate();
    }
};

#endif //SOLVER_MANDARINE2312_OPERAND_H
