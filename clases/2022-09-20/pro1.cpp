#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    (void)! freopen(out_file.c_str(), "w", stdout);
    (void)! freopen(in_file.c_str(), "r", stdin);
}

int maxTres(int a1,int a2, int a3){
    if( a1 >= a2 and a1 >= a3){
        return 1;
    }else if (a2>=a1 and a2>= a3)
    {
        return 2;
    }else{
        return 3;
    }
    
}

int main(){
    setIO();
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;cin >> n >> m;
    vector<int> a1(n+m-1);
    vector<int> a2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a2[i];
    }
    int k = n+m-1;
    int i = n-1;
    int j = m-1;
    while (j>=0){
        if(a1[i]>a2[j]){
            a1[k] = a1[i];
            i--;
            k--;
        }else{
            a1[k] =  a2[j];
            j--;
            k--; 
        }
    }
    for(int x : a1){
        cout << x << " ";
    }
    
}