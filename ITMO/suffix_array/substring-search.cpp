#include <bits/stdc++.h>
#include <string>
#include <cstring>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define FO(i, b) for (int i = 0; i < (b); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rFOR(i, a, b) for (int i = (a); i > (b); i--)
#define TR(v, arr) for (auto &(v) : (arr))
#define debug(x)         \
    cout << #x << " = "; \
    _debug(x);           \
    cout << endl;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define LB(arr, x) lower_bound(all(arr), x) - (arr).begin()
#define UB(arr, x) upper_bound(all(arr), x) - (arr).begin()
#define PR(T1, T2) pair<T1, T2>
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void setIO()
{
    string file = __FILE__;
    file = string(file.begin(), file.end() - 3);
    string in_file = file + "in";
    string out_file = file + "out";

    FILE *exist_in_file;
    exist_in_file = freopen(in_file.c_str(), "r", stdin);
    if (!exist_in_file)
    {
        exist_in_file = freopen(in_file.c_str(), "w", stdout);
        fclose(exist_in_file);
    }
    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

template <typename T>
void _debug(T &x)
{
    cout << x;
}

template <typename T1, typename T2>
void _debug(pair<T1, T2> &pair)
{
    cout << "{";
    _debug(pair.F);
    cout << ",";
    _debug(pair.S);
    cout << "}";
}

template <typename T>
void _debug(vector<T> &vec)
{
    int n = sz(vec);
    if (n == 0)
    {
        cout << "[ ]";
        return;
    }
    cout << "[";
    FO(i, n - 1)
    {
        _debug(vec[i]);
        cout << " ";
    }
    _debug(vec[n - 1]);
    cout << "]";
}

void _debug(vector<string> &vec)
{
    int n = sz(vec);
    cout << endl;
    FO(i, n)
    {
        cout << vec[i] << endl;
    }
}

template <typename T>
void _debug(vector<vector<T>> &A)
{
    int n = sz(A);
    cout << endl;
    FO(i, n)
    {
        _debug(A[i]);
        cout << endl;
    }
}

template <typename T>
void print(T &x)
{
    cout << x << endl;
    return;
}

template <typename T>
void print(vector<T> &vec, int a = 0, int b = -1)
{
    if (b == -1)
    {
        b = sz(vec);
    }
    if (b == 0)
    {
        return;
    }
    FOR(i, a, b - 1)
    {
        cout << vec[i] << " ";
    }
    cout << vec[b - 1] << endl;
    return;
}

const int N = 1e5;

void solve()
{
    int n;
    cin >> n;
    vi nums(n);
    FO(i, n)
    cin >> nums[i];
    debug(nums);
    return;
}

void count_sort_suffix(vi &a, vi &c)
{
    int n = sz(a);
    vector<int> cnt(n);
    for (auto x : c)
    {
        cnt[x]++;
    }
    vector<int> a_new(n);
    vi pos(n);
    pos[0];
    for (int i = 1; i < n; i++)
    {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x : a)
    {
        int i = c[x];
        a_new[pos[i]] = x;
        pos[i]++;
    }
    a = a_new;
}
vi suffix_array(string &s) //-O(n log n)
{
    s += "$";
    int n = sz(s);
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
        for (int i = 0; i < n; i++)
        {
            suffix[i] = (suffix[i] - (1 << k) + n) % n;
        }
        count_sort_suffix(suffix, cls);
        cls[suffix[0]] = 0;

        vi c_new(n);

        for (int i = 1; i < n; i++)
        {
            PR(int, int)
            prev = {cls[suffix[i - 1]], cls[(suffix[i - 1] + (1 << k)) % n]};
            PR(int, int)
            now = {cls[suffix[i]], cls[(suffix[i] + (1 << k)) % n]};
            if (now == prev)
            {
                c_new[suffix[i]] = c_new[suffix[i - 1]];
            }
            else
            {
                c_new[suffix[i]] = c_new[suffix[i - 1]] + 1;
            }
        }
        cls = c_new;
        k += 1;
    }
    // SHOW SUBFIJOS
    // for (auto i : suffix)
    // {
    //     string sub = s.substr(i, n - i);
    //     cout << i << "-";
    //     _debug(sub);
    //     cout << endl;
    // }
    return suffix;
}

int bns_suffix(string &s, string &sub, vi &suffix)
{
    int l = 0;
    int r = sz(suffix)-1;
    // debug(sub);
    while (r>=l)
    {
        int m = (r + l) / 2;
        string cmp = s.substr(suffix[m], sz(sub));
        // debug(cmp);
        if(cmp == sub){
            return m;
        }else if(cmp<sub){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    return -1;
}

int main()
{
    fastIO();
    //setIO();
    string s;
    cin >> s;
    vi suffix;
    suffix = suffix_array(s);
    int n;
    cin >> n;
    while (n--)
    {
        string sub;
        cin >> sub;
        int res = bns_suffix(s, sub, suffix);
        (res != -1) ? cout << "Yes" << endl : cout << "No" << endl;
    }
    return 0;
}