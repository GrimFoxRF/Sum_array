//��������� �������� ����� ��������� �������,
//� �������������� ��������������� � ��� ���
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

    std::cout << "\n\t-----������������� ���������� �������-----\n" << std::endl;

    int M = coreNumber();//������� �� ����� ���������� ���� ����������
    int doubleTreadsNum = M * 2; //8 ��� 4-�������� ����������
    int tenTreads = 10; //������������ 10 ������� 

    std::cout << "\n������� ������ �������: ";
    std::cin >> N;
    std::cin.clear();

    Array array(N, M);

    array.generateArray(N);//������� ������ � ��������� ���
    //array.showArray(); //� �������� ��������� ����� �� ������������

    std::cout << "\n\t-----������� ����� ��������� ������� � ����� ������-----" << std::endl;
    
    auto start1 = std::chrono::high_resolution_clock::now();
    int totalSum = array.sumArray();
    auto end1 = std::chrono::high_resolution_clock::now();

    // ������� ��������� � ����� ����������
    std::cout << "\n���� ������������: " << totalSum << std::endl;
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
    std::cout << "����� ����������: " << duration1.count() << " �����������\n" << std::endl;
    
    std::cout << "\n\t-----������� ����� ��������� ������� � " << M << " �������-----" << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    int totalSumWithThreads = array.sumArrayWithThreads();
    auto end2 = std::chrono::high_resolution_clock::now();

    std::cout << "\n���� ������������: " << totalSumWithThreads << std::endl;
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
    std::cout << "����� ����������: " << duration2.count() << " �����������\n" << std::endl;
    
    std::cout << "\n\t-----������� ����� ��������� ������� � " << doubleTreadsNum << " �������-----" << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    int totalSumWithDoubleThreads = array.sumArrayWithMultipleThreads(doubleTreadsNum);
    auto end3 = std::chrono::high_resolution_clock::now();

    std::cout << "\n���� ������������: " << totalSumWithDoubleThreads << std::endl;
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);
    std::cout << "����� ����������: " << duration3.count() << " �����������\n" << std::endl;

    std::cout << "\n\t-----������� ����� ��������� ������� � " << tenTreads << " �������-----" << std::endl;

    auto start4 = std::chrono::high_resolution_clock::now();
    int totalSumWithTenThreads = array.sumArrayWithMultipleThreads(tenTreads);
    auto end4 = std::chrono::high_resolution_clock::now();

    std::cout << "\n���� ������������: " << totalSumWithTenThreads << std::endl;
    auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4);
    std::cout << "����� ����������: " << duration4.count() << " �����������\n" << std::endl;

    //�������� � ������������
    std::cout << "\n\n��������� ���������� ����� ��������� ��� ������� �������� " << N << ",\n�� "<< M <<"-������� ����������:\n" << std::endl;

    std::cout << "+---------------+---------------+" << std::endl;

    std::cout << "|" << std::left << std::setw(15) << "������"<< "|"
        << std::right << std::setw(15) << "����� (���)" << "|"
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
