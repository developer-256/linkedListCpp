class Node
{
private:
    int value;
    Node *nextNode;

public:
    Node() { value = 0, nextNode = nullptr; }
    Node(int value)
    {
        this->value = value;
        nextNode = nullptr;
    }
    void setValue(int value) { this->value = value; }
    void setNextNode(Node *nextNode) { this->nextNode = nextNode; }
    int getValue() { return value; }
    Node *getNextNode() { return nextNode; }
};