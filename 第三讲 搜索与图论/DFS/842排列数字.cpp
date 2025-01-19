#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

const int N = 10;
int n;
int path[N], state[N];
void dfs(int u){
    if(u>n){
        for(int i=1;i<=n;i++){
            printf("%d ",path[i]);
        }
        puts("");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!state[i]){
            path[u] = i;
            state[i] = 1;
            dfs(u+1);
            state[i] = 0;
        }
    }
}
int main(){
    cin>>n;
    dfs(1);
}