//bellman-ford算法
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;
int n, m ,k;
int dist[N], backup[N];
struct edge
{
    int a, b, w;
}edges[N];
int bellman_ford(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < k; i ++){
        memcpy(backup, dist, sizeof dist);
        for(int j = 0; j < m; j ++){
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    return dist[n];
}
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i ++){
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }
    int t = bellman_ford();
    if(t > 0x3f3f3f3f / 2)  cout <<"impossible";
    else cout << t;

    return 0;
}