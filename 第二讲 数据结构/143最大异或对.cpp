#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;
int a[N], son[31*N][2], idx;//只有根节点的idx为0
int n;
void insert(int x){
    int p = 0;
    for(int i = 30; i >= 0; i --){
        int u = x >> i & 1;//x的第i位是0或1
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}
int query(int x){
    int p = 0, res = 0;
    for(int i = 30; i >= 0; i --){
        int u = x >> i & 1;//x的第i位是0或1
        if(son[p][!u]){
            res += 1 << i;//
            p = son[p][!u];
        }
        else 
        {
            //res += 0 << i;
            p = son[p][u];
        }
        
    }
    return res;
}
int main(){
    cin >> n;
    int res = 0;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) insert(a[i]);
    for(int i = 0; i < n; i ++) res = max(res, query(a[i]));
    cout << res;
    return 0;
}