#include<iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n,q;
int start,final;
int a[N];
int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i ++ )
        cin >> a[i];

    while(q --){
        int query;
        cin >> query;
        int l = -1, r = n;
        while(l + 1 < r){
            int mid = l + r >> 1;
            if(a[mid] >= query)r = mid;
            else l = mid;
        }
        if(a[r] != query) cout << "-1 -1" << endl;
        else{
            cout << r << ' ';
            
            int l = -1, r = n;
            while(l + 1 < r){
                int mid = l + r >> 1;
                if(a[mid] <= query)l = mid;
                else r = mid;
            }
            cout << l <<endl; 
        }
    }
    return 0;
}