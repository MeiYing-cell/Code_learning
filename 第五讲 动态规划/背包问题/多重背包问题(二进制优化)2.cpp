#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 11010;
const int M = 2010;
int n, m;
int v[N],w[N];//因为cnt增加，1000*log(2000)
int f[M];


int main(){
    cin >> n >> m;
    int cnt = 0;//组别数量

    //二进制优化
    for(int i = 1; i <= n; i++){
        int a,b,s;
        cin >> a >> b >> s;
        for(int k = 1; k <= s ; k*=2){
            cnt ++;
            s-=k;
            v[cnt] = a * k;
            w[cnt] = b * k;
        }
        if(s > 0){
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    n = cnt;
    //01背包问题模板套上
    for(int i = 1 ;i <= n ;i ++)
        for(int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m];
    return 0;
}