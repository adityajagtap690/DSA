#include <iostream>
using namespace std;

const int SIZE = 10;

int hashFunction(int key)
{
    return key % SIZE;
}

void display(int table[])
{
    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " --> ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }
}

void withoutReplacement(int table[], int key)
{
    int index = hashFunction(key);

   
    if (table[index] == -1)
    {
        table[index] = key;
        return;
    }

    
    cout << "Collision for key " << key
         << " at index " << index << endl;

    
    int i = (index + 1) % SIZE;

    while (table[i] != -1)
    {
        i = (i + 1) % SIZE;
    }

    table[i] = key;
}


void withReplacement(int table[], int key)
{
    int index = hashFunction(key);

    
    if (table[index] == -1)
    {
        table[index] = key;
        return;
    }

    
    int existingIndex = hashFunction(table[index]);

    if (existingIndex != index)
    {
        
        int displacedKey = table[index];
        table[index] = key;

        cout << "Collision: " << key << " replaces "
             << displacedKey << " at index " << index << endl;

        
        int i = (index + 1) % SIZE;

        while (table[i] != -1)
        {
            i = (i + 1) % SIZE;
        }

        table[i] = displacedKey;
    }
    else
    {
       
        cout << "Collision for key " << key
             << " at index " << index << endl;

        int i = (index + 1) % SIZE;

        while (table[i] != -1)
        {
            i = (i + 1) % SIZE;
        }

        table[i] = key;
    }
}

int main()
{
    int table[SIZE];
    int choice, n, key;

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "\n1. Linear Probing Without Replacement";
    cout << "\n2. Linear Probing With Replacement";
    cout << "\nEnter your choice: ";
    cin >> choice;

    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    cout << "\nEnter " << n << " keys:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> key;

        if (choice == 1)
            withoutReplacement(table, key);
        else if (choice == 2)
            withReplacement(table, key);
        else
        {
            cout << "Invalid choice!";
            return 0;
        }
    }

    display(table);

    return 0;
}