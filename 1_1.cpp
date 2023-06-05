#include <iostream>
using namespace std;

// creating Linked List
class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* first = new Node(10);
    Node* second= new Node(20);
    Node* third = new Node(30);
    Node* forth = new Node(40);
    Node* fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    cout << "Printing the Linked List" << endl;
    print(first);

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;

    return 0;
}
