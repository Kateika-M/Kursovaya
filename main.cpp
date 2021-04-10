#include <iostream>
using namespace std;

void getch(){
    cout << "Нажмите любую клавишу, чтобы продолжить...";
    getchar();
    system("clear");
}

void get_data(int* ptr_kolichestvo, int* ptr_rasryadnosty, int* ptr_chislznach) {//указатели
    system("clear");
    cout << "\t\t\t\tВведите параметры:" << endl;

    cout << "Кол-во чисел: ";
    cin >> *ptr_kolichestvo;
    if(cin.fail() || (*ptr_kolichestvo < 0) || (*ptr_kolichestvo > 10000) ){
        cin.clear();
        cin.ignore(32767, '\n');
        get_data(ptr_kolichestvo,ptr_rasryadnosty,ptr_chislznach);
    }

    cout << "Разрядность чисел (max.48): ";
    cin >> *ptr_rasryadnosty;
    if(cin.fail() || (*ptr_rasryadnosty < 0) || (*ptr_rasryadnosty > 48)){
        cin.clear();
        cin.ignore(32767, '\n');
        get_data(ptr_kolichestvo,ptr_rasryadnosty,ptr_chislznach);
    }

    cout << "Выберите конечное преобразование числа (16-ая, 8-ая, 2-ая): ";
    cin >> *ptr_chislznach;
    if(cin.fail() || (*ptr_chislznach != 16) && (*ptr_chislznach != 8) && ((*ptr_chislznach != 2))){
        cin.clear();
        cin.ignore(32767, '\n');
        get_data(ptr_kolichestvo,ptr_rasryadnosty,ptr_chislznach);
    }

    getch();
}
void menu(int* ptr1_n,int* ptr1_r,int* ptr1_chislo){
    system("clear");
    cout << "\t\t\tВыберите один из предложенных пунктов:" << endl;
    cout << "1. Генерация псевдослучайной последовательности" << endl;
    cout << "2. Выдача справки по программе" << endl;
    cout << "Введите свой выбор: ";
    int variant;
    cin >> variant;
    if(cin.fail()){//еcли введены не те данные
        cin.clear();
        cin.ignore(32767, '\n');
        menu(ptr1_n,ptr1_r,ptr1_chislo);
    }
    switch(variant){
        case 1:
            get_data(ptr1_n,ptr1_r,ptr1_chislo);
            break;
        case 2:
            //spravka();
            break;
        default:
            menu(ptr1_n,ptr1_r,ptr1_chislo);
            break;
    }

}
void mainmenu(int* ptr_n,int* ptr_r,int* ptr_chislo){
    setlocale(LC_ALL,"ru_Rus");//использование русского алфавита
    cout << "\n\n\n\n\n\n\n\n\n" << endl;
    cout << "\t\t\t\tКурсовая работа" << endl;
    cout << "\t\t\t\t    на тему " << endl;
    cout << "\t\t  Генератор псевдослучайной последовательности\n" << endl;
    cout << "\t\t\t\t\tстудент 20ПИ1" << endl;
    cout << "\t\t\t\t\tМуромская Е.А.\n\n\n\n\n\n" << endl;
    getch();
    menu(ptr_n,ptr_r,ptr_chislo);
}

int main() {
    int n;
    int r;
    int chislo;

    mainmenu(&n,&r,&chislo);//передача адреса переменных

    return 0;
}
