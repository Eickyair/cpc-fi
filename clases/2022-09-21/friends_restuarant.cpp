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
    int t;cin >> t;
    while (t--){
        int n;cin>>n;
        vector<int> costo(n);  
        vector<int> dinero(n);
        vector<int> sobrantes(n);
        int i = 0;
        while (i<n)
        {
            cin >> costo[i];
            i++;
        }
        i = 0;
        while (i<n)
        {
            cin >> dinero[i];
            sobrantes[i] =  dinero[i] - costo[i];
            i++;
        }
        sort(sobrantes.begin(),sobrantes.end());
        int j = 0;
        int cont = 0;
        i = (int)sobrantes.size()-1;
        // cout << "i:" << i << endl;
        while (j<i)
        {
            if(sobrantes[j]+sobrantes[i]>=0){
                cont++;
                j++;
                i--;
            }else{
                j++;
            }
        }
        
        // for(int x : sobrantes) cout << x << " ";
        // cout << endl;
        cout << cont<< endl;
    }
    
}