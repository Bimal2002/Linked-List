#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // when LL is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Non empty LL
        // step-1 : create a Node
        Node *newNode = new Node(data);
        // step-2
        newNode->next = head;
        // step-3
        head->prev = newNode;
        // step-4
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // when LL is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Non empty LL
        // step-1 : create a Node
        Node *newNode = new Node(data);
        // step-2
        tail->next = newNode;
        // step-3
        newNode->prev = tail;
        // step-4
        tail = newNode;
    }
}

void insertAtAnyPosition(Node *&head, Node *&tail, int data, int position)
{
    // if LL is empty
    if (head == NULL)
    {
        Node *newNode = new Node;
        head = newNode;
        tail = newNode;
    }
    else
    {
        // non-empty
        if (position == 1)
        {
            insertAtHead(head, tail, data);
            return;
        }

        int len = getLength(head);
        if (position > len)
        {
            insertAtTail(head, tail, data);
            return;
        }
        // insert in Middle
        // step-1  find prev and curr
        int i = 1;
        Node *prevNode = head;
        while (i < position-1)
        {
            prevNode = prevNode->next;
            i++;
        }
        Node *curr = prevNode->next;
        // step-2 : create a new node
        Node *newNode = new Node(data);

        // step3
        prevNode->next = newNode;
        newNode->prev = prevNode;
        curr->prev = newNode;
        newNode->next = curr;
    }
}

void Delete(Node* &head,Node* &tail,int position){
    if (head==NULL)
    {   // empty LL 
        cout<<"LL is empty , no need to delete";
        return;
    }
    
    if (head->next==NULL)
    {   // single element present
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        return;

    }

    if (position==1)
    {  
        // first node delete
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;

    }
    int len=getLength(head);

    if (position>len)
    {
        cout<<"Enter , valid index ";
        return;
    }

    if (position==len)
    {
        Node* temp=tail;
        tail=tail->prev;
        
        tail->next=NULL;
        temp->prev=NULL;
        delete temp;
    }
    
    // delete from middle of LL
    //step-1: find left,curr, right 
    int i=1;
    Node* left=head;
    while (i<position-1)
    {
        left=left->next;
        i++;

    }

    Node* curr=left->next;
    Node* right=curr->next;

    //step-2
    left->next=right;

    //step-3
    right->prev=left;
    //step-4
    curr->next=NULL;
    //step-5
    curr->prev=NULL;
    //step-6
    delete curr;
    
    
    
}
int main()
{

    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *head = first;
    Node *tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;
    cout << "Before value insertion: ";
    print(first);
    cout << endl;
    insertAtHead(head, tail, 33);
    cout << "After value insertion : ";
    print(head);
    cout << endl;
    cout << "After  tail insertion : ";

    insertAtTail(head, tail, 22);
    print(head);

    cout << endl;
    cout<<"after insert of value : ";
    insertAtAnyPosition(head, tail, 21, 6);
    print(head);
    cout<<endl;
    Delete(head,tail,6);
    print(head);
    return 0;
    
}