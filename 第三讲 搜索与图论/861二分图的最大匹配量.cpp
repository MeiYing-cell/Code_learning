#include<cstring>
#include<iostream>
using namespace std;
const int N = 510, M = 1e5 + 10;
int h[N], e[M], ne[M], idx;
bool st[N];
int match[N];
int n1, n2, m;
void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
bool find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;//那x浏览过这个女孩了
            //如果女孩j没有男朋友，或者她原来的男朋友能够预定其它喜欢的女孩。配对成功
            if(!match[j] || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    memset(h, -1, sizeof h);
    cin >> n1 >> n2 >> m;
    while(m --){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int res = 0;
    for(int i = 1; i <= n1; i ++){
        memset(st, false, sizeof st);
        if(find(i)) res ++;
    }
    cout << res;
    return 0;
}