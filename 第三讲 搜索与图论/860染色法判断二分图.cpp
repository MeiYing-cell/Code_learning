#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
const int M = 2 * N;
int n,m;
int h[N], e[M], ne[M], idx;
int color[N];//记录点的染色情况
void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
bool dfs(int x, int f){
    color[x] = f;
    for(int i = h[x]; i != -1; i = ne[i]){
         //遍历和 u 相邻的点
        int j = e[i];
        if(!color[j]){//相邻的点没有颜色,则递归处理这个相邻点
            if(!dfs(j, 3 - f)) return false;
        }
        else if(color[j] == f) return false;
    }
    return true;
}
int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m --){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    bool flag = true;
    for(int i = 1; i <= n; i ++){//遍历点
        if(!color[i]){
            if(!dfs(i, 1)){//染色该点，并递归处理和它相邻的点
                flag = false;
                break;
            }
        } 
    }
    if(flag == true) puts("Yes");
    else puts("No");
}