#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];//一个队列，一个记录入度
int hh = 0, tt = -1;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int topsort(){
    //第一遍遍历找入度为0的点
    for(int i = 1; i <= n; i ++){
        if(d[i] == 0) q[++ tt] = i;
    }
    while(hh <= tt){
        int t = q[hh ++];
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            d[j] --;
            if(d[j] == 0) q[++ tt] = j;
        }
    }
    return tt == n - 1;
}
int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b] += 1;
    }
    if(topsort()){
        for(int i = 0; i < n; i ++){
            cout << q[i] <<" ";
        }
    }
    else{
        cout << -1 <<endl;
    }
}