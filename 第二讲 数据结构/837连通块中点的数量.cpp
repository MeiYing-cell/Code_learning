#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int N = 1e5 + 10;
int p[N], Size[N];//表示各自的祖先节点，初始祖先节点都为自己
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        p[i] = i;
        Size[i] = 1;
        }
    while(m --){
        string op;
        int a, b;
        cin >> op;
        if(op == "C"){
            cin >> a >> b;
            if(find(a) == find(b)) continue;
            // 下面两行代码注意顺序
            Size[find(b)] += Size[find(a)];
            p[find(a)] = find(b);
        }
        else if(op == "Q1"){
            cin >> a >> b;
            if(find(a) == find(b)) cout<<"Yes"<<endl;
            else cout << "No" <<endl;
        }
        else if(op == "Q2"){
        cin >> a;
        cout << Size[find(a)] <<endl;
        }
    }   
    return 0;
}
