#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;
const int N = 110;
typedef pair<int,int> PII;
int n,m;
int g[N][N], d[N][N];//存 地图，每一个点到起点的距离
PII pre[N][N];//存前驱节点

int bfs(){
    queue<PII> q;
    q.push({0,0});
    memset(d,-1,sizeof d);
    d[0][0] = 0;
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
    while(q.size()){
        auto t = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=t.first+dx[i], y=t.second+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && g[x][y]==0 && d[x][y]==-1){
                d[x][y] = d[t.first][t.second] + 1;
                pre[x][y] = t;//记录前驱节点
                q.push({x,y});
            }
        }
    }
    return d[n-1][m-1];
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> g[i][j];
        }
    }
    cout<<bfs()<<endl;
    return 0;
}