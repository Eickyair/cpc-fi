#include <bits/stdc++.h>
using namespace std;
// minimo comun divisor
int gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a%b);
}
int main(){
    int a=10,b=100;
    cout << gcd(a,b);
    return 0;
}