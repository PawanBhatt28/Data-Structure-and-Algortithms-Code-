#include <iostream>
using namespace std;


int countDigitOne(int num) {

        int ccount = 0;
        int sum = 0;
        int rem;
        for(int n=1; n <= num; n++){
            ccount = 0;
            rem = n ;
            while(rem > 0){
                if( rem % 10 == 1){
                    ++ccount;
                }
                rem = rem / 10;
            }
            sum += ccount ;
        }
        return sum;
}


int main(){
    int nn;
    cin >> nn;
    cout << countDigitOne(nn);


    return 0;
}
