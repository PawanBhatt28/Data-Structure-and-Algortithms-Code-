#include <iostream>
using namespace std;



int power(int m, int n){
    if( n > 1) return m * power(m, n-1);
    return m;

}

int efficientPower(int m, int n){
    if( n == 1){
        return m;
    }else if ( n % 2 == 0 ){
        return efficientPower(m*m, n/2);
    }else{
        return m * efficientPower(m, n-1);
    }

}

int main(){
    int n,m;
    cin >> m >> n;

    int ans = power(m, n);
    int effAns = efficientPower(m, n);
    cout << "Power of " << m << " to " << n << " : " << ans << endl;
    cout << "Efficient Power of " << m << " to " << n << " : " << effAns ;

}
