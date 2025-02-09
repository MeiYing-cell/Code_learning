#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1005;
const int MAXN = 20;
int n,m;
char s[N][MAXN];
int dp[MAXN][MAXN];

int edit_distance(char a[], char b[]){
    int la = strlen(a + 1), lb = strlen(b + 1);
    
    //初始化
    for(int i = 0; i <= lb; i ++) dp[0][i] = i;
    for(int i = 0; i <= la; i ++) dp[i][0] = i;
    //动态规划
    for(int i = 1; i <= la; i ++){
        for(int j = 1; j <= lb; j ++){
            dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
            if(a[i] == b[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    return dp[la][lb];
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> (s[i] + 1);
    while (m--)
    {
        int res = 0;
        char query[MAXN];
        int limit;
        cin >> (query + 1) >> limit;
        for(int i = 1; i <= n; i ++){
            int temp = edit_distance(s[i] , query);
            if(temp <= limit) res++;
        }
        cout << res <<endl;
    }
    
    return 0;
}