#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 3e5 + 10;
int n, m;
int a[N];//存储离散化坐标插入的值
int s[N];//前缀和数据
vector<int> alls;//离散化后的坐标
vector<PII> add, query;//存储插入和查询的数据
int find(int x){//返回离散化后的坐标
    int l = -1, r = alls.size();
    while(l + 1 < r){
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid; 
    }
    return r + 1;//返回从1开始的坐标，方便求前缀和
}
int main(){
    cin >> n >> m;
    while(n --){
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    while(m --){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    //排序去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    //执行n次插入操作
    for(auto item : add){
        int x = find(item.first);//find是找离散化后的坐标
        a[x] += item.second;
    }
    //前缀和
    for(int i = 1; i <= alls.size(); i ++) s[i] = s[i - 1] + a[i];
    //执行m次查询操作
    for(auto item: query){
        int l = find(item.first);
        int r = find(item.second);
        cout << s[r] - s[l - 1] <<endl;
    }
    return 0;
}