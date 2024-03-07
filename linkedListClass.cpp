#include <iostream>
#include "nodeClass.cpp"
using namespace std;

class LinkedList
{
private:
    int size;
    Node *headNode;
    Node *currentNode;

public:
    LinkedList() { size = 0, headNode = nullptr, currentNode = nullptr; }

    void printLinkedList();

    void insertAtHead(int value);
    void insertAtTail(int value);
    void insertAfter(int after, int value);
    void insertTwoAfter(int after, int value1, int value2);
    void insertBefore(int before, int value);
    void insertTwoBefore(int before, int value1, int value2);

    void removeFirst(int value);
    void removeAll(int value);
};

void LinkedList::printLinkedList()
{
    if (headNode == nullptr)
    {
        cout << "Linked List is empty\n";
        return;
    }
    cout << "Size: " << size << endl;
    currentNode = headNode;

    while (currentNode->getNextNode() != nullptr)
    {
        cout << currentNode->getValue() << " -> ";
        currentNode = currentNode->getNextNode();
    }

    cout << currentNode->getValue() << endl;
}

void LinkedList::insertAtHead(int value)
{
    Node *temp = new Node(value);

    if (headNode == nullptr)
    {
        headNode = temp;
    }
    else
    {
        temp->setNextNode(headNode);
        headNode = temp;
    }
    size++;
    cout << value << " successfully added at Head" << endl;
}

void LinkedList::insertAtTail(int value)
{
    Node *temp = new Node(value);

    if (headNode == nullptr)
    {
        headNode = temp;
        size++;
        cout << value << " successfully added at tail" << endl;
        return;
    }

    currentNode = headNode;
    while (currentNode->getNextNode() != nullptr)
    {
        currentNode = currentNode->getNextNode();
    }
    currentNode->setNextNode(temp);

    cout << value << " successfully added at tail" << endl;
    size++;
}

void LinkedList::insertAfter(int after, int value)
{
    Node *temp = new Node(value);
    bool notFound = true;
    currentNode = headNode;

    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == after)
        {
            notFound = !notFound;
            temp->setNextNode(currentNode->getNextNode());
            currentNode->setNextNode(temp);
            size++;
            cout << value << " successfully added after: " << after << endl;
            return;
        }
        currentNode = currentNode->getNextNode();
    }

    if (notFound)
    {
        cout << "Reference value not found\n";
    }
}

void LinkedList::insertTwoAfter(int after, int value1, int value2)
{
    Node *temp = new Node(value1);
    Node *temp2 = new Node(value2);
    temp->setNextNode(temp2);
    bool notFound = true;
    currentNode = headNode;

    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == after)
        {
            notFound = !notFound;
            temp2->setNextNode(currentNode->getNextNode());
            currentNode->setNextNode(temp);
            size += 2;
            cout << value1 << " and " << value2 << " successfully added after: " << after << endl;
            return;
        }
        currentNode = currentNode->getNextNode();
    }

    if (notFound)
    {
        cout << "Reference value not found\n";
    }
}

void LinkedList::insertBefore(int before, int value)
{
    Node *temp = new Node(value);
    if (headNode->getValue() == before)
    {
        temp->setNextNode(headNode);
        headNode = temp;
        size++;
        return;
    }

    Node *previousNode = headNode;
    currentNode = headNode;
    bool notFound = true;

    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == before)
        {
            notFound = !notFound;
            previousNode->setNextNode(temp);
            temp->setNextNode(currentNode);
            size++;
            cout << value << " successfully added before: " << before << endl;
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->getNextNode();
    }

    if (notFound)
    {
        cout << "Reference value not found\n";
    }
}

void LinkedList::insertTwoBefore(int before, int value1, int value2)
{
    Node *temp1 = new Node(value1);
    Node *temp2 = new Node(value2);
    temp1->setNextNode(temp2);

    if (headNode->getValue() == before)
    {
        temp2->setNextNode(headNode);
        headNode = temp1;
        size += 2;
        cout << value1 << " and " << value2 << " successfully added before: " << before << endl;
        return;
    }

    Node *previousNode = headNode;
    currentNode = headNode;
    bool notFound = true;

    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == before)
        {
            notFound = !notFound;
            previousNode->setNextNode(temp1);
            temp2->setNextNode(currentNode);
            size += 2;
            cout << value1 << " and " << value2 << " successfully added before: " << before << endl;
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->getNextNode();
    }

    if (notFound)
    {
        cout << "Reference value not found\n";
    }
}

void LinkedList::removeFirst(int value)
{
    bool notFound = true;
    Node *temp;

    if (headNode->getValue() == value)
    {
        notFound = !notFound;
        temp = headNode;
        headNode = headNode->getNextNode();
        delete temp;
        size--;
        cout << "First occurance of " << value << " is deleted" << endl;
        return;
    }

    currentNode = headNode;
    // if program reached here, it means headNode is not value to be deleted. So we will now check value next to the headNode
    while (currentNode->getNextNode() != nullptr)
    {
        if (currentNode->getNextNode()->getValue() == value)
        {
            notFound = !notFound;
            temp = currentNode->getNextNode();
            currentNode->setNextNode(temp->getNextNode());
            delete temp;
            size--;
            cout << "First occurance of " << value << " is deleted" << endl;
            return;
        }

        currentNode = currentNode->getNextNode();
    }

    if (notFound)
    {
        cout << "Reference value not found" << endl;
    }
}

void LinkedList::removeAll(int value)
{
    bool notFound = true;
    Node *temp;
    Node *previousNode;

    currentNode = headNode;
    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == value)
        {
            // delete because found
            notFound = false;
            if (previousNode == nullptr)
            {
                // value is in headNode
                headNode = headNode->getNextNode();
            }
            else
            {
                // value is not in headnode
                previousNode->setNextNode(currentNode->getNextNode());
            }

            temp = currentNode;
            currentNode = currentNode->getNextNode();
            delete temp;
        }
        else
        {
            // move to next node
            previousNode = currentNode;
            currentNode = currentNode->getNextNode();
        }
    }

    if (notFound)
    {
        cout << "Reference value not found" << endl;
    }
    else
    {
        cout << "All occurances of: " << value << " were removed" << endl;
    }
}
