/**
 * TWO POINTERS
 * Tecnica que nos permite utilizar dos o mas indices para ir recorriendo
 * un arreglo o mas 
*/


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
    int len1,len2;
    cin >> len1 >> len2;
    vector<int> a1(len1);
    vector<int> a2(len2);
    vector<int> res(len1+len2-1);
    int p1=0,p2=0;
    for (int i = 0; i < len1; i++)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < len2; i++)
    {
        cin >> a2[i];
    }
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
    int p3 = 0;
    while (p3<(int)res.size())
    {
        if(a1[p1]<a2[p2]){
            res[p3] =  a1[p1];
            p1++;
            p3++;
        }else if(a1[p1]==a2[p2]){
            res[p3] = a1[p1];
            p3++;
            p1++;
            res[p3] = a2[p2];
            p3++;
            p2++;
        }else{
            res[p3] = a2[p2];
            p2++;
            p3++;
        }
    }
    for(int x : res){
        cout << x << " ";
    }
    cout << endl;
}