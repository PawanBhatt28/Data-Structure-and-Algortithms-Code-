#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *first;
struct Node *last;


void create(int arr[], int n){
    first = new struct Node;
    first -> data = arr[0];
    first -> next = NULL;
    last = first;

    struct Node *t;

    for(int i=1; i<n; i++){
        t = new struct Node;
        t -> data = arr[i];
        t -> next = NULL;
        last -> next  = t;
        last = t;
    }
}

int checkSorted(struct Node *p){
    while(p->next){
        if((p->data) > (p->next)->data) return 0;
        p = p->next;
    }
    return 1;
}

void display(struct Node *p){
    while(p){
        cout << p -> data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    int n= 7;
    int arr[n] = {1,2,2,4,2,4,5};
    create(arr, n);
    display(first);
    cout << checkSorted(first);
    return 0;
}
