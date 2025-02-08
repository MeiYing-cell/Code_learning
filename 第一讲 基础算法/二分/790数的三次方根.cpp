#include<iostream>
#include <algorithm>
using namespace std;

double f;

int main(){
    cin >> f;
    double l = -100, r = 100;
    while(r-l > 1e-8){
        double mid =(l + r)/2;
        if(mid  * mid * mid <= f)l = mid;
        else r = mid ;
    }
    printf("%.6lf",l);
    return 0;
}