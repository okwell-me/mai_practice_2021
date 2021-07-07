#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
};

void init(Node* node, int a) {
    node->val = a;
    node->next = NULL;
}

void show(Node* head) {
    Node* current = head;
    while (current->next != NULL)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

void pushNode(Node* head, Node* node) {
    Node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new Node;
    current = current->next;
    current->val = node->val;
    current->next = NULL;
}

int SkoFromList(Node* head, int size) {
    Node* current = head;
    int sum = 0, sumSqrt = 0;
    while (current->next != NULL)
    {
        sum = sum + current->val;
        current = current->next;
    }
    sum = sum + current->val;
    sum = sum / size;
    current = head;
    while (current->next != NULL)
    {
        sumSqrt = sumSqrt + pow(current->val - sum, 2);
        current = current->next;
    }
    sumSqrt = sumSqrt + pow(current->val - sum, 2);
    return sqrt(sumSqrt / size);
}

int testInit() {
    Node* head = new Node;
    int a = 3;
    init(head, a);
    if (head->val != 3)
        return -1;
    return 0;
}

int testShow() {
    return 0;
}

int testPushNode() {
    Node* head = new Node;
    Node* end = new Node;
    init(head, 1);
    init(end, 10);
    if ((head->val != 1) || (end->val != 10))
        return -1;
    return 0;
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
    if (SkoFromList(head, 3) != 4) // sqrt(56/3) ~ 4
        return -1;
    return 0;
}


static void runTest(int (*testFunction)(), const string& testName)
{
    if (testFunction() == 0)
        cout << "Test " << testName << " - OK" << endl;
    else
        cout << "Test " << testName << " - FAIL" << endl;
}



int main() {
    runTest(testInit, "testInit");
    runTest(testPushNode, "testPushNode");
    runTest(testSkoFromList, "testSkoFromList");
}
