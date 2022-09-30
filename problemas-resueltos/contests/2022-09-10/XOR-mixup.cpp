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
void solve() {
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
    }
    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
}