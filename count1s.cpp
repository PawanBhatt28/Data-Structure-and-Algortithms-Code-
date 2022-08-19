#include <iostream>
using namespace std;

int count11(int n){
    int count = 0;
    while(n > 0){
        if(n%10 == 1){
            ++count;
        }
        n /= 10;
    }
    return count;

}

int count1(int num){
    int sum = 0;
    for(int i=1; i <= num; i++){
        sum += count11(i) ;
    }
    return sum;
}


int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << count1(n) << endl;
    }


    return 0 ;
}
