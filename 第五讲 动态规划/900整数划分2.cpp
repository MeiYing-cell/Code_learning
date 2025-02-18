#include<iostream>
using namespace std;
const int  N = 1e3 + 10, mod = 1e9 + 7;
int n;
int f[N][N];
int main(){
    cin >> n;

    f[1][1] = 1;
    for(int i = 2; i <= n; i ++){
        for(int j = 1; j <= i; j ++){
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;
        }
    }
    int res =0;
    for(int i = 1; i <= n; i ++) res = (f[n][i] +res) % mod;
    cout << res;
}
