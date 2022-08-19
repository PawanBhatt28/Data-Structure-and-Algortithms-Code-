#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *first;
struct Node *last;

void insertAtLast( int k, int pos){
    struct Node *t;
    t = new struct Node;
    t -> data = k ;
    t -> next = NULL;

    if( first == NULL ){
        first = last = t;
    }
    else{
        last -> next = t;
        last = t;
    }
}


void displayLL(struct Node *p){
    while(p){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}


int main(){
    int arr[5] = {1,2,3,4,5};
    for(int i=0; i<5; i++){
        insertAtLast(arr[i], i);
    }
    displayLL(first);


}
