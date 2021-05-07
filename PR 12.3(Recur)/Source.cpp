#include <iostream>
#include <Windows.h>
#include <time.h>

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

using namespace std;
void enqueue(Elem*& first, Elem*& last, Info k, Info numb);
void dequeue(Elem*& first, Elem*& last);
bool check(Elem* L, Info value);


int main()
{
    SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
    SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������
    srand((unsigned)time(NULL));

    Elem* first = NULL,
        * last = NULL;

    enqueue(first, last, 1, 10);

    cout << endl;

    Info value = first->info;
    if (check(first, value)) { // �������� �� ��, �� �������� �����������
        cout << "�������� ����������� �� �� ���������!" << endl << endl; // ���� �������� �� ����������� �� ���������
    }
    else {
        cout << "�������� ����������� �� ���������!" << endl << endl;  // ���� �������� ����������� �� ���������
    }

    dequeue(first, last);

    cout << endl << endl;


}


void enqueue(Elem*& first, Elem*& last, Info k, Info numb)
{
    Info value = 1 + rand() % 100; // �������� �����
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
    if (k < numb) {
        k++;
        enqueue(first, last, k, numb);
    }
}

void dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    else
        first->prev = NULL;
    cout << value << " ";
    if (last != NULL) {
        dequeue(first, last);
    }
}

bool check(Elem* L, Info value) {
    if (L->next != NULL)
    {
        value = L->info;
        L = L->next;
        if (L->info <= value) { // �������� �� �������� ����������� �� ���������
            return check(L, value);
        }
        else {
            return true;  // ���� �� ����������� �� ���������, �� ������� ������� true
        }
    }
    return false; // ���� ����������� �� ���������, �� false
}