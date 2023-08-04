//вспомогательные функции
#pragma once
#include <iostream>
#include <thread>

int coreNumber() //вывод на экран количества ядер CPU
{
    std::cout << "\nВычисляем количество ядер CPU..." << std::endl;
    int numCores = std::thread::hardware_concurrency();
    if (numCores > 0) {
        std::cout << "\nКоличество ядер CPU: " << numCores << std::endl;
        return numCores;
    }
    else {
        std::cout << "\nОШИБКА: вычисления количества ядер CPU\n" << std::endl;
        return 0;
    }
}