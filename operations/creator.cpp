//
// Created by alejandro on 16/05/19.
//

#include "creator.h"

Operation* Creator::buildFromEquation(string equation) {
    if(equation == ""){
        return new Number(0);
    }

    equation = stripExtraParenthesis(equation);

    int openParenthesis = 0;
    bool isFirstOpen = true;
    int it = 0;

    while(it < equation.size() ){
        if(equation[it] == '('){
            openParenthesis++;
            isFirstOpen = false;
        }else if(equation[it] == ')'){
            openParenthesis--;
        }
        if((openParenthesis == 0) & !isFirstOpen) break;
        it++;
    }


    auto findPlusMinus = [](string equation, int in){return (equation[in] == '+' or equation[in] == '-') and (equation[in - 1] != '/' and equation[in - 1] != '*');};
    auto findMultDiv = [](string equation, int in){return equation[in] == '*' or equation[in] == '/';};
    auto findPotency = [](string equation, int in){return equation[in] == '^';};

    if(it >= equation.size() - 1) { //no hay paréntesis que se deben hacer antes
        int in = findInEquation(equation, findPlusMinus);
        if (in != equation.size()) {
            //showBackshow(equation, in);

            if(equation[in] == '+'){
                auto thisOp = new Addition();
                thisOp->setLeft(buildFromEquation(equation.substr(0, in))); //lo que se pasa a las izquierda
                thisOp->setRight(buildFromEquation(equation.substr(in+1, equation.size()))); //lo que se pasa a la derecha
                return thisOp;
            }else{
                auto thisOp = new Substraction();
                thisOp->setLeft(buildFromEquation(equation.substr(0, in))); //lo que se pasa a las izquierda
                thisOp->setRight(buildFromEquation(equation.substr(in+1, equation.size()))); //lo que se pasa a la derecha
                return thisOp;
            }

        } else {
            in = findInEquation(equation, findMultDiv);
            if (in != equation.size()) {
                //showBackshow(equation, in);

                if(equation[in] == '*'){
                    auto thisOp = new Multiplication();
                    thisOp->setLeft(buildFromEquation(equation.substr(0, in))); //lo que se pasa a las izquierda
                    thisOp->setRight(buildFromEquation(equation.substr(in+1, equation.size()))); //lo que se pasa a la derecha
                    return thisOp;
                }else{
                    auto thisOp = new Division();
                    thisOp->setLeft(buildFromEquation(equation.substr(0, in))); //lo que se pasa a las izquierda
                    thisOp->setRight(buildFromEquation(equation.substr(in+1, equation.size()))); //lo que se pasa a la derecha
                    return thisOp;
                }

            }else{
                in = findInEquation(equation, findPotency);
                if (in != equation.size()) {
                    //showBackshow(equation, in);

                    auto thisOp = new Power();
                    thisOp->setLeft(buildFromEquation(equation.substr(0, in))); //lo que se pasa a las izquierda
                    thisOp->setRight(buildFromEquation(equation.substr(in+1, equation.size()))); //lo que se pasa a la derecha
                    return thisOp;

                }else{
                    auto newNumber = new Number(atof(equation.c_str()));
                    return newNumber;
                }
            }
        }
    }else{
       // std::cout << "Debería cortar en la posición: " << equation.substr(it-1, it+2) << std::endl;
        /*std::cout << "Se pasaría a la izquierda: " << equation.substr(0, it+1);
        std::cout << "\nSe usaría para este Operation: " << equation[it+1];
        std::cout << "\nSe pasaría a la derecha: " << equation.substr(it+2, equation.size()) << endl;*/

        buildFromEquation(equation.substr(0, it+1)); //lo que se pasa a las izquierda
        buildFromEquation(equation.substr(it+2, equation.size())); //lo que se pasa a la derecha
    }
}


string Creator::stripExtraParenthesis(string equation) {
    int leftIt = 0;
    int rightIt = equation.size() - 1 ;
    while(leftIt != rightIt){
        if((equation[leftIt] == '(') & (equation[rightIt] == ')')){
            leftIt++;
            rightIt--;
        }else{
            break;
        }
    }
    return equation.substr(leftIt, equation.size()-(leftIt*2));
}

int Creator::findInEquation(string equation, function<bool (string, int)>condition) {
    int in = 0;
    while (in < equation.size()) {
        if (condition(equation, in)) {
            return in;
        }
        in++;
    }
    return equation.size();
}

string Creator::showBackshow(string equation, int in) {
    std::cout << "Debería cortarse en: " << equation[in] << std::endl;
    std::cout << "Se pasaría a la izquierda: " << equation.substr(0, in);
    std::cout << "\nSe usaría para este nodo: " << equation[in];
    std::cout << "\nSe pasaría a la derecha: " << equation.substr(in + 1, equation.size()) << endl;
}