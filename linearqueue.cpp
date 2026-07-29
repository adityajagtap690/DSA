#include <iostream>
using namespace std;

class Queue
{
private:
    int queue[5];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if (rear == 4)
        {
            cout << "\nQueue Overflow!";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        cout << "\nElement Inserted Successfully.";
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "\nQueue Underflow!";
            front = rear = -1;
            return;
        }

        cout << "\nDeleted Element : " << queue[front];

        front++;

        if (front > rear)
            front = rear = -1;
    }

    void display()
    {
        if (front == -1)
        {
            cout << "\nQueue is Empty.";
            return;
        }

        cout << "\nQueue Elements : ";

        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";

        cout << endl;
    }

    void peek()
    {
        if (front == -1)
        {
            cout << "\nQueue is Empty.";
            return;
        }

        cout << "\nFront Element : " << queue[front] << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n\n===== LINEAR QUEUE MENU =====";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Peek";
        cout << "\n5. Exit";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Element : ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            q.peek();
            break;

        case 5:
            cout << "\nProgram Terminated.";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 5);

    return 0;
}
