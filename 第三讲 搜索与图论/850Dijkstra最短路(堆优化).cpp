#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
typedef pair<int, int> PII;
const int N = 1.5e5 + 10;
int h[N], e[N], ne[N], w[N],idx;
bool st[N];
int dist[N];
int n,m;
void add(int a, int b, int c){
    w[idx] = c, e[idx] = b,ne[idx] = h[a], h[a] = idx ++;
}
int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    // 定义一个小根堆
    // 这里heap中为什么要存pair呢，首先小根堆是根据距离来排的，所以有一个变量要是距离，
    // 其次在从堆中拿出来的时候要知道知道这个点是哪个点，不然怎么更新邻接点呢？所以第二个变量要存点
    dist[1] = 0;
    heap.push({0, 1});//第一个表示距离，第二个表示节点
    while(heap.size()){
        PII k = heap.top();
        heap.pop();
        int ver = k.second, distance = k.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver]; i != -1; i = ne[i]){
            int j= e[i];
            if(dist[j] > distance + w[i]){
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }    
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}
int main(){
    cin >> n >> m;
    memset(h, -1 ,sizeof h);
    while(m --){
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    cout<<dijkstra();
    return 0;
}