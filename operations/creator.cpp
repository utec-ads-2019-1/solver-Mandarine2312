//
// Created by alejandro on 16/05/19.
//

#include "creator.h"

Operation* Creator::buildFromEquation(string equation) {

    if(skipParentesis(equation, 0) >= equation.size()-1) equation = stripExtraParenthesis(equation);

    auto findPlus = [](string equation, int in) {return (equation[in] == '+');};
    auto findMinus = [](string equation, int in){return (equation[in] == '-') and (equation[in - 1] != '/' and equation[in - 1] != '*');};
    auto findMult = [](string equation, int in) { return equation[in] == '*'; };
    auto findDiv = [](string equation, int in) { return equation[in] == '/'; };
    auto findPotency = [](string equation, int in) { return equation[in] == '^'; };

//    if(it >= equation.size() - 1) { //no hay paréntesis que se deben hacer antes
    //int in = findInEquation(equation, findPlus);

    int in1 = findInEquation(equation, findPlus);
    if (in1 != equation.size()) {
        //showBackshow(equation, in1);

        bool sign = 1;
        int beginLeft = reduceSigns(equation, in1, sign);
        //cout << "SE PASA A LA DERECHA " << equation.substr(beginLeft+1, equation.size()) << endl;
        if(sign){
                auto thisOp = new Addition();
                thisOp->setLeft(buildFromEquation(equation.substr(0, in1))); //lo que se pasa a las izquierda
                thisOp->setRight(buildFromEquation(equation.substr(beginLeft+1, equation.size()))); //lo que se pasa a la derecha
                return thisOp;
            }else{
                auto thisOp = new Substraction();
                thisOp->setLeft(buildFromEquation(equation.substr(0, in1))); //lo que se pasa a las izquierda
                thisOp->setRight(buildFromEquation(equation.substr(beginLeft+1, equation.size()))); //lo que se pasa a la derecha
                return thisOp;
            }

    } else {
        int in2 = findInEquation(equation, findMinus);
        if (in2 != equation.size()) {
            //showBackshow(equation, in2);

            bool sign = 0;
            int beginLeft = reduceSigns(equation, in2, sign);
            //cout << "SE PASA A LA DERECHA " << equation.substr(beginLeft+1, equation.size()) << endl;
            if(sign){
                auto thisOp = new Addition();
                thisOp->setLeft(buildFromEquation(equation.substr(0, in2))); //lo que se pasa a las izquierda
                thisOp->setRight(buildFromEquation(equation.substr(beginLeft+1, equation.size()))); //lo que se pasa a la derecha
                return thisOp;
            }else{
                auto thisOp = new Substraction();
                thisOp->setLeft(buildFromEquation(equation.substr(0, in2))); //lo que se pasa a las izquierda
                thisOp->setRight(buildFromEquation(equation.substr(beginLeft+1, equation.size()))); //lo que se pasa a la derecha
                return thisOp;
            }

        } else {
            int in = findInEquation(equation, findMult);
            if (in != equation.size()) {
                //showBackshow(equation, in);

                auto thisOp = new Multiplication();
                thisOp->setLeft(buildFromEquation(equation.substr(0, in))); //lo que se pasa a las izquierda
                thisOp->setRight(
                        buildFromEquation(equation.substr(in + 1, equation.size()))); //lo que se pasa a la derecha
                return thisOp;

            } else {
                in = findInEquation(equation, findDiv);
                if (in != equation.size()) {
                    //showBackshow(equation, in);

                    auto thisOp = new Division();
                    thisOp->setLeft(buildFromEquation(equation.substr(0, in))); //lo que se pasa a las izquierda
                    thisOp->setRight(
                            buildFromEquation(equation.substr(in + 1, equation.size()))); //lo que se pasa a la derecha
                    return thisOp;

                } else {
                    in = findInEquation(equation, findPotency);
                    if (in != equation.size()) {
                        //showBackshow(equation, in);

                        auto thisOp = new Power();
                        thisOp->setLeft(buildFromEquation(equation.substr(0, in))); //lo que se pasa a las izquierda
                        thisOp->setRight(
                                buildFromEquation(
                                        equation.substr(in + 1, equation.size()))); //lo que se pasa a la derecha
                        return thisOp;

                    } else {
                        auto newNumber = new Number(atof(equation.c_str()));
                        return newNumber;
                    }
                }
            }
        }
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
    int temp;
    while (in < equation.size()) {
        if(equation[in] == '('){
            temp = skipParentesis(equation, in);
            in = temp;
        }else if (condition(equation, in)) {
            return in;
        }
        in++;
    }
    return equation.size();
}

/*int Creator::findPlus(string equation, int begin) {
    int in = begin;
    int temp;
    while (in < equation.size()) {
        if (equation[in] == '+') {
            return in;
        }else if(equation[in] == '('){
            temp = skipParentesis(equation, in);
            in = temp;
        }
        in++;
    }
    return equation.size();
}*/



string Creator::showBackshow(string equation, int in) {
    std::cout << "----------------------------------------" << endl;
    std::cout << "Debería cortarse en: " << equation[in] << std::endl;
    std::cout << "Se pasaría a la izquierda: " << equation.substr(0, in);
    std::cout << "\nSe usaría para este nodo: " << equation[in];
    std::cout << "\nSe pasaría a la derecha: " << equation.substr(in + 1, equation.size()) << endl;
}

int Creator::skipParentesis(string equation, int it) {
    int parYetToClose = 0;
    while(it < equation.size() ){
        if(equation[it] == '('){
            parYetToClose++;
        }else if(equation[it] == ')'){
            parYetToClose--;
        }
        if(parYetToClose == 0){
            //cout << "El it bota " << it <<  endl;
            return it;
        }
        it++;
    }
    //cout << "El it bota " << it <<  endl;
    return it;
}

int Creator::reduceSigns(string equation, int &in, bool &end){
    int leftBegin = in;

    if(in != 0) {
        while(equation[in-1] == '+' or equation[in-1] == '-'){
            if(equation[in-1] == '+'){
                in--;
            }else if(equation[in-1] == '-'){
                in--;
                end = not end;
            }
        }
    }

    while(equation[leftBegin+1] == '+' or equation[leftBegin+1] == '-'){
        if(equation[leftBegin+1] == '+'){
            leftBegin++;
        }else if(equation[leftBegin+1] == '-'){
            leftBegin++;
            end = not end;
        }
    }
    return leftBegin;
}
