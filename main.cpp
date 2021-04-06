#include <iostream>
using namespace std;

void getch(){
    cout << "Нажмите любую клавишу, чтобы продолжить...";
    getchar();
    system("clear");
}

void get_data(){
    system("clear");
    cout << "\t\t\t\tВведите параметры:" << endl;

    cout << "Кол-во чисел: ";
    int N;
    cin >> N;
    if(cin.fail() || (N < 0) || (N > 10000) ){
        cin.clear();
        cin.ignore(32767, '\n');
        get_data();
    }

    cout << "Разрядность чисел (max.48): ";
    int R;
    cin >> R;
    if(cin.fail() || (R < 0) || (R > 48)){
        cin.clear();
        cin.ignore(32767, '\n');
        get_data();
    }

    cout << "Выберите конечное преобразование числа (16-ая, 8-ая, 2-ая): ";
    int chislo;
    cin >> chislo;
    if(cin.fail() || (chislo != 16) && (chislo != 8) && ((chislo != 2))){
        cin.clear();
        cin.ignore(32767, '\n');
        get_data();
    }

    getch();
}
void menu(){
    system("clear");
    cout << "\t\t\tВыберите один из предложенных пунктов:" << endl;
    cout << "1. Генерация псевдослучайной последовательности" << endl;
    cout << "2. Выдача справки по программе" << endl;
    cout << "Введите свой выбор: ";
    int variant;
    cin >> variant;
    if(cin.fail()){//ли введены
        cin.clear();
        cin.ignore(32767, '\n');
        menu();
    }
    switch(variant){
        case 1:
            get_data();
            break;
        case 2:
            //spravka();
            break;
        default:
            menu();
            break;
    }

}
void mainmenu(){
    setlocale(LC_ALL,"ru_Rus");//использование русского алфавита
    cout << "\n\n\n\n\n\n\n\n\n" << endl;
    cout << "\t\t\t\tКурсовая работа" << endl;
    cout << "\t\t\t\t    на тему " << endl;
    cout << "\t\t  Генератор псевдослучайной последовательности\n" << endl;
    cout << "\t\t\t\t\tстудент 20ПИ1" << endl;
    cout << "\t\t\t\t\tМуромская Е.А.\n\n\n\n\n\n" << endl;
    getch();
    menu();
}

int main() {
    mainmenu();
    return 0;
}
