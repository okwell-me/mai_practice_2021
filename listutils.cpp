#include <iostream>

using namespace std;

struct Node {
  int val;
  Node* next;
};

// ������������� �������� ������������ ������ ������

void init(Node* node) {

}

// ����������� ������������ ������ �� �����
void show(Node* head) {

}

// ���������� �������� � ����������� ������
void pushNode(Node* head,Node* node) {

} 


// �������� ������� ���������� �������� �������� ��������� ������.
int averageList(Node* head, int size) {

  return 0;
}



int testSkoFromList() {
  return -1;
}


static void runTest(int (*testFunction)(),const string& testName)
{
  if(testFunction()==0)
    cout << "Test "<< testName << " - OK" << endl;
  else 
    cout << "Test "<< testName << " - FAIL" << endl;
}



int main() {
  runTest(testSkoFromList,"testSkoFromList");


}