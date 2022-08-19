#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Node *head;

void create(int arr[], int n){
    struct Node *last, *t;

    head = new struct Node;
    head -> data = arr[0];
    head -> next = head;
    last = head;

    for(int i=1; i<n; i++){
        t = new struct Node;
        t -> data = arr[i];
        t -> next = head;
        last -> next = t;
        last = t;
    }

}

void display(struct Node *p){
    if( p->next == head){
        cout << p->data << " ";
        cout << endl;
        return;
    }

    cout << p->data << " ";
    display(p->next);
}


int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    create(arr, n);
    display2(head);
}
