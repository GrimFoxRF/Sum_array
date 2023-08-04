//программа подсчета суммы элементов массива,
//с использованием многопоточности и без нее
#include <iostream>
#include <thread>
#include <Windows.h>
#include <chrono>
#include <iomanip>
#include "Functions.h"
#include "Array.h"

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    
    int N;

    std::cout << "\n\t-----Многопоточная сортировка массива-----\n" << std::endl;

    int M = coreNumber();//выводим на экран количество ядер процессора
    int doubleTreadsNum = M * 2; //8 при 4-хядерном процессоре
    int tenTreads = 10; //фиксированно 10 потоков 

    std::cout << "\nВведите размер массива: ";
    std::cin >> N;
    std::cin.clear();

    Array array(N, M);

    array.generateArray(N);//создаем массив и заполняем его
    //array.showArray(); //с большими массивами лучше не использовать

    std::cout << "\n\t-----Подсчет суммы элементов массива в одном потоке-----" << std::endl;
    
    auto start1 = std::chrono::high_resolution_clock::now();
    int totalSum = array.sumArray();
    auto end1 = std::chrono::high_resolution_clock::now();

    // Выводим результат и время выполнения
    std::cout << "\nИтог суммирования: " << totalSum << std::endl;
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
    std::cout << "Метод выполнялся: " << duration1.count() << " микросекунд\n" << std::endl;
    
    std::cout << "\n\t-----Подсчет суммы элементов массива в " << M << " потоках-----" << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    int totalSumWithThreads = array.sumArrayWithThreads();
    auto end2 = std::chrono::high_resolution_clock::now();

    std::cout << "\nИтог суммирования: " << totalSumWithThreads << std::endl;
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
    std::cout << "Метод выполнялся: " << duration2.count() << " микросекунд\n" << std::endl;
    
    std::cout << "\n\t-----Подсчет суммы элементов массива в " << doubleTreadsNum << " потоках-----" << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    int totalSumWithDoubleThreads = array.sumArrayWithMultipleThreads(doubleTreadsNum);
    auto end3 = std::chrono::high_resolution_clock::now();

    std::cout << "\nИтог суммирования: " << totalSumWithDoubleThreads << std::endl;
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);
    std::cout << "Метод выполнялся: " << duration3.count() << " микросекунд\n" << std::endl;

    std::cout << "\n\t-----Подсчет суммы элементов массива в " << tenTreads << " потоках-----" << std::endl;

    auto start4 = std::chrono::high_resolution_clock::now();
    int totalSumWithTenThreads = array.sumArrayWithMultipleThreads(tenTreads);
    auto end4 = std::chrono::high_resolution_clock::now();

    std::cout << "\nИтог суммирования: " << totalSumWithTenThreads << std::endl;
    auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4);
    std::cout << "Метод выполнялся: " << duration4.count() << " микросекунд\n" << std::endl;

    //табличка с результатами
    std::cout << "\n\nРезультат вычисления суммы элементов для массива размером " << N << ",\nна "<< M <<"-ядерном процессоре:\n" << std::endl;

    std::cout << "+---------------+---------------+" << std::endl;

    std::cout << "|" << std::left << std::setw(15) << "Потоки"<< "|"
        << std::right << std::setw(15) << "Время (мкс)" << "|"
        << std::endl;
    std::cout << "+---------------+---------------+" << std::endl;
    std::cout << "|" << std::left << std::setw(15) << "1" << "|"
        << std::right << std::setw(15) << duration1.count() << "|"
        << std::endl;
    std::cout << "+---------------+---------------+" << std::endl;
    std::cout << "|" << std::left << std::setw(15) << M << "|"
        << std::right << std::setw(15) << duration2.count() << "|"
        << std::endl;
    std::cout << "+---------------+---------------+" << std::endl;
    std::cout << "|" << std::left << std::setw(15) << doubleTreadsNum << "|"
        << std::right << std::setw(15) << duration3.count() << "|"
        << std::endl;
    std::cout << "+---------------+---------------+" << std::endl;
    std::cout << "|" << std::left << std::setw(15) << tenTreads << "|"
        << std::right << std::setw(15) << duration4.count() << "|"
        << std::endl;
    std::cout << "+---------------+---------------+\n" << std::endl;

    system("pause");
    return 0;
}
