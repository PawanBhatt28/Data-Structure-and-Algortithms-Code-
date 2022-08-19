#include <iostream>
using namespace std;

int c = 0;
void print(){
    cout << c << " ";
    c++;
    print();
}


int main(){
    print();
    return 0;
}
