#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int e[N], ne[N], head, idx;
void init(){
    head = -1;
    idx = 0;//初始idx指向的是第0个
}
void add_head(int x){
    e[idx] = x, ne[idx] = head, head = idx ++;
}
void add(int k, int x){
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++;
}
void remove(int k){
    ne[k] = ne[ne[k]];
}
int main(){
    int m;
    cin >> m;
    init();
    while(m --){
        char op;
        int k, x;
        cin >> op;
        if(op == 'H'){
            cin >> x;
            add_head(x);
        }
        else if(op == 'D'){
            cin >> k;
            if(k == 0) head = ne[head];
            else remove(k - 1);
        }
        else if(op == 'I'){
            cin >> k >> x;
            add(k-1, x);
        }
    }
    for(int i = head; i != -1; i = ne[i]) cout << e[i] <<" ";
    return 0;
}