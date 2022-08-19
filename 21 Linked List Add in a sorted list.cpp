#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *first;
struct Node *last;


void create(int arr[], int n){
    struct Node *t;
    first = new struct Node;
    first -> data = arr[0];
    first -> next = NULL;
    last  = first;

    for(int i=1; i<n; i++){
        t = new struct Node;
        t -> data = arr[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void insertInSorted(struct Node *p, int key){
    struct Node *t;
    t = new struct Node;
    t -> data = key;
    t->next = NULL;

    while(p->next){
        if( p->data > key){
            t -> next = first ;
            first = t;
            return;
        }
        if( ((p->next)->data) >= key ){
            t -> next = p -> next;
            p -> next = t;
            return;
        }
        p = p->next;
    }

    p->next = t;
    return;

}

void display(struct Node *p){
    while(p){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

int main(){
    int n = 8;
    int arr[n] = {1,2,3,3,3,5,5,5};
    create(arr, n);
    display(first);
    insertInSorted(first, 0); // 0 index
    insertInSorted(first, 4); // inbetween
    insertInSorted(first, 3); // there exist more of them
    insertInSorted(first, 9); // last index
    display(first);



}
