// problem: https://codeforces.com/problemset/problem/268/A
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
typedef vector<pair < int, int>> vpii;
int main(){
    setIO();
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vpii equipos(n);
    int i = 0;
    while (i<n)
    {
        int h, a;
        cin >> h >> a;
        equipos[i] = make_pair(h, a);
        i++;
    }
    int contador = 0;
    for (int i = 0; i < equipos.size(); i++)
    {
        for (int j = 0; j < equipos.size(); j++)
        {
            if(i!=j){
                if(equipos[i].first==equipos[j].second)
                    contador++;
            }
        }
        
    }
    cout << contador;
}