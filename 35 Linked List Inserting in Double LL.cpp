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
    first -> data = arr[0];
    first -> prev = NULL;
    first -> next = NULL;
    last = first;

    for(int i=1; i<n; i++){
        t = new struct Node;
        t -> data = arr[i];
        t -> prev = last;
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}


void display(struct Node *p){
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


void Insert(struct Node *p, int k, int pos){
    struct Node *t;
    t = new struct Node;
    t -> data = k;
    t -> prev = t -> next = NULL;

    if(pos == 0){
        t -> next = first;
        t -> prev = first -> prev;
        first -> prev = t;
        first = t;
    }else{
        for(int i=0; i<pos-1; i++){
            p = p -> next;
        }

        t -> next = p -> next;
        t -> prev = p;
        if(pos != 7 ) p -> next -> prev = t;
        p -> next = t;
    }
}
int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    create(arr, n);
    display(first);
    Insert(first, 69, 0);
    display(first);
    Insert(first, 70, 4);
    display(first);
    Insert(first, 71, 7);
    display(first);
    return 0;
}
