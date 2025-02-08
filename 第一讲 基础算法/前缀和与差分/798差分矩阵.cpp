#include<iostream>
#include<cstdio>

using namespace std;
const int N = 1e3 + 10;
int n, m, q;
int a[N][N], b[N][N];//a是前缀和数组，b是差分数组
void insert(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> a[i][j];
        }
    }
     for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            insert(i, j, i, j, a[i][j]);
            //b[i][j] = a[i][j] - a[i][j-1] - a[i-1][j] + a[i-1][j-1];//构建二维差分数组
        }
    }

    while(q --){
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c); 
    }
    
     for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
             a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + b[i][j];
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
           printf("%d ",a[i][j]);
        }
        puts("");
    }
    return 0;
}