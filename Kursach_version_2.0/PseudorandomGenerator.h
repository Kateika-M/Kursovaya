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
public:
    PseudorandomGenerator();
    void setReg(vector<int> reg);
    vector<int> gen(int N,int razryad);
};

class PseudorandomGeneratorError: public std::invalid_argument{
public:
    explicit PseudorandomGeneratorError (const std::string& what_arg):
            std::invalid_argument(what_arg) {}
    explicit PseudorandomGeneratorError (const char* what_arg):
            std::invalid_argument(what_arg) {}
};