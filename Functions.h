//��������������� �������
#pragma once
#include <iostream>
#include <thread>

int coreNumber() //����� �� ����� ���������� ���� CPU
{
    std::cout << "\n��������� ���������� ���� CPU..." << std::endl;
    int numCores = std::thread::hardware_concurrency();
    if (numCores > 0) {
        std::cout << "\n���������� ���� CPU: " << numCores << std::endl;
        return numCores;
    }
    else {
        std::cout << "\n������: ���������� ���������� ���� CPU\n" << std::endl;
        return 0;
    }
}