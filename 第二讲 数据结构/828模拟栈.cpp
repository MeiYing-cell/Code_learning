#include<iostream>
#include<string>
using namespace std;
const int N = 1e5 + 10;
int stk[N], tt;
void push(int x){
    stk[++ tt] = x;
}
void pop(){
    tt--;
}
string empty(){
    if(tt > 0) return "NO";
    else return "YES";
}
int query(){
    return stk[tt];
}
int main(){
    int m;
    cin >> m;
    while(m --){
         string op;
         cin >> op;
         if(op == "push"){
            int x;
            cin >> x;
            push(x);
         }
         else if(op == "pop"){
            pop();
         }
         else if(op == "query"){
            cout << query() <<endl;
         }
         else if(op == "empty"){
            cout << empty() << endl;
         }
    }

    return 0;
}