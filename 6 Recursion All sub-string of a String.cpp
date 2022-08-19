#include <iostream>
#include <string>
using namespace std;
int c;

int subString(string s, string sub, int n, int i){

    if( i == n ){
        cout << sub << endl;
        return 1;
    }
    cout << "c : " << c << endl;
    sub.push_back(s[i]);
    c = subString(s, sub, n, i+1);

    sub.pop_back();
    c = subString(s, sub, n, i+1);

}



int main()
{
    int t;
    cout << "t : ";
    cin >>  t;
    while(t--){
        c = 0;
        string s;
        cout << "string : ";
        cin >> s;
        int n  = s.size();
        subString(s, "", n, 0);
        cout << "C : " << c << endl;
    }
    return 0;
}
