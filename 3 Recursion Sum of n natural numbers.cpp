#include <iostream>
using namespace std;

int sum(int n){
    if(n > 1) return n + sum(n-1);
    else return 1;
}


int main(){
    int n;
    cin >> n;
    int ans;
    ans = sum(n);
    cout << "Sum of first ss" << n << " natural numbers : " << ans;

}
