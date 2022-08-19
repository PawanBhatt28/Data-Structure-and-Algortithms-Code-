#include <iostream>
#include <vector>
using namespace std;

void subSeq(int index, vector<int> &ds, int arr[], int n){

    if(index == n){
        for(auto it: ds){
            cout << it << " ";
        }
        cout << endl;
        return ;
    }

    ds.push_back(arr[index]);
    subSeq(index+1, ds, arr, n);

    ds.pop_back();
    subSeq(index+1, ds, arr, n);
}



int main(){
    int t, n;
    vector<int> ds ;

    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        for(int i=0; i < n; i++){
            cin >> arr[i];
        }
        subSeq(0, ds, arr, n);
    }
    return 0;
}
