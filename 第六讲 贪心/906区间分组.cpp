#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 1e5 + 10;
int n;
struct Range{
    int l, r;
    bool operator< (const Range &w)const{
        return l < w.l;
    }
}Ranges[N];

int main(){
    cin >> n;
    for(int i= 0; i < n; i ++){
        int l, r;
        cin >> l >> r;
        Ranges[i].l = l,Ranges[i].r = r;
    }
    sort(Ranges,Ranges + n);
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0; i < n; i ++){//heap存的是右端点，ranges按照左端点排序
        if(heap.empty() || heap.top() >= Ranges[i].l){
            heap.push(Ranges[i].r);
        }
        else{
            heap.pop();
            heap.push(Ranges[i].r);
        }
    }
    cout << heap.size();
    return 0;
}