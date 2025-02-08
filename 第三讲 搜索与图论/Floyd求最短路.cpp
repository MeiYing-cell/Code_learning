#include<iostream>
#include<cstring>
using namespace std;
const int N  = 210;
const int INF = 1e9;
int n, m, k;

int dist[N][N];
void floyd(){
    for(int k = 1; k <= n; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
int main(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i ++){
        int a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
    }
    floyd();
    while(k --){
        int x, y;
        cin >> x >> y;
        int t = dist[x][y];
        if(t > INF / 2) cout << "impossible" <<endl;
        else cout << t << endl;
    }
    return 0;
}