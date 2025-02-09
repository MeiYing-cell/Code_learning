#include<iostream>
#include<cstring>
using namespace std;
const int N = 510;
const int INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];
bool st[N];
int n, m;
int prim(){
    int res = 0;
    memset(dist, 0x3f, sizeof dist);
    for(int i = 0; i < n; i ++){
        int t = -1;
        for(int j = 1; j <= n; j ++){
            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
        }

        if(i && dist[t] == INF) return INF;
        if(i) res += dist[t];
        st[t] = true;
        for(int j = 1; j <= n; j ++) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}
int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);//注意图也需要初始化
    while(m --){
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = g[b][a] = min(g[a][b], w);
    }
    int t = prim();
    if(t == INF) cout<<"impossible";
    else cout << t;
    return 0;
}