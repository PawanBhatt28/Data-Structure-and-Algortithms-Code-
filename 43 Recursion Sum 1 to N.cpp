#include <iostream>
using namespace std;


int sumToN(int i, int n){
    if( i > n ){
        return 0;
    }
    return i + sumToN(i+1, n);
}




int main(){
    int n;
    cin >> n;

    cout << sumToN(1, n);
    return 0;
}
