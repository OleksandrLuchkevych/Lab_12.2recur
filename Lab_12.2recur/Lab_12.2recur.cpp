#include <iostream>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void Input(Elem*& first, Elem*& last, Info value)
{
    if (first == NULL)
    {
        first = new Elem;
        first->info = value;
        first->link = NULL;
        last = first;
    }
    else
    {
        Input(first->link, last, value);
    }
}

void Delete(Elem*& first, Elem*& last, Info& value)
{
    if (first == NULL) 
    {
        // Список порожній, повертаємо невизначене значення
        value = -1;
        return;
    }
    if (first == last) 
    {
        // Список містить один елемент, видаляємо його
        value = first->info;
        delete first;
        first = NULL;
        last = NULL;
        return;
    }
    // Рекурсивно викликаємо функцію для наступного елемента
    Delete(first->link, last, value);
    if (first == NULL) {
        // Якщо видалено перший елемент, оновлюємо значення змінної first
        return;
    }
    if (first->link == NULL) 
    {
        // Якщо видалено останній елемент, оновлюємо значення змінної last
        last = first;
    }
}

bool Сheck(Elem* elem)
{
    if (elem->link == NULL)
    {
        return false;
    }
    if (elem->info > elem->link->info)
    {
        return true;
    }
    return Сheck(elem->link);
}

int main()
{
    Elem* first = NULL, * last = NULL;
    int n = 12;
    for (int i = 0; i < n; i++)
    {
        Input(first, last, i);
    }
    bool count = Сheck(first);
    if (count == true)
    {
        cout << "List elements are sorted in non-descending order" << endl;
    }
    else
    {
        cout << "List elements are sorted in descending order" << endl;
    }

    cout << endl;

    Info value;
    for (int i = 0; i < n; i++)
    {
        Delete(first, last, value);
        cout << value << " ";
    }

    cout << endl;

    return 0;
}