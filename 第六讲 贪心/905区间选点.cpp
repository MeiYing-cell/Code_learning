#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;
int n;
struct Range{
    int l, r;
    bool operator< (const Range & s)const{//注意重载小于符号，方便排序
        return r < s.r;
    }
}Ranges[N];
int main(){
    cin >> n;
    for(int i = 0; i < n; i ++){
        int a, b;
        cin >> a >> b;
        Ranges[i].l = a, Ranges[i].r = b;
    }
    sort(Ranges, Ranges + n);
    int res = 0, ed = -2e9;
    for(int i = 0; i < n; i ++){
        if(Ranges[i].l > ed){//当有个新的区间
            res ++;
            ed = Ranges[i].r;
        } 
    }
    cout << res;
    return 0;
}