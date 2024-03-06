//23ВП1, Сёмкин, Вариант 25
#include <iostream>
#include "Double_stack_list.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    List<double> li;
    for (int i{}; i < 5; i++)
        li.push(1.5 + 2*i, 1);
    for (int i{}; i < 4; i++)
        li.push(-2.5 + 2*i, 2);
    std::cout << li;
    List<double> li2;
    std::cout << "li2: "; li2 = li;
    li.push(3, 2);
    std::cout << li2;
    (li != li2) ? std::cout << "Количество элементов не совпадает\n" : std::cout << "количество элементов совпадает\n";
    li2.print(1);
    li.print(2);
    li.pop(2);
    try {
        for (int i{}; i < 3; i++)
            li.pop(1);
    }
    catch (...) {
        std::cout << "Стек пуст!\n";
    }
    try {
        for (int i{}; i < 3; i++)
            li.pop(2);
    }
    catch (...) {
        std::cout << "Стек пуст!\n";
    }
    std::cout << li;
    li.print(1);
    li.print(2);
}