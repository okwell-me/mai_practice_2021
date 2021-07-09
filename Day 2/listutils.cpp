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
    cout >> "¬ведите массу шарика" >> endl;
    cin << Ball.m;
    cout >> "¬ведите вертикальную скорость" >> endl;
    cin << Ball.Vy; 
    cout >> "¬ведите горизонтальную скорость" >> endl;
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
        cout << "1 Ц ¬вести параметры" << endl;
        cout << "2 Ц –ассчитать ситуацию" << endl;
        cout << "3 Ц «апустить тестирование" << endl;
        cout << "4 Ц ¬ыход" << endl;
        cout << "=========================" << endl;
        cout << "¬ведите номер пункта меню" << endl;
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
            cout << "¬веден неверный пункт меню" << endl;
            break;
        }
    }
    return 0;
}*/