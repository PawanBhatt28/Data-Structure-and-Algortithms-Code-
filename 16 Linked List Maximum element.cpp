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

int maxEle(struct Node *p){
    int maxx = INT_MIN;
    while(p){
        if( (p -> data) > maxx ) maxx = (p -> data);
        p = p -> next;
    }
    return maxx;
}

int maxEleRecursive(struct Node *p, int maxx){
    int x;
    if(p){
        if( (p->data) > maxx ){
            maxx = (p->data);
        }
        x = maxEleRecursive(p->next, maxx);
    }else{
        return maxx;
    }
}


int maxEleRecursive2(struct Node *p){
    int x;
    if( p == 0 ) return INT_MIN;
    else{
        x = maxEleRecursive2(p->next);
        if( x > (p -> data) ) {
            return x;
        }else{
            return p -> data;
        }
    }

}


int maxEleRecursive3(struct Node *p){
    int x;
    if( p == 0 ) return INT_MIN;
    x = maxEleRecursive3(p->next);
    return x > (p->data) ? x : (p->data);

}

int main(){
    int arr[] = {1,2,1,4,0,69,26};

    create(arr, 7);

    cout << "Max element : " << maxEle(first) << endl;                  // ITERATION
    cout << "Max element : " <<maxEleRecursive(first, INT_MIN) << endl; // RECURSION on CALLING TIME
    cout << "Max element : " <<maxEleRecursive2(first) << endl;                 // RECURSION on RETURNING TIME
    cout << "Max element : " <<maxEleRecursive3(first);
    return 0;
}
