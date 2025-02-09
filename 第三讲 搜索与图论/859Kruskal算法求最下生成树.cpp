#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e5 + 10;
struct edge{
    int a, b, w;
    bool operator < (const edge& e){
        return this -> w < e.w;
    }
}edges[N];
int n, m;
int p[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    int res = 0, cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    for(int i = 1; i <= n; i ++) p[i] = i;
    sort(edges, edges + m);
    for(int i = 0; i < m; i ++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        int pa = find(a), pb = find(b);
        if(pa != pb){
            res += w;
            cnt ++;//记录边数
            p[pa] = pb;
        }
    }
    if(cnt < n - 1) cout <<"impossible";
    else cout << res;
    return 0;
}