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
    int w;
    cin >> w;
    for (int i = 1; i < w; i++)
    {
        int second = w - i;
        if(i%2==0 and second%2==0){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}