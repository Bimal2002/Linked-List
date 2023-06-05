#include <bits/stdc++.h>
using namespace std;
class Node
{   public:
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
void Print(Node* &head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    
    first->next=second;
    second->next=third;
    cout<<"Link-list values are : ";
    Print(first);

    delete first;
    delete  second;
    delete third;

    return 0;

}