#include <iostream>
using namespace std;

void generateArray(int *arr, int n){
    for(int i=0;i<=n, i++){
        cin >> arr[i+1];
    }
}

int squareRoot(int n){
    int ans;
    int start=0, endd = n/2;
    int diff = n;
    int mid;
    int *arr = new int[n/2+1];
    generateArray(arr);

    while( (start-endd) >= 0 ){
        mid = start + (endd-start)/2;
        if( (arr[mid]*arr[mid]) == n ) return arr[mid];
        else if( (n - arr[mid]*arr[mid]) < diff ) ans = arr[mid];
        diff = n - arr[mid]*arr[mid];

    }

}


int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        squareRoot(n);
    }
    return 0;
}
