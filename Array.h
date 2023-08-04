//класс Array и его методы
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

	void generateArray(int N);//создаем массив и заполняем его значениями от 0 до 9

	int sumArray();//сумма элементов массива в одном потоке
	int sumArrayWithThreads();//сумма элементов массива в количестве потоков, равных количеству ядер CPU
	int sumArrayWithMultipleThreads(int num);//сумма элементов массива в нескольких потоках 8/10

	void showArray();//вывод всех элементов массива на экран

};