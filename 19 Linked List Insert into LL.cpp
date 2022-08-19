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

void insertLL(int ele, int pos){
    struct Node *t;;
    t = new struct Node;
    t -> data = ele;

    if(pos == 0){
        t -> next = first;
        first  = t;
    }else{
        struct Node *p;
        p = new struct Node;
        p = first;
        for(int i=0; i<(pos-1) && p->next; i++) p = p -> next;
        t -> next = p -> next;
        p -> next = t;
    }
}


void display(struct Node *z){
    while(z){
        cout << z -> data << " ";
        z = z -> next;
    }
    cout << endl;
}

int main()
{
    int arr[6] = {1,2,3,4,5,6};
    create(arr, 6);
    display(first);
    insertLL(69, 10);
    display(first);
    return 0;
}
