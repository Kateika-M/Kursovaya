//
// Created by katya on 01.05.2021.
//

#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class PseudorandomGenerator{
private:
    vector<int> reg;
    int razryad;
public:
    PseudorandomGenerator();
    void setReg(vector<int> reg);
    void setRas(int razryad);
    vector<int> gen(int N);
};

class PseudorandomGeneratorError: public std::invalid_argument{
public:
    explicit PseudorandomGeneratorError (const std::string& what_arg):
            std::invalid_argument(what_arg) {}
    explicit PseudorandomGeneratorError (const char* what_arg):
            std::invalid_argument(what_arg) {}
};