
@file PseudorandomGenerator.h
@author Муромская Е.А.
@version 9.0
@date 1.06.2021
@copyright ИБСТ ПГУ
@brief Заголовочный файл для модуля PseudorandomGenerator

#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

@brief Программа генерации псевдослучайной последовательности на базе регистра сдвига с линейной обратной связью в конфигурации Фибоначчи

class PseudorandomGenerator{
private:
    vector<int> reg;
public:
    PseudorandomGenerator();
    void setReg(vector<int> reg);
    vector<int> gen(int N,int razryad);
};

@brief Класс обработки ошибок PseudorandomGeneratorError

class PseudorandomGeneratorError: public std::invalid_argument{
public:
    explicit PseudorandomGeneratorError (const std::string& what_arg):
            std::invalid_argument(what_arg) {}
    explicit PseudorandomGeneratorError (const char* what_arg):
            std::invalid_argument(what_arg) {}
};