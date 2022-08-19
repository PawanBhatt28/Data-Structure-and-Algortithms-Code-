#include <iostream>
#include <vector>
using namespace std;

void allPath(int i, int j, int x, int y, vector<string> path){
    if(x > i || y > j){
        return;
    }else if(x == i && y == j){
        for(auto it: path){
            cout << it << " ";
        }
        cout << endl;
        return ;

    }
    x += 1;
    path.push_back("D");
    allPath(i, j, x, y, path);

    x -= 1;
    path.pop_back();
    path.push_back("R");
    y += 1;
    allPath(i, j, x, y, path);
}

int main(){
    int t,i,j;
    cin >> t;
    while(t--){
        cin >> i >> j;
        vector<string> path;
        allPath(i,j,0,0,path);
    }

    return 0;
}


