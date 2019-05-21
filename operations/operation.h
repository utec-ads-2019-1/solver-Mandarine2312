#ifndef OPERATION_H
#define OPERATION_H

#include <string>
#include <iostream>
#include <functional>
#include <map>

using namespace std;

class Operation {
    protected:
        string equation;
        Operation * left;
        Operation * right;

    Operation(): left(nullptr), right(nullptr) {};

    Operation(string equation): left(nullptr), right(nullptr), equation(equation) {};


public:
        inline string name() { return equation; }

        virtual float operate() = 0;

        inline void setLeft(Operation * op) {left = op;};

        inline void setRight(Operation * op) {right = op;};

        virtual void fillVariables(map<string, float>*storedValues) = 0;
};

#endif