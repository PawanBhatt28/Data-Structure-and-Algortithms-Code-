  #include <iostream>
using namespace std;


struct Node{
    int data;
    struct Node *next;
};

struct Node *first;
struct Node *last;


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

void deleteNode(struct Node *p, int pos){
    int x;

    if(pos < 0 || pos > 5) return;

    else if( pos == 1){
        first = first->next;
        x = p -> data; /// if we need we can store the data before deleting.
        delete p;
    }
    else{
        int i = 1;
        while( i <= pos-2){
            cout << "i : " << i << " p :" << p <<  endl;
            p = p->next;
            i++;
        }
        cout << "Node deleted." << endl;
      //  p -> next = (p -> next) -> next != NULL ? (p->next)->next : NULL ;
        p -> next = (p->next)->next ;
       // x = (p->next) -> data;  if we want to delete last node, then code will get stuck here, because last node is deleted not p is the last node, then it;ll try to get data from next node which doesnt exist.

       // delete p->next;   3
       cout << "assinged new connection." << endl;
    }
}

void display(struct Node *p){
    cout << "Printing LL : ";
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    int n = 5;
    int arr[n] = {1,2,3,4,5};
    create(arr, n);
    display(first);
    deleteNode(first, 1);
    display(first);
}
