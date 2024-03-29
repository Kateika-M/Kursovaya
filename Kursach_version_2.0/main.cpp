/**
* @file main.cpp
*/
#include "PseudorandomGenerator.h"
using namespace std;

int main(){
    vector<uint64_t> num;
    int a;
    uint64_t number;
    uint64_t bitrate;
    PseudorandomGenerator object;

    cout << "Приветствую вас, пользователь.Сообщаю вам, что  длина регистра 48 бит.\n"
            "Введите 1 чтобы вручную ввести регистр, 2 чтобы воспользоваться регистром по умолчанию.\n"
            "Регистр по умолчанию: 101010000010010101100111101010000010010101100111\n"
            "Или введите 0, чтобы выйти." << endl;
    cin >> a;

    if(a == 1) {
        cout << "Введите регистр.\n"
                "Регистр должен состоять из 0 или 1. Содержать минимум одну единицу.\n"
                "Символы регистра вводятся по одному. Длина регистра 48 символов." << endl;

        for (int i = 0; i < 48; i++) {
            cin >> a;
            num.push_back(a);
        }

        object.setReg(num);

    }else if(a == 2){
        num = {1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,1,0,1,1,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,1,0,1,1,0,0,1,1,1};
        object.setReg(num);
    }else{
        return 0;
    }

    cout << "Введите количество генерируемых чисел.\n"
            "Если будет введен ноль и число меньше нуля, то последовательность автоматически становится равной 1." << endl;
    cin >> number;

    if(number <= 0)
        number = 1;

    cout << "Введите разрядность числа.\n"
            "Разрядность не может превышать 48 бит."<< endl;
    cin >> bitrate;

    uint64_t count;

    for (count = 0; count < number; count++) {

        num = object.gen(bitrate);
        for (int i = 0; i < num.size(); i++)
            cout << num[i];
        cout << endl;
    }

    return 0;
}
