#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void Print(Node *&head)
{
    // temporary variable temp create and assine the value of head
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void InsertAtTailValue(Node *&head, Node *&tail, int data)
{

    // check for Empty LL
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // step-1 : create a new node
        Node *newNode = new Node(data);
        // step -2 connect this node to head
        tail->next = newNode;
        // step 3 Update the head
        tail = newNode;
    }
}

int main()
{   Node *head= NULL;
    Node *tail = NULL;

    InsertAtTailValue(head,tail, 10);
    InsertAtTailValue(head,tail, 20);
    InsertAtTailValue(head,tail, 30);
    InsertAtTailValue(head,tail, 40);

    Print(head);
}