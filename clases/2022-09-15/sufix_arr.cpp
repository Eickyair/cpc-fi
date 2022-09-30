#include <bits/stdc++.h>
using namespace std;

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


void radix_sort(vector<pair<pair<int, int>, int>> &a)
{
    int n = a.size();
    {
        vector<int> cnt(n);
        for (auto x : a){
            cnt[x.first.second]++;
        }
        vector<pair<pair<int, int>, int>> a_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; i++){
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto x : a){
            int i = x.first.second;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;  
    }
    {
        vector<int> cnt(n);
        for (auto x : a){
            cnt[x.first.first]++;
        }
        vector<pair<pair<int, int>, int>> a_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; i++){
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto x : a){
            int i = x.first.first;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;  
    }
}

vector<int> suffix_arr(string s)
{
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++){
            if (a[i].first == a[i - 1].first){
                c[p[i]] = c[p[i - 1]];
            }
            else{
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }
    int k = 0;
    while ((1 << k) < n){
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++){
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        radix_sort(a);
        for (int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++){
            if (a[i].first == a[i - 1].first){
                c[p[i]] = c[p[i - 1]];
            }
            else{
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k++;
    }
    return p;
}


struct segtree{
    
    int size;
    vector<long long> sums;
    
    void init(int n){
        size=1;
        while(size<n) size*=2;
        sums.assign(2*size, 0LL);
    }
    
    void build(vector<int> &a,int x,int lx, int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                sums[x]=a[lx];
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    
    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            sums[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    
    void set(int i, int v){
        set(i,v,0,0,size);
    }
    
    long long sum(int l,int r,int x,int lx, int rx){
        if(lx>= r || l>=rx) return 0;
        if(lx>=l && rx <= r) return sums[x];
        int m=(lx+rx)/2;
        long long s1=sum(l,r,2*x+1,lx,m);
        long long s2 = sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }
    long long sum(int l,int r){
        return sum(l,r,0,0,size);
    }
};

vector<int> criba(int n){
    vector<int> cri(n+1);
    int i = 2;
    while (i <= n)
    {
        if (cri[i] == 0){
            int mult = i;
            while (mult<=n){
                mult+=i;
                cri[mult] = i;
            }
        }
        i++;
    }
    return cri;
}

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a % b);
}

int main()
{
    int a = 74, b=32;
    cout << gcd(a,b);
    return 0;
}