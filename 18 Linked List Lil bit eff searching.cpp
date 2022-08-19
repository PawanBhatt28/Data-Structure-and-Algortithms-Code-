#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};
struct Node *first;

void create(int arr[], int n)
{
    struct Node *last, *t;

    first = new struct Node;
    first -> data = arr[0];
    first -> next = NULL;
    last = first;

    for(int i=1; i<n; i++)
    {
        t = new struct Node;
        t -> data = arr[i];
        t -> next = NULL;
        last -> next = t;

        last = t;
    }
}


struct Node* searchAndMove(struct Node *p, int k)
{
    struct Node *temp ;
    struct Node *q = p;
    while(p){
        if( p->data == k ){
       //     cout << " q : " << q << " p : " << p << endl;
            q -> next = p -> next;
            p -> next = first;
            first = p;
            return p;
        }
        q = p;
        p = p -> next;
    }
    return 0;
};



void display(struct Node *p){
    while(p!=0){
        cout << p-> data << " ";
        p = p -> next;
    }
    cout << endl;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};

    create(arr, 8);
    display(first);
    cout << 2 << " found at : " << searchAndMove(first, 2) << endl;
    display(first);
    return 0;
}
