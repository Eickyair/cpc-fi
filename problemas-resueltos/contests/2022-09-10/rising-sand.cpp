#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int MAX = 200007;
const int MOD = 1000000007;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    (void)! freopen(out_file.c_str(), "w", stdout);
    (void)! freopen(in_file.c_str(), "r", stdin);
}
void solve() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
	    cin >> a[i];
	}
	if (k > 1) {
	    int res = 0;
	    for (int i = 1; i < n - 1; i++) {
	        res += (a[i] > a[i - 1] + a[i + 1]);
	    }
	    cout << res << '\n';
	}
	else {
	    cout << (n - 1) / 2 << '\n';
	}
}

int main(){
    //setIO();
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; 
    cin >> t; 
    for (int i = 1; i <= t; i++){
        solve();
    }
}


 
