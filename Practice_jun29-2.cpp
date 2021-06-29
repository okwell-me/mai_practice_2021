#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int averageMas(int* source, int size);
void test();

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned short int size = 0;
    cout << "Введите размер массива\n";
    cin >> size;
    int source[1000];
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        source[i] = rand() % 101;
        //cout << i + 1 << " element = " << source[i] << "\n";
    }
    cout << averageMas(source, size) / size << "\n";
    test();
}

int averageMas(int* source, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += source[i];
    }
    return sum;
}

void test()
{
    int testArr[10] = { 4,7,3,5,8,1,6,4,9,3 }; //10 значений, в сумме - 50
    int testSize = 10;
    int sum = 0;
    for (int i = 0; i < testSize; i++)
    {
        sum += testArr[i];
    }
    if (sum / testSize == 5) 
        cout << "Тест пройден, среднее значение вычислено верно";
    else 
        cout << "Тест провален, среднее значение вычислено неверно";
        

}