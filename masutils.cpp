#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int averageMas(int* source, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += source[i];
    }
    return sum;
}

int testAverageMas() {
    int testArr[10] = { 4,7,3,5,8,1,6,4,9,3 }; //10 значений, в сумме - 50
    int testSize = 10;
    int sum = 0;
    for (int i = 0; i < testSize; i++)
    {
        sum += testArr[i];
    }
    if (sum / testSize != 5)
        return -1;
    return 0;
}


void runTest(int (*testFunction)(),const string& testName)
{
  if(testFunction()==0)
    cout << "Test "<< testName << " - OK" << endl;
  else 
    cout << "Test "<< testName << " - FAIL" << endl;
}



int main() {
    setlocale(LC_ALL, "Russian");
    unsigned short int size = 0;
    cout << "¬ведите размер массива\n";
    cin >> size;
    int source[1000];
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        source[i] = rand() % 101;
        //cout << i + 1 << " element = " << source[i] << "\n";
    }
    cout << "—реднее значение " << averageMas(source, size) / size << "\n";
    runTest(testAverageMas,"testAverageMas");
}

