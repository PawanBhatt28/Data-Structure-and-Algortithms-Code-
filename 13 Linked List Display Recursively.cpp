#include <iostream>
using namespace std;


struct Node{
    int data;
    struct Node *next;
};

struct Node *first;


void create(int arr[], int n){
    struct Node *last, *t;

    first = new struct Node;
    first -> data = arr[0];
    first -> next = NULL;
    last = first;

    for(int i=1; i<n; i++){
        t = new struct Node;
        t -> data = arr[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void display(struct Node *p){  // displaying on CALLING time.
    if( p == NULL) return;
    cout << p->data << " ";
    display(p->next);
}

void display2(struct Node *p){  // displaying on RETURNIG time.
    if( p == NULL ) return;
    display2(p->next);
    cout << p->data << " ";
}

int main(){
    int arr[7] = {1,2,3,4,5,6,7};
    create(arr, 7);

    display(first); // print will be in same order as of array.
    cout << endl;
    display2(first); // print will be in reverse order as of array.
    return 0;
}
