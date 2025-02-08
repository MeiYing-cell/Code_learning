#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], w[N],idx;
bool st[N];
int dist[N];
int n,m;
void add(int a, int b, int c){
    w[idx] = c, e[idx] = b,ne[idx] = h[a], h[a] = idx ++;
}
int spfa(){
    memset(dist, 0x3f, sizeof dist);

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    st[1] = true;

    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;//遍历t的出边
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){//注意这里是dist[t],不是dist[i]
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dist[n];
}
int main(){
    cin >> n >> m;
    memset(h, -1 ,sizeof h);
    while(m --){
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    
    int t = spfa();
    if(t == 0x3f3f3f3f) cout << "impossible";
    else cout << t;
    return 0;
}