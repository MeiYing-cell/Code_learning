#include<iostream>
using namespace std;

int lowbit(int x){
    return x & -x;
}
int main(){
    int n;
    cin >> n;
    while(n --){
        int x;
        int res = 0;
        cin >> x;
        while(x){
            x -= lowbit(x);
            res ++;
        }
        cout<< res <<" ";
    }
    return 0;
}