#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int n;
int st, ed;
struct Range
{
    int l, r;
    bool operator< (const Range &a) const{
        return l < a.l;
    }
}range[N];

int main(){
    cin >> st >> ed;
    cin >> n;
    for(int i= 0; i < n; i ++){
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    sort(range, range + n);
    int res = 0;
    bool success = false;
    for(int i = 0; i < n; i ++){
        int j = i, r = -2e9;
        while(j < n && range[j].l <= st){
            r = max(r, range[j].r);
            j ++;
        }
        if(r < st) break;
        res ++;
        if(r >= ed) {
            success = true;
            break;
        }
        st = r;
        i = j - 1;
    }
    if(!success) res = -1;
    cout << res;
    return 0;
}