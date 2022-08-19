#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *first = new struct Node;
struct Node *second = new struct Node;


void create(struct Node *p, int arr[], int n){
    struct Node *last, *t;

    p -> data = arr[0];
    p -> next = NULL;
    last = p;
    cout << "Creating node..";
    for(int i=1; i<n; i++){
        t = new struct Node;
        t -> data = arr[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p) {
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}


void concatenate(struct Node *p, struct Node *q){
    while(p->next) p = p -> next;
    p -> next = q;
}

int main(){
    int arr1[] = {1,2,3,4};
    int arr2[] = {5,6,7,8,9};

    create(first, arr1, 4);
    display(first);
    create(second, arr2, 5);
    display(second);
    concatenate(first, second);
    display(first);
    return 0;
}
