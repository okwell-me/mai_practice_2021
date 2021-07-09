#include <iostream>
#include <cmath>
using namespace std;

struct Node {
  int val;
  Node* next;
};

void init(Node* node, int a) {
  node->val = a;
  node->next = NULL;
}

void show(Node* head)
{
  Node* bufer = head;
  while (bufer != NULL)
  {
    cout << bufer->val << " ";
    bufer = bufer->next;
  }
}

void pushNode(Node* head, Node* node)
{
  Node* bufer = head;
  while (bufer->next != NULL)
  {
    bufer = bufer->next;
  }
  bufer->next = new Node;
  bufer = bufer->next;
  bufer->val = node->val;
  bufer->next = NULL;
} 

int SkoFromList(Node* head, int size)
{
  Node* bufer = head;
  int summa = 0, summa_kvadrata = 0;
  while (bufer->next != NULL)
  {
    summa = summa + bufer->val;
    bufer = bufer->next;
  }
  summa = summa + bufer->val;
  summa = summa / size;
  bufer = head;
  while (bufer->next != NULL)
  {
    summa_kvadrata = summa_kvadrata + pow(bufer->val - summa, 2);
    bufer = bufer->next;
  }
  summa_kvadrata = summa_kvadrata + pow(bufer->val - summa, 2);
  return sqrt(summa_kvadrata / size);
}

int testInit()
{
  Node* head = new Node;
  int a = 3;
  init(head, a);
  if (head->val == 3)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

int testPushNode()
{
  Node* head = new Node;
  Node* end = new Node;
  init(head, 1);
  init(end, 10);
  if ( (head->val == 1) && (end->val == 10) )
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

int testSkoFromList() {
  Node* head = new Node;
  Node* middle = new Node;
  Node* end = new Node;
  init(head, 2);
  init(middle, 10);
  init(end, 12);
  pushNode(head, middle);
  pushNode(head, end);
  if (SkoFromList(head, 3) == 4) // sqrt(56 / 3) ~ 4
  {
    return 0;
  }
  else
  {
    return -1;
  }
}


static void runTest(int (*testFunction)(),const std::string& testName)
{
  if(testFunction()==0)
    std::cout << "Test "<< testName << " - OK" << std::endl;
  else 
    std::cout << "Test "<< testName << " - FAIL" << std::endl;
}



int main() {
  runTest(testSkoFromList,"testSkoFromList");
  runTest(testInit, "testInit");
  runTest(testPushNode, "testPushNode");
}
