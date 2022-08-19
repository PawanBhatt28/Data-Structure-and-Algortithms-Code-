#include <iostream>
using namespace std;



struct Node{
    int data;
    struct Node *next;
};

struct Node *first;

void create(int arr[], int n)
{
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

void reverseLL(struct Node *p){
    struct Node *r, *q;
    r = q = NULL;
    while(p){
        r = q;
        q = p;
        p = p->next;
        q -> next = r;
    }
    first = q;
}

void reverseRecursively(struct Node *p, struct Node *q){
    if( p == NULL ){
        first = q;
        return;
    }
    reverseRecursively(p -> next, p);
    p -> next = q;
}


void display(struct Node *p){
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    int n = 6;
    int arr[n] = {1,2,3,4,5,6};
    create(arr, n);
    display(first);
    reverseRecursively(first, NULL);

    display(first);

}
