#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int d[N];
queue<int> q;
int n, m;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int bfs(){
    memset(d, -1, sizeof d);
    d[1] = 0;
    q.push(1);
    while(q.size()){
        int t = q.front();
        q.pop();
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(d[j] == -1){//优化可直接用d[j]代替st
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }
    return d[n];
}
int main(){
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() <<endl;
    return 0;
}