#include <iostream>
using namespace std;


void printLinearBacktracking(int n){
    if( n == 0 ){
        return;
    }
    printLinearBacktracking(--n);
    cout << n + 1 << " ";
}

int main(){
    int n;
    cin >> n;

    printLinearBacktracking(n);
    return 0;
}
