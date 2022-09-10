//problema: https://codeforces.com/problemset/problem/1728/A
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
int main(){
    //setIO();
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> balls(n);
        int max = -1;
        int i = 1;
        int aws=1;
        while (n--)
        {
            int num;
            cin >> num;
            if(max < num){
                max = num;
                aws = i;
            }
            i++;
        }
        cout << aws << endl;
    }
}