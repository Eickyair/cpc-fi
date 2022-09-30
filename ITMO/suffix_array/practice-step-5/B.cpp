#include <bits/stdc++.h>
using namespace std;
//NOT RESOLVE
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl                        '\n'
#define fastIO()                    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FO(i, b)                    for (int i = 0; i < (b); i++)
#define FOR(i, a, b)                for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)               for (int i = (a); i > (b); i--)
#define TR(v, arr)                  for (auto& (v) : (arr))
#define debug(x)                    cout << #x << " = "; _debug(x); cout << endl;
#define pb                          push_back
#define mp                          make_pair
#define F                           first
#define S                           second
#define all(x)                      x.begin(), x.end() 
#define sz(x)                       (int) x.size()
#define LB(arr, x)                  lower_bound(all(arr), x)-(arr).begin()
#define UB(arr, x)                  upper_bound(all(arr), x)-(arr).begin()
#define PR(T1, T2) pair<T1, T2>
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";

    FILE *exist_in_file;
    exist_in_file = freopen(in_file.c_str(), "r", stdin);
    if(!exist_in_file){
        exist_in_file = freopen(in_file.c_str(), "w", stdout);
        fclose(exist_in_file);
    }
    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

template <typename T>
void _debug(T& x){
    cout << x;
}

template <typename T1, typename T2>
void _debug(pair<T1, T2>& pair){
    cout << "{"; _debug(pair.F); cout << ","; _debug(pair.S); cout << "}";  
}

template <typename T>
void _debug(vector<T>& vec){
    int n = sz(vec);
    if(n == 0){cout << "[ ]"; return;}
    cout << "[";
    FO(i, n-1){
        _debug(vec[i]); cout << " ";
    }
    _debug(vec[n-1]); cout << "]";
}

void _debug(vector<string>& vec){
    int n = sz(vec);
    cout << endl;
    FO(i, n){
        cout << vec[i] << endl;
    }
}

template <typename T>
void _debug(vector<vector<T>>& A){
    int n = sz(A);
    cout << endl;
    FO(i, n){
        _debug(A[i]); cout << endl;
    }
}

template <typename T>
void print(T& x){
    cout << x << endl;
    return;
}

template <typename T>
void print(vector<T>& vec, int a=0, int b=-1){
    if(b == -1){b = sz(vec);}
    if(b == 0){return;}
    FOR(i, a, b-1){
        cout << vec[i] << " ";
    }
    cout << vec[b-1] << endl;
    return; 
}

const int N = 1e5;

void solve() {
    int n; cin >> n;
    vi nums(n);
    FO(i, n) cin >> nums[i];
    debug(nums);
    return;
}

void count_sort_suffix(vi &a,vi &c){
    int n = sz(a);
    vector<int> cnt(n);
    for (auto x : c){
        cnt[x]++;
    }
    vector<int> a_new(n);
    vi pos(n);
    pos[0];
    for (int i = 1; i < n; i++){
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x : a){
        int i = c[x];
        a_new[pos[i]] = x;
        pos[i]++;
    }
    a = a_new;
}
vi lcp;
vi suffix_array(string &s) //-O(n log n)
{
    int n = sz(s);
    debug(s);
    vi suffix(n), cls(n);
    {
        // k = 0
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {s[i], i};
        sort(all(a));
        for (int i = 0; i < n; i++)
            suffix[i] = a[i].second;
        cls[suffix[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)
            {
                cls[suffix[i]] = cls[suffix[i - 1]];
            }
            else
            {
                cls[suffix[i]] = cls[suffix[i - 1]] + 1;
            }
        }
    }
    int k = 0;
    while ((1 << k) < n)
    {
        for(int i=0;i<n;i++){
            suffix[i]=(suffix[i]-(1<<k)+n)%n;
        }
        count_sort_suffix(suffix,cls);
        cls[suffix[0]] = 0;

        vi c_new(n);

        for (int i = 1; i < n; i++){
            PR(int, int) prev = {cls[suffix[i-1]], cls[(suffix[i-1] + (1 << k)) % n]};
            PR(int, int) now = {cls[suffix[i]], cls[(suffix[i] + (1 << k)) % n]};
            if (now==prev){
                c_new[suffix[i]] = c_new[suffix[i - 1]];
            }
            else{
                c_new[suffix[i]] = c_new[suffix[i - 1]] + 1;
            }
        }
        cls = c_new;
        k += 1;
    }
    // _debug(cls);
    // cout << endl;
    vi phi(n);
    for (int i = 1; i < n; i++)
    {
        phi[suffix[i]] = suffix[i - 1];
    }
    // _debug(phi);
    vi plcp(n);
    // cout << endl;
    int l = 0;
    for (int j = 0; j < n-1; j++)
    {
        while(s[j+l]==s[phi[j]+l]){l++;}
        plcp[j] = l;
        if(l>0) l--;
    }
    lcp.resize(n);
    for (int i = 1; i < n; i++)
    {
        lcp[i] = plcp[suffix[i]];
    }
    debug(lcp);
    for(auto i : suffix)
    {
        string sub = s.substr(i,n-i);
        cout << i << " ";
        _debug(sub);cout<<endl;
    }
    return suffix;
}
int upperBound(vi &a, int x)
{
    int l = -1;    // a[l] <= x
    int r = sz(a); // a[r]>x
    while (r > l + 1){
        int m = (l + r) / 2;
        if (a[m] < x){
            l = m;
        }
        else{
            r = m;
        }
    }
    return r+1;
}
int lowerBound(vi &a, int x)
{
    int l = -1;    // a[l] <= x
    int r = sz(a); // a[r]>x
    while (r > l + 1){
        int m = (l + r) / 2;
        if (a[m] <= x){
            l = m;
        }
        else{
            r = m;
        }
    }
    return l + 1;
}
int main() {
    fastIO();
    setIO();
    string s;
    cin >> s;
    vi p = suffix_array(s);
    //debug(p);
    return 0;
}