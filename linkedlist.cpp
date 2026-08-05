#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Create List
    void createList()
    {
        int n, value;

        cout << "\nEnter number of nodes: ";
        cin >> n;

        for(int i=1; i<=n; i++)
        {
            cout << "Enter value " << i << ": ";
            cin >> value;
            insertEnd(value);
        }

        cout << "\nLinked List Created Successfully.\n";
    }

    // Insert at Beginning
    void insertBeginning(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;
        newNode->next = head;

        head = newNode;

        cout << "\nNode Inserted at Beginning.";
    }

    // Insert at End
    void insertEnd(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        cout << "\nNode Inserted at End.";
    }

    // Delete from Beginning
    void deleteBeginning()
    {
        if(head == NULL)
        {
            cout << "\nList is Empty.";
            return;
        }

        Node *temp = head;
        head = head->next;

        delete temp;

        cout << "\nFirst Node Deleted.";
    }

    // Delete from End
    void deleteEnd()
    {
        if(head == NULL)
        {
            cout << "\nList is Empty.";
            return;
        }

        if(head->next == NULL)
        {
            delete head;
            head = NULL;

            cout << "\nLast Node Deleted.";
            return;
        }

        Node *temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

        cout << "\nLast Node Deleted.";
    }

    // Display
    void display()
    {
        if(head == NULL)
        {
            cout << "\nLinked List is Empty.";
            return;
        }

        Node *temp = head;

        cout << "\nLinked List : ";

        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main()
{
    LinkedList list;

    int choice, value;

    do
    {
        cout << "\n==============================";
        cout << "\n      LINKED LIST MENU";
        cout << "\n==============================";
        cout << "\n1. Create List";
        cout << "\n2. Insert at Beginning";
        cout << "\n3. Insert at End";
        cout << "\n4. Delete from Beginning";
        cout << "\n5. Delete from End";
        cout << "\n6. Display List";
        cout << "\n7. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                list.createList();
                break;

            case 2:
                cout << "\nEnter value: ";
                cin >> value;
                list.insertBeginning(value);
                break;

            case 3:
                cout << "\nEnter value: ";
                cin >> value;
                list.insertEnd(value);
                break;

            case 4:
                list.deleteBeginning();
                break;

            case 5:
                list.deleteEnd();
                break;

            case 6:
                list.display();
                break;

            case 7:
                cout << "\nProgram Ended.";
                break;

            default:
                cout << "\nInvalid Choice.";
        }

    } while(choice != 7);

    return 0;
}
