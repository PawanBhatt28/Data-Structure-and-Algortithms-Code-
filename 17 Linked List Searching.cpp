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

struct Node* searchIt(struct Node *p, int k){
    while(p){
        if( (p->data) == k ) return p;
        p = p -> next;
    }
    return 0;
};


struct Node* searchRecursive(struct Node *p, int k){
    if( !p ){
        return 0;
    }
    else if( p->data == k){
        return p;
    }

    searchRecursive(p->next, k);
};

int main(){
    int arr[] = {1,2,3,4,5,6};
    int k = 9;
    create(arr, 6);
    cout << k << " found at : " << searchIt(first, k) << endl;
    cout << k << " found at : " << searchRecursive(first, k);

}
