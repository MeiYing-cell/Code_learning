#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 2010;

int n, m;
int f[N];
struct Good{
    int w,v;
};

int main(){
    cin >> n >> m;
    vector<Good> good;
    //二进制处理
    for(int i = 1 ; i <= n; i++){
        int v,w,s;
        cin >> v >> w >> s;
        for(int k = 1; k <= s ; k*=2){
            s-=k;
            good.push_back({w*k, v*k});
        }
        if(s > 0) good.push_back({w*s , v*s});
    }
    for(auto t : good)
        for(int j = m; j >= t.v; j--)
            f[j] = max(f[j], f[j-t.v] + t.w);
             
    cout << f[m];
    return 0;
}