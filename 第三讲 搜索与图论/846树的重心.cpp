#include<iostream>
#include<cstring>
using namespace std;
const  int N = 1e5 + 10;
const int M = 2 * N;
int h[N], idx;
int e[M], ne[M];
bool st[N];
int n;
int ans = N;//记录最终的答案，最小的最大值点数
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
//返回以u为根节点的树的结点数，包括u
int dfs(int u){
    st[u] = true;
    int res = 0;//记录删掉节点u后最大的连通子图的结点数
    int sum = 1;//初始包括自己是1
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);//要比较两部分谁大
    ans = min(ans, res);
    return sum;
}
int main(){
    memset(h, -1, sizeof(h));
    
    cin >> n;
    for(int i = 0; i < n - 1; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans;
    return 0;
}