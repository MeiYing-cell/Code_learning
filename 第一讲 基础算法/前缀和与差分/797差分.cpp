#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int n,m;
int a[N], b[N];
void insert(int l, int r, int c){
    b[l] += c;
    b[r + 1] -= c;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    //初始化差分数组
    for(int i = 1; i <= n; i ++) insert(i, i, a[i]);
    while(m --){
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    //根据差分数组输出变化后的数组
    for(int i = 1; i <= n; i ++) b[i] += b[i-1];
    for(int i = 1; i <= n; i ++) printf("%d ",b[i]); 
    return 0;
}