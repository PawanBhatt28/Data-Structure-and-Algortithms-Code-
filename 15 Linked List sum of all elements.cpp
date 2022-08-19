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


int sum(struct Node *p){
    if(p){
        return (p -> data) + sum(p -> next);
    }
}
int main(){
    int arr[7] = {1,2,3,4,5,6};
    create(arr, 7);
    cout << "Sum  : " << sum(first);
    return 0;
}
