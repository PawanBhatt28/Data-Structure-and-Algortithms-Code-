#include <iostream>
using namespace std ;

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
        t -> next = NULL;
        t -> prev = last;
        last -> next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }cout << endl;

}


int Delete(struct Node *p, int index){
    if(index < 0 || index > 5) return -1;
    int data;
    if(index == 0){
        data = first->data;
        delete first;
        first = first->next;
    }else{
        for(int i=0; i<index-2; i++) p = p->next;

        data = p->next->data;
        p->next = p->next->next;
        delete p->next;

    }
    return data;
}


int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    create(arr, n);
    display(first);
    cout << "DATA : " << Delete(first, 0) << endl;
    display(first);
    cout << "DATA : " << Delete(first, 5) << endl;
    display(first);
    cout << "DATA : " << Delete(first, 1) << endl;
    display(first);
    cout << "DATA : " << Delete(first, 3) << endl;
    display(first);
    return 0;
}
