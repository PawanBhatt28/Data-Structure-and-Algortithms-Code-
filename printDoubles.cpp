#include <bits/stdc++.h>
using namespace std;


int main(){
    int num;
    cin >> num;
    int arr[num];
    int hash_array[num] ;
    vector<int> result;

    for(int i=0; i < num; i++){
        cin >> arr[i];
        hash_array[i] = 0;
    }

    for(int i=0; i < num; i++){
        hash_array[arr[i]] += 1;
    }

    for(int i=0; i < num; i++){
        if(hash_array[i] >= 2){
            result.push_back(i);
        }
    }

    if(result.size() == 0){
        cout << -1;
    }else{
        int arr = {1,2,3,4};
        for(auto it: result){
            cout << it << " ";
        }
    }
}
