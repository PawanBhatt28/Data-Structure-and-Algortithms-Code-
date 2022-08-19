#include <iostream>
#include <string>
using namespace std;

void greatestPath(int arr[5][5], int n, int m, int x, int y, int a, int b, int i, int j, int c, string path, int maxxi, string maxxiPath){
     if( (i == a) && (j == b)){
        cout << "Path : "  << path << ", Length : " << c << endl;
        if( c > maxxi){
            maxxi = c;
            maxxiPath = path;
        }
        arr[i][j] = 0;
        return;
    }
    if( (i == n) || (j == m) || (i < 0) || (j < 0) || arr[i][j] == 1 ){
        return;
    }

    arr[i][j] = 1;

    path += "R";
    greatestPath(arr, n, m, x, y, a, b, i, j+1, c+1, path, maxxi, maxxiPath);

    path.pop_back();

    path += "D";
    greatestPath(arr, n, m, x, y, a, b, i+1, j, c+1, path, maxxi, maxxiPath);
    path.pop_back();

    path += "L";
    greatestPath(arr, n, m, x, y, a, b, i, j-1, c+1, path, maxxi, maxxiPath);
    path.pop_back();

    path += "U";
    greatestPath(arr, n, m, x, y, a, b, i-1, j, c+1, path, maxxi, maxxiPath);

    arr[i][j] = 0;

    cout << "Maxlenngth : " << maxxi << " Path : " << maxxiPath << endl;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cout << "n, m : ";
        cin >> n >> m;

        int arr[5][5] ;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                arr[i][j] = 0;
            }
        }

        int x, y, a, b;
        cout << "Point 1 : " ;
        cin >> x >> y;

        cout << "Point 2 : ";
        cin >> a >> b;
        int i = x, j = y;
        int c = 0;
        greatestPath(arr, n, m, x, y, a, b, i, j, c, "", 0, "");
    }

    return 0;
}
