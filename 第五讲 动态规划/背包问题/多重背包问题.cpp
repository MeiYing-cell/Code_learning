#include<iostream>
#include<algorithm>
using namespace std;
const int N = 105;
int n, m;
int v[N], w[N], s[N];
int f[N];

int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n; i++) cin >> v[i] >> w[i] >> s[i];

    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= s[i]; k ++)//k放在第二层，看作k个不同的物品
            for(int j = m; j >= v[i]; j -- ){
                f[j] = max(f[j] , f[j-v[i]] + w[i]);
            }
    }
    //版本2
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= v[i]; j -- )
            for(int k = 1; k <= s[i]; k ++)
            {
                f[j] = max(f[j] , f[j-k * v[i]] + k * w[i]);//这里是把k放在最里面，看作k个不同决策，
            }
    }
    cout << f[m];
    return 0;
}