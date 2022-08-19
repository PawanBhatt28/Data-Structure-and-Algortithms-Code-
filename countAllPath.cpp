#include <iostream>
#include <vector>
using namespace std;

int allPath(int i, int j, int x, int y, int a, int b){
    if(x > i || y > j){
        return 0;
    }else if(x == i && y == j){
        return 1;
    }
    x += 1;
    a = allPath(i, j, x, y, a,b);

    x -= 1;
    y += 1;
    b = allPath(i, j, x, y, a,b);

    return a + b;
}

int main(){
    int t,i,j;
    cin >> t;
    while(t--){
        int a = 0, b = 0;
        cin >> i >> j;
        cout << allPath(i-1,j-1,0,0,a,b) << endl;
    }

    return 0;
}



