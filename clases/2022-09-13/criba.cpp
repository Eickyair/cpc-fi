#include <bits/stdc++.h>
using namespace std;
vector<int> criba(int n){
    vector<int> c(n+1);
    for(int i=2;i<=n;i++){
        if(!c[i]){
            int mult = i;
            while(mult<=n){
                c[mult]=i;
            }
        }
    }
}
int main(){
    int n;
}