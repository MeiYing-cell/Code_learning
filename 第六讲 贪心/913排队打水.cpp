#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int t[N];
int n;
int main(){
    cin >> n;
    long long res = 0;
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        t[i] = x;
    }
    sort(t, t + n);
    for(int i = 0; i < n; i ++) res += t[i] * (n - i - 1);
    cout << res;
    return 0;
}