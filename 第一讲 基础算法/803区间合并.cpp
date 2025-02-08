#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
int n;
vector<PII> segs;
void merge(vector<PII> &segs){
    vector<PII> res;
    sort(segs.begin(),segs.end());
    // 左右端点初始化，-无穷
    int st = -2e9, ed = -2e9;
    for(auto seg : segs){//合并步骤
        if(ed < seg.first){
            // 初始的[-无穷，-无穷]区间要跳过，不能装入
            if(ed != -2e9) res.push_back({st, ed});
            st = seg.first;
            ed = seg.second;
        }
        else ed = max(ed, seg.second);
    }
    // 有两个作用，1.是防止n为0，把[-无穷，-无穷]压入；2.是压入最后一个（也就是当前）的区间，若n>=1，if可以不要
    if(st != -2e9) res.push_back({st, ed});
    segs = res;
}
int main(){
    cin >> n;
    while(n --){
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout<< segs.size();
    return 0;
}

