#include <iostream>
using namespace std;


struct Node{

    int data;
    struct Node *next;
};

void createLinkedList(struct Node *p, int n){
    cout << "Creating linked list..." << endl;
    int i = 0;
    while( i != n){
        p -> data = i + 10;
        cout << "Node " << i+1 << " : " << p -> data << " " << p << endl;
        p -> next = p + sizeof(int);
        p = p -> next;
        i++;
    }
}

void displayLinkedList(struct Node *p){
    cout << endl;
    cout << "Created Linked List : " << endl;
    while( p != 0){
        cout << "Data : " << p -> data << endl;
        p = p -> next;
    }
}


int main()
{
    struct Node *p = new Node;

    createLinkedList(p, 5);
    displayLinkedList(p);

    return 0;
}
