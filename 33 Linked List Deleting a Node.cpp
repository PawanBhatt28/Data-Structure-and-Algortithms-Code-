#include <iostream>
using namespace std;


struct Node{
    int data;
    struct Node *next;
};

struct Node *head;

void create(int arr[], int n){
    struct Node *last, *t;

    head = new struct Node;
    head -> data = arr[0];
    head -> next = head;
    last = head;

    for(int i=1; i<n; i++){
        t = new struct Node;
        t -> data = arr[i];
        t -> next = head;
        last -> next = t;
        last = t;
    }
}


void display(struct Node *p){
    if(p->next == head){
        cout << p->data << endl;
        return;
    }

    cout << p->data << " ";
    display(p->next);
}

int Length(struct Node *p){
    int l = 1;
    while(p->next != head){
        l++;
        p = p->next;
    }
    return l;
}

int Delete(struct Node *p, int pos){
    struct Node *q = NULL;
    int value;
    int l;
    l = Length(head);
    if(pos < 0 ){
        return -1;
    }
    if(pos == 1){
        for(int i=0; i<l-1; i++){
            p = p->next;
        }
        value = head -> data;
        p -> next = head -> next;
        head = head -> next;
        delete p;
        return value;
    }

    for(int i=0; i<pos-1; i++){
        q = p;
        p = p -> next;
    }

    value = p -> data;
    q -> next = p->next;
    delete p;

    return value;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n  =sizeof(arr)/sizeof(arr[0]);


    create(arr, n);
    display(head);
    cout << "Deleted Element : " << Delete(head, 8) << endl; // Here, length of my linked list is 5, but i am trying to delete 8th node, so, it'll try to go to, 8-1)th node, and at last, it'll loop the ll and reach 3rd node.
    display(head);
    cout << "Delete Element : " << Delete(head, 4  ) << endl;
    display(head);
    cout << "Deleted Element : " << Delete(head, 2) << endl;
    display(head);
    cout << "Deletd Element : " << Delete(head, 1) << endl;
    display(head);

    return 0;

}
