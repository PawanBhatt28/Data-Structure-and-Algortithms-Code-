#include <iostream>
using namespace std;


struct Node{
    int data;
    struct Node *next;
};

struct Node *first;
struct Node *last;


void create(int arr[], int n){
    first = new struct Node;
    first -> data = arr[0];
    first -> next = NULL;
    last = first;

    struct Node *t;
    for(int i=1; i<n; i++){
        t = new struct Node;
        t -> data = arr[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}
/*
void removeDuplicated(struct Node *p){
    struct Node *q;
    while(p->next){
        q = p->next;
        while((p->data) == (q->data)){
            q = q->next;
//            delete q;
        }
        p -> next = q;
        p = p -> next;
    }
}
*/
void removeDuplicates(struct Node *p){
    struct Node *q;
    q = p -> next;
    while(q){
        if( (p->data) == (q->data) ){
            p -> next = q -> next;
            delete q;
            q = p -> next;
        }else{
            p = q;
            q = q -> next;
        }
    }
}


void display(struct Node *p){
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

}
int main()
{

    int arr[] = {1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "n : " << n << endl;
    create(arr, n);
    display(first);
    removeDuplicates(first);
    display(first);
    return 0;
}
