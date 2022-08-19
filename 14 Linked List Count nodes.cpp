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

void display(struct Node *p){
    while( p != NULL){
        cout << p -> data;
        p = p -> next;
    }
}

int countNode(struct Node *p){
    int c = 0;
    while(p!=0){
        c++;
        p = p -> next;
    }
    return c;
}

int countNodeRecursive(struct Node *p){
    if( p == 0 ) return 0;
    return 1 + countNodeRecursive(p -> next);
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    create(arr, n);
    display(first);
    cout << endl;
    cout << "Number of nodes : " << countNode(first) << endl; // loop
    cout << "Number of nodes : " << countNodeRecursive(first); //recursive

}
