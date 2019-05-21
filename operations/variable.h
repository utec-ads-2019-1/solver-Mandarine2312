//
// Created by alejandro on 20/05/19.
//

#ifndef SOLVER_MANDARINE2312_VARIABLE_H
#define SOLVER_MANDARINE2312_VARIABLE_H

#include "operation.h"

class Variable : public Operation {

private:
    float* value;

public:
    Variable(string equation): Operation(equation), value(nullptr) {};

    inline void receiveValue (float valor) {this->value = new float; (*value) = valor; };

    float operate() override {
        if(value){ //funcionará esto????
            return *value;
        }else{
            throw ("Error: esta variable aún no recibe un valor");
        }
    }

    void fillVariables(map<string, float>*storedValues) override {
        if(storedValues->find(equation) == storedValues->end()){ //no está
            float newValue;
            cout << "Ingrese el valor de " << equation <<":\n";
            cin >> newValue;
            (*storedValues)[equation] = newValue;
            this->receiveValue(newValue);
            if(left) left->fillVariables(storedValues);
            if(right) right->fillVariables(storedValues);
        }else{
            this->receiveValue((*storedValues)["equation"]);
            if(left) left->fillVariables(storedValues);
            if(right) right->fillVariables(storedValues);
        }
    };



};

#endif //SOLVER_MANDARINE2312_VARIABLE_H
