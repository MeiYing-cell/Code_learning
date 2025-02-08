#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int N = 1e5 + 10;
int p[N];//表示各自的祖先节点，初始祖先节点都为自己
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) p[i] = i;
    while(m --){
        string op;
        int a, b;
        cin >> op >> a >> b;
        if(op == "M"){
            p[find(a)] = find(b);
        }
        else if(op == "Q"){
            if(find(a) == find(b)) cout<<"Yes"<<endl;
            else cout << "No" <<endl;
        }
    }
    return 0;
}
