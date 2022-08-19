#include <iostream>
#include <vector>
using namespace std;

void printMatrix(int arr[4][4], int m, int n){
    for(int i=0;i<m; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixPath(char arr[4][4], int m, int n, int i, int j, string path){

    if( i >= m || j >= n ){
        return;
    }
    else if( i == (m-1) && j == (n-1) ){
        cout << "Path : " << path << endl;
        return;
    }

    path += "R";
    matrixPath(arr, m, n, i, j+1, path);
    path.pop_back();

    path += "D";
    matrixPath(arr, m, n, i+1, j, path);

}


void matrixPath4D(int arr[4][4], int m, int n, int i, int j, string path){
    if( i >= m || j >= n || i < 0 || j < 0 || arr[i][j] == 1){
        return;
    }
    else if( i == (m-1) && j == (n-1) ){
        ///printMatrix(arr, m, n);
        cout << "Path : " << path << endl;
        return;
    }

    arr[i][j] = 1;

    path += "R";
    matrixPath4D(arr, m, n, i, j+1, path);
    path.pop_back();


    path += "D";
    matrixPath4D(arr, m, n, i+1, j, path);
    path.pop_back();


    path += "L";
    matrixPath4D(arr, m, n, i, j-1, path);
    path.pop_back();


    path += "U";
    matrixPath4D(arr, m, n, i-1, j, path);
 //   path.pop_back();

    arr[i][j] = 0;
}

void matrixPath8D(int arr[4][4], int m, int n, int i, int j, string path){
    if( i >= m || j >= n || i < 0 || j < 0 || arr[i][j] == 1){
        return;
    }
    else if( i == (m-1) && j == (n-1) ){
        //printMatrix(arr, m, n);
        cout << "Path : " << path << endl;
        return;
    }

    arr[i][j] = 1;

    path += "R";
    matrixPath8D(arr, m, n, i, j+1, path);
    path.pop_back();

    path += "D";
    matrixPath8D(arr, m, n, i+1, j, path);
    path.pop_back();

    path += "L";
    matrixPath8D(arr, m, n, i, j-1, path);
    path.pop_back();

    path += "U";
    matrixPath8D(arr, m, n, i-1, j, path);
    path.pop_back();

    path += "1";
    matrixPath8D(arr, m, n, i-1, j-1, path);
    path.pop_back();

    path += "2";
    matrixPath8D(arr, m, n, i-1, j+1, path);
    path.pop_back();

    path += "3";
    matrixPath8D(arr, m, n, i+1, j-1, path);
    path.pop_back();

    path += "4";
    matrixPath8D(arr, m, n, i+1, j+1, path);

    //path.pop_back() why did not include this ?

    arr[i][j] = 0;
}

int main()
{
    int m,n;
    cout << "m, n : ";
    cin >> m >> n;

    int arr[4][4] ;


    cout << "Matrix : " << endl;
    for(int i=0; i < m ; i++){
        for(int j=0; j < n ; j++){
            arr[i][j] = 0;
        }
    }

    printMatrix(arr, m, n);

    //matrixPath(arr, m, n, 0, 0, "");
    //matrixPath4D(arr, m, n, 0, 0, "");
    matrixPath8D(arr, m, n, 0, 0, "");
    return 0;
}
