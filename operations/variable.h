//
// Created by alejandro on 20/05/19.
//

#ifndef SOLVER_MANDARINE2312_VARIABLE_H
#define SOLVER_MANDARINE2312_VARIABLE_H

#include "operation.h"

class Variable : public Operation {

private:
    float value;

public:
    Variable(string equation): Operation(equation) {};

    inline void receiveValue(float) {this->value = value;};

    float operate() override {
        if(value){ //funcionará esto????
            return value;
        }else{
            throw ("Error: esta variable aún no recibe un valor");
        }
    }
};

#endif //SOLVER_MANDARINE2312_VARIABLE_H
