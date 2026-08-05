#include <iostream>
using namespace std;

#define MAX 5

class Stack
{
private:
    int stack[MAX];
    int top;

public:
    // Constructor
    Stack()
    {
        top = -1;
    }

    // Push Operation
    void push(int value)
    {
        if(top == MAX - 1)
        {
            cout << "\nStack Overflow!";
            return;
        }

        top++;
        stack[top] = value;
        cout << "\nElement Pushed Successfully.";
    }

    // Pop Operation
    void pop()
    {
        if(top == -1)
        {
            cout << "\nStack Underflow!";
            return;
        }

        cout << "\nDeleted Element: " << stack[top];
        top--;
    }

    // Peek Operation
    void peek()
    {
        if(top == -1)
        {
            cout << "\nStack is Empty.";
            return;
        }

        cout << "\nTop Element: " << stack[top];
    }

    // Display Operation
    void display()
    {
        if(top == -1)
        {
            cout << "\nStack is Empty.";
            return;
        }

        cout << "\nStack Elements:\n";

        for(int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "\n======================";
        cout << "\n   LINEAR STACK MENU";
        cout << "\n======================";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "\nProgram Ended.";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 5);

    return 0;
}