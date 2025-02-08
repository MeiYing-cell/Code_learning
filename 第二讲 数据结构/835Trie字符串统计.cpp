#include<iostream>
#include<string>

using namespace std;
const int N = 1e5 + 10;
int n;
int idx, son[N][26], cnt[N];
void insert(string s){
    int p = 0;//指向根节点
    for(int i = 0;i < s.size(); i ++){
        int u = s[i] - 'a';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];//现在移到子节点
    }
    cnt[p] ++;
}
int query(string s){
    int p = 0;
    for(int i = 0;i < s.size(); i ++){
        int u = s[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];//现在移到子节点
    }
    return cnt[p];
}
int main(){
    cin >> n;
    string op, s;
    while(n --){
        cin >> op >> s;
        if(op == "I"){
            insert(s);
        }
        else if(op == "Q"){
            cout << query(s) <<endl;
        }
    }
    return 0;
}