#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N = 1e5 + 10;
int a[N], s[N];
int main(){
    cin >> n;
    int res = 0;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0, j = 0; i < n; i ++){
        s[a[i]] ++;
        while(s[a[i]] > 1 && j < i){
            s[a[j]] --;
            j ++;
        }
        res = max(res, i - j + 1);
    }
    cout << res;
    return 0;
}
