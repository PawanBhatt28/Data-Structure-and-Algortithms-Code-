#include <iostream>
using namespace std;


void printRevLinear(int n){
    if( n == 0 ){
        return ;
    }
    cout << n << endl;
    printRevLinear(--n);
}

int main(){
    int n; cin >> n;
    printRevLinear(n);

    return 0;
}
