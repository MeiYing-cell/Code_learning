#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int N = 2e5 + 3, null = 0x3f3f3f3f;//一般取大于范围的最小质数
int h[N];
int n;

int find(int x){
    int k = (x % N + N) % N;
    while(h[k] != null && h[k] != x){
        k ++;
        if(k == N){//到达末尾需要重新开始
            k = 0;
        }
    }
    return k;//传输应该在的位置
}
int main(){
    memset(h, 0x3f ,sizeof h);
    cin >> n;
    while(n --){
        string op;
        int x;
        cin >> op >> x;
        if(op == "I"){
            h[find(x)] = x;
        }
        else{
            if(h[find(x)] != null) cout << "Yes" <<endl;
            else cout << "No" <<endl;
        }
    }
    return 0;
}