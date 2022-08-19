#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *head;

void Create(int arr[], int n)
{
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

void Display(struct Node *p)
{
    if(p -> next  == head){
        cout << p->data << endl;
        return;
    }

    cout << p->data << " ";
    Display(p -> next);
}

int Length(struct Node *p){
    int l = 0;
    while(p->next != head){
        l++;
        p = p -> next;
    }
    return l;
}


void Insert(struct Node *p, int key, int pos){
    if(pos < 0 ){
        return ;
    }else{
        struct Node *t, *q;
        t = new struct Node;
        t -> data = key;

        if(pos == 0) pos = Length(head)+1;
        for(int i=0; i < pos-1; i++){
            p = p->next;
        }
        /*
        while(pos--){
            cout << p->data << " ";
            p = p->next;
        }*/
        t -> next = p -> next;
        p -> next = t;
    }
}

int main(){
    int arr[] =  {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    Create(arr, n);
    Display(head);
    Insert(head, 69, 0);
    Display(head);
    Insert(head, 70, 3);
    Display(head);
    Insert(head, 71, 3);
    Display(head);
    Insert(head, 72, 8);
    Display(head);
    return 0;
}
