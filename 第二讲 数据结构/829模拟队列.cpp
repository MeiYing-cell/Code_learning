#include<iostream>
#include<string>
using namespace std;
const int N = 1e5 + 10;
string s;
int n;
int q[N], hh = 0, tt = -1;
void push(int x){
    q[++ tt] = x;
}
void pop(){
    hh ++;
}
void query(){
    cout << q[hh] <<endl;
}
void empty(){
    if(hh <= tt) cout << "NO" <<endl;
    else cout << "YES" <<endl;
}
int main(){
    cin >> n;
    while(n --){
        
        cin >> s;
        if(s == "push"){
            int x;
            cin >> x;
            push(x);
        }
        else if(s == "pop"){
            pop();
        }
        else if(s == "empty"){
            empty();
        }
        else if(s == "query"){
            query();
        }
    }
    return 0;
}