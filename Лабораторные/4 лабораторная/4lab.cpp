#include <iostream>
#include <locale.h>
#include "c_file.c"// добавление файла "c_file.c из этого проекта

extern "C" double   func1(int n, int x);// добавление функции из ассемблеровского файла этого проекта

void main() {

    setlocale(LC_ALL, "Russian");  
    int n, x;
    double z;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "x = ";
    std::cin >> x;

    z = func1(n, x);

    std::cout << "z = " << z;
}