#include <iostream>
using namespace std;


int binarySearch(int arr[], int ele, int first, int last){
    int middle = (first + last )/ 2 ;

    if(arr[middle]  == ele){
        cout << "Found the element at " << middle << endl;
        return middle;


    }else if(ele > arr[middle]){
        first = middle + 1;
    }else if(ele < arr[middle]){
        last = middle;
    }

    return binarySearch(arr, ele, first, last);
}


int main(){
    int t,n;

    cin >> t;
    while(t--){
        cin >> n;
        int arr[n], ele, f, l;

        for(int i=0; i < n; i++){
            cin >> arr[i];
        }
        f = 0;
        l = sizeof(arr)/sizeof(int) - 1;
        cout << "Element to search : ";
        cin >> ele;

        binarySearch(arr, ele, f, l);
    }


    return 0;
}
