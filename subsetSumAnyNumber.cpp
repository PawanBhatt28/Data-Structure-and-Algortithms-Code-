#include <iostream>
#include <vector>
using namespace std;

void beautifulSum(int index, int arr[], int n, vector<int> &ds, int sum, int s){
    if(sum == s){
        cout << "Sum : " << sum << endl;
        cout << "Subset : ";
        for(auto it: ds){
            cout << it << " ";
        }
        cout << endl;
        return;
    }else if(index == n || sum > s){
        return;
    }

    sum += arr[index];
    ds.push_back(arr[index]);
    beautifulSum(index, arr, n, ds, sum, s);

    ds.pop_back();
    sum -= arr[index];
    beautifulSum(index+1, arr, n, ds, sum, s);

}

int main(){
    int t, n,s ;
    cout << "Test Cases :" ;
    cin >> t;
    while(t--){
        cout << "Size of Array : " ;
        cin >> n;
        cout << "Sum : ";
        cin >> s;

        int arr[n], sum, index;
        vector<int> ds;

        for(int i=0; i < n; i++){
            cin >> arr[i];
        }
        for(int k=0; k < n; k++){
            beautifulSum(k, arr, n, ds , 0, s);
        }

    }
    return 0;
}
