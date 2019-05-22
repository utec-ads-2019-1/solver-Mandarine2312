#include "tester.h"

void Tester::execute() {
    string equations[] = {
        "7/4*((3+1)*3)+3",
        "7/4*((2+-+--8)*2)+3",
        "2+(3)",
        "7/4*((1+2)^4*2)+3",
        "7*-1",
        "1-2*5/2+1-2^4+1",
        "19+-+++-++++++9",
        "((7*3)/4+6*(3^2)/2)*(-1)",
        "(5+-3)+(21/3*5)-(5^3-2)",
        "((19--45/16*100-(181^2-15*10)))",
            "(a+13)*a",
            "7/4*((a+b)*a)+3",
            "7/4*((a+-+--b)*a)+3",
            "7/4*((a+b)^4*a)+3",
            "a-2*5/2+1-2^4+a",
            "a+-+++-++++++9",
            "((7*3)/4+6*(a^2)/b)*(1)"

    };

    float results[] = {
       24,
        -18,
        5,
        286.5,
        -7,
        -18,
        28,
        -32.25,
        -86,
        -32310.75,

        //se asume que a = 3 y b = 2
        48,
        29.25,
        8.25,
        3284.25,
        -14,
        12,
        32.25
    };

    const unsigned int size = sizeof(equations) / sizeof(string);
    for (int i = 0; i < size; ++i) {
        Operation* root = Creator::buildFromEquation(equations[i]);
        root->fillVariables(new map<string, float>);
        float respuesta = root->operate();
        ASSERT(respuesta == results[i], "The solver is not working");
        cout << "Equation(" << i + 1 << ") solved" << endl;
    }
}
