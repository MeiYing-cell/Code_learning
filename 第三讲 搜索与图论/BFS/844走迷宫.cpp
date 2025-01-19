#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;
const int N = 110;
typedef pair<int,int> PII;
int n,m;
int g[N][N], d[N][N];
PII pre[N][N];

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
void print_path(){
    stack                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   <PII> path;
    int x=n-1,y=m-1;
    while (x||y)
    {
        path.push({x,y});
        auto t = pre[x][y];
        x = t.first, y = t.second;
    }
    path.push({0,0});
    while (path.size())
    {
        auto t = path.top();
        path.pop();
        cout<<'('<<t.first<<','<<t.second<<')'<<endl;
    }
    
    
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