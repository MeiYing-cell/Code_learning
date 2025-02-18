#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int N = 12, M = 1 << N;
long long f[N][M];//每列有M个不同的状态
bool st[M];//存储每种状态是否合法，即是否有奇数个连续的0
vector<int> state[M];//vector即表示第几列，M对应的是该列的状态
int n, m;
int main(){
    while(cin >> n >> m, n || m){
        //第一部分，预处理st，即先看单列合法状态.对于每种状态，先预处理每列不能有奇数个连续的0
        for(int i = 0; i < (1 << n); i ++){
            int cnt = 0;
            bool is_valid = true;
            for(int j = 0; j < n; j ++){//看每个位
                if((i >> j) & 1){//看第j位是否为1
                    if(cnt & 1){//这一位为1，看前面连续的0的个数，如果是奇数（cnt &1为真）则该状态不合法
                        is_valid = false;
                        break;
                    }
                    cnt = 0;//此时清零，这个不影响答案，但更便于理解
                }
                else cnt ++;
            }
            if(cnt & 1) is_valid = false;
            st[i] = is_valid;//就是对一个数进行处理
        }

        //第二部分：处理state，表示状态st的所有合法相邻状态k
        for(int j = 0; j < (1 << n); j ++){//对于第i列的状态，即从i-1列伸出来的
            state[j].clear();
            for(int k = 0; k < (1 << n); k ++){//对于第i-1列的状态
                if((j & k) == 0 && st[j | k]){
                    // 第i-2列伸出来的 和第i-1列伸出来的不冲突(不在同一行) 
                    //这个 j|k 就是当前 第i-1列的到底有几个1，即哪几行是横着放格子的,此时第i列还没有确定伸出去多少
                    state[j].push_back(k);
                    //存入状态j的合法的相邻状态k
                    //“真正”可行是指：既没有前后两列伸进伸出的冲突；又没有连续奇数个0。
                }
            }
        }
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for(int i = 1; i <= m; i ++){
            for(int j = 0; j < (1 << n); j ++){
                for(auto k : state[j])//遍历statej的每个元素（每个合法状态）
                    f[i][j] += f[i - 1][k];//i列j状态下的方案数，就是i-1列的所有j状态的，所有合法相邻状态的方案数的总和.如果i-1列的j状态不合法，则没有k，则不会+到fij
            }
        }
        cout << f[m][0] << endl;
    }
    return 0;
}