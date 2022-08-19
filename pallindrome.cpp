#include <iostream>
using namespace std;

bool checkPalli(string word, int first, int last){

    cout << first << " " << word[first] << " : " << last << " " << word[last] << endl;

    bool ans = true;
    if(( word[first] != word[last]) ){
        ans = false;
        return ans;
    }

    if( last-first <= 1 ){
        return ans;
    }

    first++;
    last--;
    return checkPalli(word, first, last);
}


int main() {
	int t;
	string word;

	cin >> t;
	while(t--){
	    cin >> word;
	    int f=0, l=word.size() -1;

	    cout << checkPalli(word, f, l) << endl;
	}
    return 0;
}
