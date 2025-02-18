#include<iostream>

using namespace std;
const int N = 1e6 + 10;
bool st[N];
int primes[N];
int cnt;
int n;
void get_prime2(){//朴素版本
    for(int i = 2; i <= n; i ++){
        if(!st[i]) primes[cnt ++] = i;
        for(int j = i; j <= n; j += i){//不管是合数还是质数，都用来筛掉后面它的倍数
            st[j] = true;
        }
    }
}
void get_prime1(){
    for(int i = 2; i <= n; i ++){
        if(!st[i]) {
            primes[cnt ++] = i;
            for(int j = i; j <= n; j += i) st[j] = true;//可以用质数就把所有的合数都筛掉；
        }
    }
}
void get_prime(){
    for(int i = 2; i <= n; i ++){
        if(!st[i]) primes[cnt ++] = i;
        for(int j = 0; primes[j] <= n/i; j ++){
            st[primes[j] * i] = true;//要保证primes式最小质因子
            /*1)当i%primes[j]!=0时,说明此时遍历到的primes[j]不是i的质因子，那么只可能是此时的primes[j]<i的最小质因子,所以primes[j]*i的最小质因子就是primes[j];
            2)当有i%primes[j]==0时,说明i的最小质因子是primes[j],因此primes[j]*i的最小质因子也就应该是prime[j]，之后接着用st[primes[j+1]*i]=true去筛合数时，就不是用最小质因子去更新了,因为i有最小质因子primes[j]<primes[j+1],此时的primes[j+1]不是primes[j+1]*i的最小质因子，此时就应该退出循环，避免之后重复进行筛选。*/
            if(i % primes[j] == 0) break;
        }
    }
}
int main(){
    cin >> n;
    get_prime();
    cout << cnt;
    return 0;
}