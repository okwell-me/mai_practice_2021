#include <iostream>
#include <cmath>

using namespace std;

const double g = 9.8;

struct ParamsOfBall {
    float Sy, Vy, Sx, Vx, t;
};

struct List {
    ParamsOfBall inf;
    struct List* next;
};

struct TestStruct {
    ParamsOfBall res;
    float Sy, Vy, Sx, Vx, timeBTW;
};

ParamsOfBall initInfStruct() {
    ParamsOfBall temp;
    temp.Sy = 0;
    cout << "Введите Vy" << endl;
    cin >> temp.Vy;
    temp.Sx = 0;
    cout << "Введите Vx" << endl;
    cin >> temp.Vx;
    return temp;
}

List* addElemToList(List* beg, ParamsOfBall tmp) {
    if (beg == NULL) {
        beg = new List;
        beg->inf = tmp;
        beg->inf.t = 0;
        beg->next = NULL;
        return beg;
    }
    List* temp = beg;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new List;
    temp = temp->next;
    temp->inf = tmp;
    temp->next = NULL;
    return beg;
}

void printOfInfStruct(ParamsOfBall tmp) {
    cout << endl;
    cout << "Time: " << tmp.t << endl;
    cout << "Sy = " << tmp.Sy << endl;
    cout << "Sx = " << tmp.Sx << endl;
    cout << "Vy = " << tmp.Vy << endl;
    cout << "Vx = " << tmp.Vx << endl;
}

void printList(List* begin) {
    while (begin) {
        printOfInfStruct(begin->inf);
        begin = begin->next;
    }
}

ParamsOfBall calculatingParams(List* beg, double btwTime) {
    ParamsOfBall temp;

    while (beg->next != NULL) {
        beg = beg->next;
    }

    temp.t = beg->inf.t + btwTime;

    if (temp.t < 2 * beg->inf.Vy / g) {
        temp.Sx = beg->inf.Vx * temp.t;
        temp.Sy = beg->inf.Vy * temp.t - g * temp.t * temp.t / 2;
        temp.Vy = beg->inf.Vy - g * temp.t;
        temp.Vx = beg->inf.Vx;
    }
    else {
        temp.Sx = 2 * beg->inf.Vx * temp.t / g;
        temp.Sy = 0;
        temp.Vx = 0;
        temp.Vy = 0;
    }

    if (temp.Sy < 0)
        temp.Sy = 0;

    return temp;
}


List* mainCalculating(List* beg) {
    if (beg == NULL) {
        return beg;
    }
    List* temp = beg;
    double btwTime = 0;

    while (btwTime <= 0) {
        cout << "Введите интервал времени: " << endl;
        cin >> btwTime;
    }

    while (calculatingParams(temp, btwTime).Sy != 0) {
        beg = addElemToList(beg, calculatingParams(temp, btwTime));
        temp = temp->next;
    }
    beg = addElemToList(beg, calculatingParams(temp, btwTime));
    printList(beg);
    return beg;
}

List* ClnMem(List* beg) {
    List* temp = beg;
    while (beg->next) {
        beg = beg->next;
        delete temp;
        temp = beg;
    }
    delete beg;
    beg = NULL;
    return beg;
}

bool comprasionOfParams(ParamsOfBall p1, ParamsOfBall p2) {
    if ((p1.Sx == p2.Sx) && (p1.Sy == p2.Sy) && (p1.Vx == p2.Vx) && (p1.Vy == p2.Vy) && (p1.t == p2.t)) {
        return true;
    }
    return false;
}

bool testCalculating(TestStruct test) {
    List* someList = NULL;
    ParamsOfBall temp;
    temp.Vy = test.Vy;
    temp.Vx = test.Vx;
    temp.Sy = test.Sy;
    temp.Sx = test.Sx;
    someList = addElemToList(someList, temp);

    if (comprasionOfParams(calculatingParams(someList, test.timeBTW), test.res)) {
        return true;
    }

    return false;
}

void RunTest() {
    TestStruct* arrToTests = new TestStruct[1];

    arrToTests[0].Vx = 10;
    arrToTests[0].Vy = 5;
    arrToTests[0].Sx = 0;
    arrToTests[0].Sy = 0;
    arrToTests[0].timeBTW = 1;

    arrToTests[0].res.Sx = (float)10;
    arrToTests[0].res.Vy = (float)-4.8;
    arrToTests[0].res.Vx = (float)10;
    arrToTests[0].res.Sy = (float)0.1;
    arrToTests[0].res.t = (float)1;

    if (testCalculating(arrToTests[0])) {
        cout << "Тестирование пройдено" << endl;
    }
    else {
        cout << "Ошибка. Тестирование не пройдено" << endl;
    }

}

int main() {
    setlocale(LC_ALL, "Russian");
    List* begin = NULL;
    int choice = 0;
    while (true) {
        cout << endl;
        cout << "МЕНЮ" << endl;
        cout << "1 – Ввод начальных данных" << endl;
        cout << "2 – Расчёт ситуации" << endl;
        cout << "3 – Тестирование" << endl;
        cout << "4 – Выход" << endl;
        cout << "=========================" << endl;
        cout << "Введите номер пункта меню" << endl;
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
            cout << "Введен неверный пункт меню" << endl;
            break;
        }
    }
    return 0;
}
