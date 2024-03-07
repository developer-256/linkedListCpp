#include <iostream>
#include "linkedListClass.cpp"
using namespace std;

void addNode(LinkedList *list)
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
        cout << "| 2: Insert at Head            |\n";
        cout << "| 3: Insert at Tail            |\n";
        cout << "| 4: Insert before             |\n";
        cout << "| 5: Insert after              |\n";
        cout << "| 6: Insert two before         |\n";
        cout << "| 7: Insert two after          |\n";
        cout << "| 0: Exit                      |\n";
        cout << "********************************\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int value, value2, reference;

        switch (choice)
        {
        case 1:
            system("cls");
            list->printLinkedList();
            break;

        case 2:
            system("cls");
            cout << "Enter the value to insert at Head: ";
            cin >> value;
            list->insertAtHead(value);
            break;

        case 3:
            system("cls");
            cout << "Enter the value to insert at Tail: ";
            cin >> value;
            list->insertAtTail(value);
            break;

        case 4:
            system("cls");
            cout << "Enter the reference term: ";
            cin >> reference;
            cout << "Enter the value to be inserted: ";
            cin >> value;
            list->insertBefore(reference, value);
            break;

        case 5:
            system("cls");
            cout << "Enter the reference term: ";
            cin >> reference;
            cout << "Enter the value to be inserted: ";
            cin >> value;
            list->insertAfter(reference, value);
            break;

        case 6:
            system("cls");
            cout << "Enter the reference term: ";
            cin >> reference;
            cout << "Enter the first value to be inserted: ";
            cin >> value;
            cout << "Enter the second value to be inserted: ";
            cin >> value2;
            list->insertTwoBefore(reference, value, value2);
            break;

        case 7:
            system("cls");
            cout << "Enter the reference term: ";
            cin >> reference;
            cout << "Enter the first value to be inserted: ";
            cin >> value;
            cout << "Enter the second value to be inserted: ";
            cin >> value2;
            list->insertTwoAfter(reference, value, value2);
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