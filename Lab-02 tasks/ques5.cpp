#include <iostream>
using namespace std;

struct Entity
{
    int id;
    string name;
};

void SortById(Entity arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i].id > arr[j].id)
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void SortByName(Entity arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i].name > arr[j].name)
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of entities you want to enter: ";
    cin >> n;

    Entity ent[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "Enter ID and Name for entity " << i + 1 << ":" << endl;
        cin >> ent[i].id >> ent[i].name;
    }

    SortById(ent, n);
    cout << "Sorted by ID:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << ent[i].id << " " << ent[i].name << endl;
    }

    SortByName(ent, n);
    cout << "Sorted by Name:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << ent[i].id << " " << ent[i].name << endl;
    }

    return 0;
}
