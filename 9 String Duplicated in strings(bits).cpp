#include <iostream>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--){
        char word[10];
        cin >> word;
        int h=0, a, p;
        for(int i=0; word[i]!='\0'; i++){
            // Masking
            a = 1;
            p = word[i] - 97 ;
            a = (a << p);
            if( (h & a) > 0 ) cout << "Duplicate : " << word[i] << endl;
            h = a | h;

        }
    }
    return 0;
}
