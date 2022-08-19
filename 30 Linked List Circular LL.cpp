#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

Node *head ;


class LinkedList{


public:
    LinkedList();
    LinkedList(int arr[], int n);
  //  ~LinkedList(); // Deconstructor not working properly

    void display();
    void displayRecursive(Node *p);
};

LinkedList :: LinkedList(int arr[], int n)
{
    Node *last, *t;

    head = new Node;
    head -> data = arr[0];
    head -> next = head;
    last = head;

    for(int i=1; i<n; i++){
        t = new Node;
        t -> data = arr[i];
        t -> next = last -> next;
        last -> next = t;
        last = t;
    }
}
/*
LinkedList :: ~LinkedList(){
    Node *p = head;
    while(head){
        head = head -> next;
        delete p;
        p = head;//
    }
}
*/
void LinkedList :: display(){
    Node *p = head;
    do{
        cout << p->data << " ";
        p = p->next;
    }while(p != head);
    cout << "DONE";
    cout << endl;
}


void LinkedList :: displayRecursive(Node *p){

    if( p->next == head){
        cout << p->data << " " ;
        cout << "Done recursively." << endl;
        return;
    }
    cout << p->data << " ";
    displayRecursive(p->next);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    LinkedList l1(arr, n);
    l1.display();
    l1.displayRecursive(head);
    cout << "out of recursion hell";
    return 0;
}
