#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], w[N],idx;
bool st[N];
int dist[N], cnt[N];
int n,m;
void add(int a, int b, int c){
    w[idx] = c, e[idx] = b,ne[idx] = h[a], h[a] = idx ++;
}
bool spfa(){
     // 这里不需要初始化dist数组为 正无穷/初始化的原因是， 如果存在负环， 那么dist不管初始化为多少， 都会被更新
    queue<int> q;
    for(int i = 1; i <= n; i ++){
         q.push(i);
        st[i] = true;
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;//遍历t的出边
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){//注意这里是dist[t],不是dist[i]
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}
int main(){
    cin >> n >> m;
    memset(h, -1 ,sizeof h);
    while(m --){
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    
    if(spfa()) cout << "Yes";
    else cout << "No";
    return 0;
}