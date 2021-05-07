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
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
    srand((unsigned)time(NULL));

    Elem* first = NULL,
        * last = NULL;

    enqueue(first, last, 1, 10);

    cout << endl;

    Info value = first->info;
    if (check(first, value)) { // перевірка на те, як елементи впорядковані
        cout << "Елементи впорядковані не за спаданням!" << endl << endl; // якщо елементи не впорядковані за спаданням
    }
    else {
        cout << "Елементи впорядковані за спаданням!" << endl << endl;  // якщо елементи впорядковані за спаданням
    }

    dequeue(first, last);

    cout << endl << endl;


}


void enqueue(Elem*& first, Elem*& last, Info k, Info numb)
{
    Info value = 1 + rand() % 100; // рандомне число
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
        if (L->info <= value) { // перевірка чи елементи впорядковані за спаданням
            return check(L, value);
        }
        else {
            return true;  // якщо не впорядковані за спаданням, то функція поверне true
        }
    }
    return false; // якщо впорядковані за спаданням, то false
}