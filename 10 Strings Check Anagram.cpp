#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int checkAnagram(string s, string t){
    if( s.size() != t.size() ) return 0;

    int has[26] = {0};
    for(int i=0; i<s.size(); i++){
        has[ s[i] - 97 ]++;
        has[ t[i] - 97 ]--;
        printArray(has, 26);
    }

    printArray(has, 26);
    cout << "Above Final Output";

    for(int i=0; i<26; i++){
        if(has[i] != 0) return 0; // != 0 is important, >0  will not work with every test case. what is array contain 23, 4  anything greater than 0;
    }
    return 1;
}



int main(){
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cout << "String1 and String2 : ";
        cin >> a >> b;

        checkAnagram(a, b);


    }
    return 0;
}
