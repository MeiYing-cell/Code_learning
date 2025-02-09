#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N],f[N];
//数组从1开始的话，就不需要l+1
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int len = 0;
    f[0]=-1e9 - 10;//因为有负值，第0个数还是要设一个最小值,需要和f[0]作比较
    for(int i = 0; i < n; i ++){
        int l = -1 , r = len + 1; //二分找到最后一个(最大的)的小于当前数a[i]的数
        while(l + 1 < r){
            int mid = l + r >>1;
            if(f[mid] < a[i]) l = mid;
            else r = mid;
        }//最后l是x的下标
        if(l + 1 > len) len ++;//下标对应的长度需要+1
        f[l + 1] = a[i];
    }
    cout << len;
}
