#include <iostream>
using namespace std;


struct Node{
    int data;
    struct Node *next;
};

struct Node *first = new struct Node;
struct Node *second = new struct Node;


void create(struct Node *p, int arr[], int n){
    struct Node *last, *t;

    p -> data = arr[0];
    p -> next = NULL;
    last = p;

    for(int i=1; i<n; i++){
        t = new struct Node;
        t -> data = arr[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void mergeLL(struct Node *p, struct Node *s){

    struct Node *a, *b;

    struct Node *z = NULL;
    if( (p->data) <= (s->data) ){
        z = p;
        p = p -> next;
    }else{
        z = s;
        s = s -> next;
    }

    a = p -> next ;
    b = s -> next ;

    while( p != NULL && s != NULL ){
        cout << z->data << " " << endl;
        cout << p << " " << "P : " << p->data << " s : " << s->data << endl;

        if( (p->data) < (s->data) ){
            z -> next = p;
            p = p -> next;
            //p = a ;
           // a = a ->next;
        }else{
            z -> next = s;
            s = s -> next;
        //    s = s -> next;
           // s = b ;
           // b = b -> next;
        }
        z = z->next;
    }
    cout << "Reached Null of one of the ll." << endl;

    while(p){
        z -> next = p;
        p = p -> next;
    }
    while(s){
        z -> next = s;
        s = s -> next;
    }

}


void display(struct Node *p){
    while(p){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

int main(){
    int arr1[] = {1,5,8,12,13};
    int arr2[] = {3,6,7,14};

    create(first, arr1, 5);
    display(first);
    create(second, arr2, 4);
    display(second);
    mergeLL(first, second);
    display(first);
    cout << "Mergin Done." << endl;
   // display(second);


    return 0;
}
