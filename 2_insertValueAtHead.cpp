#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(){
      this->data=0;
      this->next=NULL;
    }

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void Print(Node* &head){
    //temporary variable temp create and assine the value of head
    Node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        
    }
    
}

void InsetAtHeadValue(Node* &head, int data){
    //step-1 : create a new node
    Node* newNode=new Node( data);
    // step -2 connect this node to head
    newNode->next=head;
    //step 3 Update the head
    head=newNode;

}


int main(){
    Node* head=NULL;
    //********************************************
    // Node *first=new Node(10);
    // Node *second=new Node(20);
    // Node *third=new Node(30);
    
    // first->next=second;
    // second->next=third;

    
    // cout<<"Values of Linked List : "<<endl;
    // Print(first);  //output values
    //*****************************************************

    //cout<<"after iteration : ";
    InsetAtHeadValue(head,10);
    InsetAtHeadValue(head,20);
    InsetAtHeadValue(head,30);
    InsetAtHeadValue(head,40);
    

    Print(head);

}