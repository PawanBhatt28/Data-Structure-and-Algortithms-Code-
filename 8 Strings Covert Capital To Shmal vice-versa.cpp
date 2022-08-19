#include <iostream>
using namespace std;



int main(){
    cout << "1 - Lower to Upper , 2 - Upper to Lower " << endl;
    int n;
    char name[5];
    cin >> name;

    cin >> n;
    if( n == 1){
        for(int i=0; i<5; i++){
            name[i] = name[i] - 32;
        }
    }else{
        for(int i=0; i<5; i++){
            name[i] = name[i] + 32;
        }
    }


    cout << name;

    return 0;
}
