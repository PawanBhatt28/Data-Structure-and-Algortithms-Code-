#include <iostream>
using namespace std;

int revArrayRecursion(int arr[],int first, int last);

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n],f = 0,l=n-1;

        for(int i=0; i < n; i++){
            cin >> arr[i];
        }
        revArrayRecursion(arr,f,l);
        for(int i=0; i<n; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}

int revArrayRecursion(int arr[], int first, int last){
    int temp;
    if(last-first <= 0){
        return 1;
    }

  //  arr[first] = arr[first] ^ arr[last];
  //  arr[last] = arr[last] ^ arr[first] ;
  //  arr[first] = arr[first] ^ arr[first];
    temp = arr[first];
    arr[first] = arr[last];
    arr[last] = temp;
    ++first;
    --last;

    return revArrayRecursion(arr, first, last);
}
