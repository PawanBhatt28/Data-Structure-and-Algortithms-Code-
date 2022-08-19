#include <iostream>
#include <numeric>
#include <vector>
using namespace std;


int tripletSum(int arr[], int n){
    int i,j,k;
    i = 0;
    while(i < n-2){
        j = i+1;
        while(j < n-1){
            k = j+1;
            while(k < n){
                int sum=0;
                sum = arr[i] + arr[j] + arr[k];
                if(sum == 0){
                    return 1;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    return 0;
}



int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        for(int i=0; i < n; i++){
            cin >> arr[i];
        }

        cout << tripletSum(arr, n) << endl;

    }

    return 0;
}
