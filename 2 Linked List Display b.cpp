#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *first;

void createLL(int arr[], int n){

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

void display(struct Node *head){
    while( head != NULL ){
        cout << "| " << head -> data << " " << head -> next << " | " << " -> ";
        head = head->next;
    }
    cout << "| " << head -> data << " " << head -> next ;
    cout << endl;

}

void displayRecursively(struct Node *p){
    if( p == NULL) return;
    cout << p->data << " " << p << " -> ";
    displayRecursively(p->next);
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];
 //   cout << "First : " << first << endl;
    createLL(arr, n);
    //display(first);
 //   cout << "First : " << first << endl;
 displayRecursively(first);
    return 0;
}
