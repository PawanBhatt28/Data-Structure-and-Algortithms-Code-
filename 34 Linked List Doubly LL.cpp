#include <iostream>
using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *first;

void create(int arr[], int n){

    struct Node *last, *t;

    first = new struct Node;
    first -> prev = NULL;
    first -> next = NULL;
    first -> data = arr[0];
    last = first;

    for(int i=1; i<n; i++){
        t = new struct Node;
        t -> prev = last;
        t -> next = NULL; // how is it working if assign t -> next  = last -> next;
        t -> data = arr[i];
        last -> next = t;
        last = t;
    }
}


void display(struct Node *p){
    //struct Node *q = first;
    while(p->next){
        cout << p->data << " ";
        p = p -> next;
    }
    cout << p->data;
    cout << endl;
    cout << "Ascending Done." << endl;

    while(p){
        cout << p->data << " ";
        p = p -> prev;
    }
    cout << endl;
    cout << "Descending Done." << endl;
}


int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    create(arr, n);
    display(first);
    return 0;
}
