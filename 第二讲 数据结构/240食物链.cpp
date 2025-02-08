#include<iostream>
using namespace std;
const int N = 5e5 + 10;
int p[N], d[N];
int n, k;
int find(int x){
    if(p[x] != x){
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){//初始化并查集
        p[i] = i;
    }
    int res = 0;
    while(k --){
        int op, x, y;
        cin >> op >> x >> y;
        if(x > n|| y > n) res ++;//判断x和y的范围
        else{
            int px = find(x), py = find(y);
            if(op == 1){//是同类情况
                if(px == py && (d[x] - d[y]) % 3 != 0) res ++;//已经在同一个集合，判断是否有冲突
                else if(px != py){//不在一个集合，按照同类的规则，插入
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else if(op == 2){// x吃y的情况
                if(px == py && (d[x] - d[y] - 1) % 3) res ++;
                else if(px != py){
                    p[px] = py;
                    d[px] = d[y] + 1 -d[x];
                }
            }
        }
    }
    cout << res;
    return 0;
}