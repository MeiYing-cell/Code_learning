#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> get_divisors(int x){
    vector<int> res;
    for(int i = 1; i <= x / i; i ++){
        if(x % i == 0) 
        {
            res.push_back(i);
            if(i != x / i) res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
int main(){
    cin >> n;
    while(n --){
        int a;
        cin >> a;
        auto res = get_divisors(a);
        for(auto i : res){
            printf("%d ", i);
        }
        puts("");
    }
    return 0;
}