#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
void setIO()
{
    string file = __FILE__;
    file = string(file.begin(), file.end() - 3);
    string in_file = file + "in";
    string out_file = file + "out";
    (void)!freopen(out_file.c_str(), "w", stdout);
    (void)!freopen(in_file.c_str(), "r", stdin);
}
int main()
{
    //setIO();
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        for (int i = n & 1; i < n - 2; i += 2)
            swap(p[i], p[i + 1]);
        for (int &x : p)
            cout << x << ' ';
        cout << '\n';
    }
}