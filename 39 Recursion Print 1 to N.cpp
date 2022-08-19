#include <iostream>
using namespace std;



void printLinear(int n, int i){
    if( i == n + 1){
        return;
    }
    cout << i << endl;
    printLinear(n, ++i);
}

int main(){
    int n;
    cin >> n;

    printLinear(n, 1);

    return 0;
}
