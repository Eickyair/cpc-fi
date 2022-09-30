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
	vector<int> pos, neg, a;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x > 0){
            pos.push_back(x);
        }
		else if (x < 0){
            neg.push_back(x);
        }
		else {
			if (a.size() < 2){
                a.push_back(x);
            }
		}
	}
	if (pos.size() > 2 || neg.size() > 2){
        cout << "NO\n"; 
        return;
    }
	
	for (int i : pos){
        a.push_back(i);
    }
	for (int i : neg){
        a.push_back(i);
    }
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = i + 1; j < (int)a.size(); j++) {
			for (int k = j + 1; k < (int)a.size(); k++) {
				bool exist = false;
				for (int l = 0; l < (int)a.size(); l++) {
					if (a[i] + a[j] + a[k] == a[l]){
                        exist = true;
                    }
				}
				if (!exist){
                    cout << "NO\n"; 
                    return;
                }
			}
		}
	}
	cout << "YES\n";
}
int main(){
    //setIO();
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}