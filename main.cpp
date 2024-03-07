#include <iostream>
#include "addNodeFunction.cpp"
using namespace std;

void removeNode(LinkedList *list);

int main()
{
    LinkedList *list = new LinkedList;

    int choice;
    do
    {
        cin.clear();
        fflush(stdin);

        cout << "________________________________\n";
        cout << "| Choose one of the following: |\n";
        cout << "********************************\n";
        cout << "| 1: Print Linked List         |\n";
        cout << "| 2: Add a node                |\n";
        cout << "| 3: Remove a node             |\n";
        cout << "| 4: Empty the list            |\n";
        cout << "| 0: Exit                      |\n";
        cout << "********************************\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            list->printLinkedList();
            break;

        case 2:
            system("cls");
            addNode(list);
            break;

        case 3:
            system("cls");
            removeNode(list);
            break;

        case 4:
            system("cls");
            delete list;
            cout << "Linked List is deleted successfully\n";
            list = new LinkedList;
            break;

        case 0:
            system("cls");
            cout << "Program to war gya\n";
            break;

        default:
            system("cls");
            cout << "Invalid Input\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

void removeNode(LinkedList *list)
{
    int choice;
    do
    {
        cin.clear();
        fflush(stdin);

        cout << "________________________________\n";
        cout << "| Choose one of the following: |\n";
        cout << "********************************\n";
        cout << "| 1: Print Linked List         |\n";
        cout << "| 2: Remove first Occurance    |\n";
        cout << "| 3: Remove all Occurances     |\n";
        cout << "| 0: Exit                      |\n";
        cout << "********************************\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int value;

        switch (choice)
        {
        case 1:
            system("cls");
            list->printLinkedList();
            break;

        case 2:
            system("cls");
            cout << "Enter the value to remove from list: ";
            cin >> value;
            list->removeFirst(value);
            break;

        case 3:
            system("cls");
            cout << "Enter the value to remove from list: ";
            cin >> value;
            list->removeAll(value);
            break;

        case 0:
            system("cls");
            break;

        default:
            system("cls");
            cout << "Invalid Input\n";
            break;
        }
    } while (choice != 0);
}

// if we add #include "linkedListClass" in this file it gives error

// if program crashes, just run other cpp files and run main.cpp again