#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class LinkedList{

    private:
        Node *first;
    public:
        LinkedList(){ first = NULL; }
        LinkedList(int arr[], int n);
        ~LinkedList();

        void Display();
        void Insert(int index, int k);
        int Delete(int index);
        int Length();

};

LinkedList :: LinkedList(int arr[], int n){
    Node *last, *t;

    first = new Node;
    first -> data = arr[0];
    first -> next = NULL;
    last = first;

    for(int i=1; i<n; i++){
        t = new Node;
        t -> data = arr[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

LinkedList :: ~LinkedList(){
    // Deconstructor deleting complete list.
    Node *p = first;
    while(first){
        first = first -> next;
        delete p;
        p = first;
    }
}

int LinkedList :: Length(){
    int l = 0;
    Node *p = first;
    while(p){
        l++;
        p = p->next;
    }
    return l;
}

void LinkedList :: Display(){
    Node *p = first;
    while(p){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

void LinkedList :: Insert(int k, int index){


    int l = Length();
    cout << "Length : " << l << endl;
    if(index <= 0 || index > (l+1) ) return ;

    Node *t = new Node;
    t -> data = k;
    t -> next = NULL;

    if(index == 1){
        t -> next = first;
        first = t;
    }
    else{
        Node *p = first;
        index -= 2;

        while(index--){
            p = p -> next;
        }

        t -> next = p -> next;
        p -> next = t;
    }
}


int LinkedList :: Delete(int index){

    if(index == 0){
        first = first -> next;
        return index;
    }

    Node *p = first;
    index -= 2;
    while(index--){
        p = p->next;
    }

    p -> next = (p->next) -> next;
    return index;
}


int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    LinkedList L1(arr, n);
    L1.Display();
//    L1.Delete(2);
 //   L1.Display();
    L1.Insert(666, 6);
    L1.Display();
    L1.Insert(69, 1);
    L1.Display();
    L1.Insert(89, 2);
    L1.Display();
    L1.Insert(70, 3);
    L1.Display();
    L1.Insert(70, 6);
    L1.Display();

    return 0;
}
