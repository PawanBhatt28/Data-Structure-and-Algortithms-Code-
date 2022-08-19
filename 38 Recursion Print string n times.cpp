#include <iostream>
using namespace std;


void printNtimes(int n, string s){
    if( n == 0 ){
        return;
    }
    cout << s << " " << n << endl;
    printNtimes(--n, s);          // if we do n--, it becomes post increment and it never increments, i guess. Yes, it does not increment.
}


int main(){
    string s;
    cin >> s;
    cout << "String : " << s << endl;
    int n;
    cin >> n;
    cout << "N : " << n << endl;

    printNtimes(n, s);
    return 0;
}

