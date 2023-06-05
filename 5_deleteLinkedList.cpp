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

void InsertAtHeadValue(Node *&head, Node *&tail, int data)
{
    // step-1 : create a new node
    Node *newNode = new Node(data);
    // step -2 connect this node to head
    newNode->next = head;
    // step 3 Update the head
    head = newNode;
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

int findLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {

        len++;
        temp = temp->next;
    }
    return len;
}

void InsertAtPosition(int data, int position, Node *&head, Node *&tail)
{
    // check for Empty LL
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    if (position == 0)
    {
        InsertAtHeadValue(head, tail, data);
        return;
    }

    int len = findLength(head);
    if (position >= len)
    {
        InsertAtTailValue(head, tail, data);
        return;
    }

    // step-1 : find Previous and current Node
    int i = 1;
    Node *prev = head;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    // step-2 : Create a new Node
    Node *newNode = new Node(data);
    // step-3 : point newNode to Current node
    newNode->next = curr;

    // step-4 : point prev to newNode
    prev->next = newNode;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Cannot delete , LL is empty";
        return;
    }
    // deleting first node
    if (position == 1)
    {
        Node *temp = head; // head ke temp dara initialize kora holo
        head = head->next; // head ke age move kora holo
        temp->next = NULL;
        delete temp; // purono 1 position e point kora head (temp ) ke delete kora holo
    }

    int len = findLength(head);
    // deleting last node
    if (position == len)
    {
        // find prev
        int i = 1;
        Node *prev = head;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }

        // step-2
        prev->next = NULL;
        // step-3
        Node *temp = tail;
        // step-4
        tail = prev;
        // delete temp
        delete temp;
        return;
    }

    int i=1;
    Node* prev=head;
    while (i<position-1)
    {
        prev=prev->next;
        i++;
    }

    Node* curr=prev->next;

    //step-2

    prev->next=curr->next;

    // curr Mark NULL
    curr->next=NULL;
    // step 4
    delete curr;
    
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    InsertAtTailValue(head, tail, 10);
    InsertAtTailValue(head, tail, 20);
    InsertAtTailValue(head, tail, 30);
    InsertAtTailValue(head, tail, 40);

    Print(head);
    cout << endl;
    // cout << "Length : " << findLength(head);
    //  InsertAtPosition(23,3,head,tail);
    //  cout<<"After iniserting value : ";
    //  Print(head);

    deleteNode(3, head, tail);
    Print(head);
}