#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
typedef long long ll;
template <class T>
using pbset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using pbmultiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define SORT(A) sort(A.begin(), A.end());
#define REVERSE(A) reverse(A.begin(), A.end());
#define srt(A, n) sort(A, A + n);
#define ln "\n"
#define dbg cout << "debug\n";
#define inf 2e18;
const ll mod = 1e9 + 7;
const ll modx = 998244353;
typedef priority_queue<ll> pqmax;
typedef priority_queue<ll, vector<ll>, greater<ll>> pqmin;
// binary search on real number l=mid||r=mid
// Ordered set functions
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
//************PRIME CHECK*************
bool ipr(int n)
{
    if (n == 1)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
//**************SIEVE****************
// BOOL HAS LESS TIME COMPLEXITY THAN INT
vector<bool> soe(9000001, 1);
void sieve()
{
    for (int i = 2; i * i <= 9000001; i++)
    {
        if (soe[i] == true)
        {
            for (int j = i * i; j <= 9000001; j += i)
                soe[j] = false;
        }
    }
}
//*************DSU******************
ll parent[200001];
ll siz[200001];
void make(ll v)
{
    parent[v] = v;
    siz[v] = 1;
}
ll find(ll v)
{
    if (parent[v] == v)
        return v;
    else // path compresssion
        return parent[v] = find(parent[v]);
}
void Union(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    { // union by size
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
//***********prime factorization*****
vector<pair<ll, ll>> pf(ll n)
{
    vector<pair<ll, ll>> ans;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            pair<ll, ll> p;
            p.first = i;
            p.second = cnt;
            ans.push_back(p);
        }
    }
    if (n > 1)
    {
        pair<ll, ll> p;
        p.first = n;
        p.second = 1;
        ans.push_back(p);
    }
    return ans;
}
//**************bin exp************
ll mpw(ll base, ll exp, ll M)
{
    // O(LOGEXP) TIME
    if (exp == 0)
        return 1;
    ll res = mpw(base, exp / 2, M);
    if (exp % 2 == 1)
        return (((res * res) % M) * base) % M;
    else
        return (res * res) % M;
}

ll pw(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res *= a;
            n--;
        }
        else
        {
            a *= a;
            n /= 2;
        }
    }
    return res;
}

//***********pop_count*******
ll ppc(ll n)
{
    ll c = 0;
    for (; n; ++c)
        n &= n - 1;
    return c;
}
//***********CEIL************
ll ceill(ll up, ll down)
{
    ll res = up / down;
    if (up % down != 0)
        res++;
    return res;
}
//**********ncr**************
ll F[1000001];
void ix()
{
    F[0] = F[1] = 1;
    for (ll i = 2; i <= 1000000; i++)
        F[i] = (F[i - 1] * 1LL * i) % mod;
}
ll n;
vector<ll> v;
string s;
string p = "MEX";
ll dp[200001][5][50];
ll f(ll idx, ll type, ll mex)
{
    if (type == 3)
    {
        if (mex == 7)
        {
            return 3;
        }
        else if (mex == 6)
        {
            return 0;
        }
        else if (mex == 5)
        {
            return 1;
        }
        else if (mex == 4)
        {
            return 0;
        }
        else if (mex == 3)
        {
            return 2;
        }
        else if (mex == 2)
        {
            return 0;
        }
        else if (mex == 1)
        {
            return 1;
        }
    }
    if (idx == s.size())
        return 0;
    if (dp[idx][type][mex] != -1)
        return dp[idx][type][mex];
    ll ans = 0;
    ans += f(idx + 1, type, mex);
    if (type == 0)
    {
        if (s[idx] == 'M')
        {
            ans += f(idx + 1, type + 1, mex | pw(2, (v[idx])));
        }
    }
    else if (type == 1)
    {
        if (s[idx] == 'E')
        {
            ans += f(idx + 1, type + 1, mex | pw(2,(v[idx])));
        }
    }
    else
    {
        if (s[idx] == 'X')
        {
            ans += f(idx + 1, type + 1, mex | pw(2,(v[idx])));
        }
    }
    return dp[idx][type][mex] = ans;
}
void solve()
{
    cin >> n;
    v.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> s;
    memset(dp, -1, sizeof(dp));
    ll ans = f(0, 0, 0);
    cout << ans;
}

int main()
{
    fastio();
    ll t = 1;
    // ix();
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
