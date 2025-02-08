#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int N = 1e5 + 3;//一般取大于范围的最小质数
int h[N], e[N], ne[N], idx;
int n;
void insert(int x){
    int k = (x % N + N) % N;//防止是负数所以加N
    e[idx] = x, ne[idx] = h[k], h[k] = idx ++;
}
bool find(int x){
    int k = (x % N + N) % N;
    for(int i = h[k]; i!= -1; i = ne[i]){
        if(e[i] == x) return true;
    }
    return false;
}
int main(){
    memset(h, -1 ,sizeof h);
    cin >> n;
    while(n --){
        string op;
        int x;
        cin >> op >> x;
        if(op == "I"){
            insert(x);
        }
        else{
            if(find(x)) cout << "Yes" <<endl;
            else cout << "No" <<endl;
        }
    }
    return 0;
}