#include<iostream>
#include<algorithm>

using namespace std;
typedef pair<int, int> PII;
const int N = 5e4 + 10;
PII cow[N];
int n;
int main(){
    cin >> n;
    for(int i = 0; i < n; i ++){
        int w, s;
        cin >> w >> s;
        cow[i] = {w + s, w};
    }
    sort(cow, cow + n);
    int res = -2e9, sum = 0;
    for(int i = 0; i < n; i ++){
        int s = cow[i].first - cow[i].second;
        int w = cow[i].second;
        res = max(res, sum - s);
        sum += w;
    }
    cout << res;
    return 0;
}