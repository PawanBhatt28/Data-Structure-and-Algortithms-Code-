#include <iostream>
#include <vector>
using namespace std;

void subSeq(int index, vector<int> &d, int arr[], int n, int k){

    int sum;

    if(index == n){
        sum = 0 ;
        // printing the sub sequence

        // summing the sub-sequence
        for(int i=0; i < d.size(); i++){
            sum += d[i] ;
        }
        //cout << "Sum of sub sequence : " << sum << endl;
       if(sum == k){
            for(auto it: d){
                cout << it << " ";
            }
            cout << endl;
       }

        return;
    }

    d.push_back(arr[index]);
    sum += arr[index];
    subSeq(index+1, d, arr, n, k);
    d.pop_back();

    subSeq(index+1, d, arr, n, k);
}


int main(){
    int t, n, k;
    cin >> t;

    while(t--){
        cin >> n >> k;
        int arr[n];
        vector<int> d;

        for(int i=0; i < n; i++){
            cin >> arr[i] ;
        }
        subSeq(0, d , arr, n, k) ;
    }
    return 0;
}
