#include <iostream>


const int MASSIZE = 1000;
int mas[MASSIZE];



// ������� 8:
// �������� ������� ���������� �������� �������� ��������� �������.
int averageMas(int* source, int size) {
  return 0;
}



//������� 3:
//�������� ������� ��������� size ��������� ��������  source � dest. ���� ������� ����� 0, ���� �� ����� -1

int testCompareMas() {
  int source[] = {0,1,2,3,4,5,6,7,8,9}; 
  int dest[] = {0,1,2,3,4,5,6,7};

  if (compareMas(source,dest,8) != 0)
    return -1;
    
  int source1[] = {0,1,2,3,4,5,6,7,8,9}; 
  int dest1[] = {1,1,2,3,4,5,6,7};

  if (compareMas(source1,dest1,8) != -1)
    return -1;

  return 0;
}


// ������� 8:
// �������� ������� ���������� �������� �������� ��������� �������.
int testAverageMas() {
  return -1;
}


void runTest(int (*testFunction)(),const std::string& testName)
{
  if(testFunction()==0)
    std::cout << "Test "<< testName << " - OK" << std::endl;
  else 
    std::cout << "Test "<< testName << " - FAIL" << std::endl;
}



int main() {
   runTest(testInitByZeroMas,"testInitByZeroMas");
   runTest(testInitMas,"testInitMas");
   runTest(testCopyMas,"testCopyMas");

   runTest(testCompareMas,"testCompareMas");
   runTest(testSkoFromMas,"testSkoFromMas");
}

