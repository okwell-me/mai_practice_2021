#include <iostream>

using namespace std;

struct Node {
  int val;
  Node* next;
};

// Инициализации элемента односвязного списка нулями

void init(Node* node) {

}

// Отображения односвязного списка на экран
void show(Node* head) {

}

// Добавления элемента в односвязный список
void pushNode(Node* head,Node* node) {

} 


// Написать функцию вычисления среднего значения элементов списка.
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