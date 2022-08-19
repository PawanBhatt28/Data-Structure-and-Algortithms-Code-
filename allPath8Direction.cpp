#include <iostream>
using namespace std;


void ratinaMaze(int i, int j, int x, int y, int arr[2][2], string path){


    if(x > i || y > j || x < 0 || y < 0 || arr[x][y] == 1){
        return;
    }else if(x == i && y == j){
        cout << path << endl;
        return;
    }


    arr[x][y] = 1;

    path += "R";
    ratinaMaze(i, j, x , y + 1, arr, path);

    path.pop_back();
    path += "D" ;
    ratinaMaze(i, j, x + 1, y, arr, path);

    path.pop_back();
    path += "L";
    ratinaMaze(i, j, x, y - 1, arr, path);

    path.pop_back();
    path += "U";
    ratinaMaze(i, j, x - 1, y, arr, path);

    path.pop_back();
    path += "1";
    ratinaMaze(i, j, x - 1, y - 1, arr, path);

    path.pop_back();
    path += "4";
    ratinaMaze(i, j, x - 1, y + 1, arr, path);

    path.pop_back();
    path += "3";
    ratinaMaze(i, j, x + 1, y + 1, arr, path);

    path.pop_back();
    path += "2";
    ratinaMaze(i, j, x + 1, y - 1, arr, path);

    arr[x][y] = 0;

}

int main(){
    int t;
    cin >> t;
    int i,j;
    while(t--){
        cin >> i >> j;
        int arr[2][2];
        string path = "" ;
        ratinaMaze(i, j, 0, 0, arr, path);
    }

    return 0;
}
