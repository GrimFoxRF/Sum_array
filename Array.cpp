#include "Array.h"

void Array::calculateSum(int start, int end)
{
    int sum = 0;
    while (start <= end) 
    {
        sum += _array[start++];
    }
    _sum += sum;
}

void Array::generateArray(int N)
{
    _array.clear();
    std::srand(static_cast<unsigned int>(std::time(nullptr))); //генератор случайных чисел

    for (int i = 0; i < N; ++i) {
        int randomNumber = std::rand() % 10; // —лучайное число от 0 до 9
        _array.push_back(randomNumber);
    }
}

int Array::sumArray()
{
    int sum = 0;
    for (int i = 0; i < _array.size(); i++) 
    {
        sum += _array[i];
    }
    return sum;
}

int Array::sumArrayWithThreads()
{
    std::vector<std::thread> threads;
    int start = 0;
    int end = 0;
    _sum = 0;
    int elementsCount = _size / _numThreads;

    for (int i = 0; i < _numThreads; i++) 
    {
        if (i == _numThreads - 1) 
        {
            end = _array.size();
        }
        else 
        {
            end += elementsCount;
        }

        std::thread t(&Array::calculateSum, this, start, end - 1);
        threads.push_back(std::move(t));
        start += elementsCount;
    }

    for (auto& t : threads) 
    {
        if (t.joinable()) 
        {
            t.join();
        }
    }

    return _sum;
}

int Array::sumArrayWithMultipleThreads(int num)
{
    std::vector<std::thread> threads;
    int start = 0;
    int end = 0;
    _sum = 0;
    int numThreads = num;
    int elementsCount = _size / numThreads;

    for (int i = 0; i < numThreads; i++)
    {
        if (i == numThreads - 1)
        {
            end = _array.size();
        }
        else
        {
            end += elementsCount;
        }

        std::thread t(&Array::calculateSum, this, start, end - 1);
        threads.push_back(std::move(t));
        start += elementsCount;
    }

    for (auto& t : threads)
    {
        if (t.joinable())
        {
            t.join();
        }
    }

    return _sum;
}

void Array::showArray()
{
    for (auto& values : _array) 
    {
        std::cout << values << " ";
    }
}
