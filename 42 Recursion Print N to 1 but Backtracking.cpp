#include <iostream>
using namespace std;


void printRevBacktracking(int n, int i){
    if( n == 0){
        return;
    }
    printRevBacktracking(--n, i);
    cout << i - n << " ";
}

int main(){
    int n;
    cin >> n;

    printRevBacktracking(n, n);
    return 0;
}
