#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

stack<int> num;
stack<char> op;
unordered_map<char, int> h{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
void eval(){
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    char p = op.top();
    op.pop();
    int r = 0;
    if(p == '+') r = a + b;
    else if(p == '-') r = a-b;
    else if(p == '*') r = a*b;
    else if(p == '/') r = a / b;
    num.push(r);
}
int main(){
    string s;
    cin >> s;
    for(int i = 0;i < s.size(); i ++){
        if(isdigit(s[i])){
            int j = i, x = 0;
            while(j < s.size() && isdigit(s[j])){
                x = x * 10 + s[j] - '0';
                j ++;
            }
            num.push(x);
            i = j - 1;
        }
        else if(s[i] == '(') op.push(s[i]);
        else if(s[i] == ')'){
            while(op.top() != '(') eval();
            op.pop();
        }
        else{
            while(op.size() && h[op.top()] >= h[s[i]]) eval();
            op.push(s[i]);
        }
    }
    while(op.size()) eval();
    cout << num.top();
    return 0;
}