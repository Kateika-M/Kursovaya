
@file PseudorandomGenerator.cpp

#include "PseudorandomGenerator.h"

PseudorandomGenerator::PseudorandomGenerator(){};

@brief Конструктор класса PseudorandomGenerator
@param reg - регистр, состоящий из нулей и единиц
@warning Регистр не может состоять только из нулей
@throw PseudorandomGeneratorError, если произошла ошибка

void PseudorandomGenerator::setReg(vector<int> reg)
{
    if(reg.size() != 48)
        throw PseudorandomGeneratorError("Ошибка! Недопустимая длина регистра!");

    for(int i = 0; i < reg.size(); i++) {
        if(reg[i] != 1 && reg[i] != 0)
            throw PseudorandomGeneratorError("Ошибка! Недопустимый символ!");
    }

    int reg_sum = 0;
    for(int i = 0; i < reg.size(); i++)
        reg_sum += reg[i];
    if(reg_sum == 0)
        throw PseudorandomGeneratorError("Ошибка! Регистр из нулей!");

    this->reg = reg;
}

@brief Генерация последовательности псевдослучайных чисел
@param N - длина выходной последовательности (N > 0)
@param razryad - разрядность числа
@param Отводная последовательность (48,7,5,4,2,1,0)
@throw PseudorandomGeneratorError, если произошла ошибка
@return Псевдослучайная последовательность в виде вектора

vector<int> PseudorandomGenerator::gen(int N, int razryad = 48){

    vector<int> num;
    int new_num;

    if(N <= 0)
        throw PseudorandomGeneratorError("Ошибка! Невозможная длина выходной последовательности!");

    if ((razryad <= 0) || (razryad > 48))
        throw PseudorandomGeneratorError("Ошибка! Невозможная разрядность!");

    for(int i = 0; i < N; i++) {
        num.push_back(reg[reg.size() - 1]);

        new_num = (reg[47] ^ reg[6] ^ reg[4] ^ reg[3] ^ reg[1] ^ reg[0]) >> (48 - razryad);

        for(int j = reg.size() - 1; j > 0; j--) {
            reg[j] = reg[j - 1];
        }
        reg[0] = new_num;
    }

    return num;
}