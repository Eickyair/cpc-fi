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
    setIO();
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,d; cin >> n >> d;
    unsigned long long res = 0;
    vector<pair<int,int>> data(n);
    int i = 0;
    while (n--)
    {
        int factor,dinero; cin >> dinero >> factor;
        data[i] = make_pair(factor,dinero);
        i++;
    }
    sort(data.begin(),data.end());
    // for(auto var : data)
    // {
    //     cout << "("<<var.first << "," << var.second << ")" << endl;
    // }
    int j = 0;
    i = (int)data.size()-1;
    while (j<=i)
    {
        if(j==i){
            res += data[i].first;
            j++;
            i--;
            continue;
        }
        if(abs(data[i].second-data[j].second)<d){
            res += (data[i].first+data[j].first);
            i--;
            j++;
        }else{
            j++;
        }
    }
    cout << res << endl;
}