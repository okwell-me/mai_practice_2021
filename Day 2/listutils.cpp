#include <iostream>
#include <cmath>

using namespace std;

const double g = 9.8;

struct ParamsOfBall
{
	float Vy, Vx, m, Sx, Sy, t;
};

ParamsOfBall Ball;

void addParOfBall()
{
    cout >> "������� ����� ������" >> endl;
    cin << Ball.m;
    cout >> "������� ������������ ��������" >> endl;
    cin << Ball.Vy; 
    cout >> "������� �������������� ��������" >> endl;
    cin << Ball.Vx;
}


int main()
{
    addParOfBall();
}

/*
int main()
{
    setlocale(LC_ALL, "Russian");
    //List* begin = NULL;
    int choice = 0;
    while (true) {
        cout << "1 � ������ ���������" << endl;
        cout << "2 � ���������� ��������" << endl;
        cout << "3 � ��������� ������������" << endl;
        cout << "4 � �����" << endl;
        cout << "=========================" << endl;
        cout << "������� ����� ������ ����" << endl;
        cin >> choice;

        switch (choice - 1) {
        case 0:
            begin = NULL;
            begin = addElemToList(begin, initInfStruct());
            break;
        case 1:
            begin = mainCalculating(begin);
            break;
        case 2:
            RunTest();
        case 3:
            return 0;
        default:
            cout << "������ �������� ����� ����" << endl;
            break;
        }
    }
    return 0;
}*/