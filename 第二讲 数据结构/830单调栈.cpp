#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int stk[N], tt;
int main(){
    cin >> n;
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        while(tt && stk[tt] >= x) tt --;//如果栈顶元素大于当前待入栈元素，则出栈
        if(tt) cout << stk[tt] << ' ';//如果栈空，则没有比该元素小的值。
        else cout << -1 << ' ';//栈顶元素就是左侧第一个比它小的元素。
        stk[++ tt] = x;
    }

    return 0;
}