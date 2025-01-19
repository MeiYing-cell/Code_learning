#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
const int N = 10;

int n;
char path[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u){
    //u==n 表示已经搜了n行
    if(u==n){
        for(int i=0;i<n;i++){
            puts(path[i]);
        }
        puts("");
        return;
    }
    int x=u;
    for(int y=0;y<n;y++){
        if(!col[y] && !dg[y-x+n] && !udg[y+x]){
            col[y] = dg[y-x+n] = udg[y+x] = true;
            path[x][y] = 'Q';
            dfs(u+1);
            //回溯
            path[x][y] = '.';
            col[y] = dg[y-x+n] = udg[y+x] = false;
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            path[i][j] = '.';
        }
    }
    dfs(0);
}
