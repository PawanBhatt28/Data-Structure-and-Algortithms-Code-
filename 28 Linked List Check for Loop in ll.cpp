#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
struct Node *first;


void display(struct Node *p){
    while(p){
        cout << p->data << " " << p << endl;
        p = p->next;
    }cout << endl;
}




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
    //last->next = first->next->next;
}

int checkLoop(struct Node *p){
    while(p){
        if(p -> data == -1){
            return 1;
        }
        p -> data = -1;
        p = p -> next;
    }
    return 0;
}

int checkLoop2(struct Node *p){
    cout << "Checking for Loop : " << endl;
    struct Node *a, *b;
    a = b = p;
    while( a && b ){
        cout << "a : " << a->data << " " << b->data << endl;
        a = a->next != NULL ? a->next->next : NULL;
        b = b->next;
        if(a == b) return 1;
    }

    return 0;
}


int main()
{
    int arr[] = {1,2,3,4,5};
    create(arr, 5);
  //  display(first);
    cout << checkLoop2(first);
   // display(first);

    return 0;
}
