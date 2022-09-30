#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl                        '\n'
#define ull                         unsigned long long
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
template <typename T1, typename T2>
void _debug(unordered_map<T1,T2> &mi_mapa){
    cout << "map:{\n";
    for (auto const& pair: mi_mapa)
    {
        cout << "\tkey:" << pair.first << " value:" << pair.second << endl;
        }
        cout << "}\n";
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


ull factorial(ull n,unordered_map<ull,ull> &dp){
    ull i = n-1;
    auto it = dp.find(n);
    while(it == dp.end()){
        it = dp.find(i);
        i--;
    }
    ull res = it->second;
    i += 2;
    while (i<=n){
        res *= i; //aqui dice que se pasa
        //res = (res * i) % MOD;
        dp[i] = res;
        i++;
    }
    return res;
}


ull combinaciones(ull n,ull k, unordered_map<ull,ull> &dp){
    if(k>n) return 0;
    ull n_fac = factorial(n, dp);
    ull k_fac = factorial(k, dp);
    ull n_k = factorial(n - k, dp);
    return (n_fac) / (k_fac * n_k);
}

// int main()
// {
//     //fastIO();
//     //setIO();
//     int t;
//     cin >> t;
//     unordered_map<ull, ull> dp = {{0 , 1}, {1 , 1}};
//     while(t--){
//         int n;
//         cin >> n;
//         vi j(n);
//         FO(i,n){
//             cin >> j[i];
//         }
//         auto it = max_element(all(j));
//         int max = *it;
//         *it = 0;
//         int segundo = *max_element(all(j));
//         int diff = max - segundo;
//         if(diff>=2){
//             cout << 0 << endl;
//         }else if(diff==1){
//             int cnt = count(all(j), segundo);
//             ull n_fac = factorial(n, dp);
//             ull sumas = 0;
//             ull c = factorial(cnt, dp) * factorial(n - cnt-1,dp);
//             for (int i = 1; i <= n;i++){
//                 ull aux = combinaciones(i-1,cnt,dp);
//                 sumas += aux;
//             }
//             sumas = c * sumas;
//             n_fac = n_fac - sumas;
//             cout << n_fac % MOD << endl;
//         }else if(diff==0){
//             ll res = factorial(n, dp) % MOD;
//             cout << res << endl;
//         }
//     }
//     return 0;
// }


const int MOD = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //setIO();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int mx = *max_element(a.begin(), a.end());
    int cmx = count(a.begin(), a.end(), mx);
    int k = count(a.begin(), a.end(), mx - 1);
    int ans = 1, sub = 1;
    for (long long i = 1; i <= n; ++i) {
      ans = ans * i % MOD;
      if (i != k + 1) sub = sub * i % MOD;
    }
    if (cmx == 1) ans = (ans - sub + MOD) % MOD;
    cout << ans << '\n';
  }
}