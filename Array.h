//����� Array � ��� ������
#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <cstdlib>
#include <ctime>

class Array 
{
private:
	int _size;
	int _numThreads;
	int _sum;
	std::vector<int> _array;

	void calculateSum(int start, int end);

public:
	Array(int size, int numThreads) : _size(size), _numThreads(numThreads){}
	~Array() {}

	void generateArray(int N);//������� ������ � ��������� ��� ���������� �� 0 �� 9

	int sumArray();//����� ��������� ������� � ����� ������
	int sumArrayWithThreads();//����� ��������� ������� � ���������� �������, ������ ���������� ���� CPU
	int sumArrayWithMultipleThreads(int num);//����� ��������� ������� � ���������� ������� 8/10

	void showArray();//����� ���� ��������� ������� �� �����

};