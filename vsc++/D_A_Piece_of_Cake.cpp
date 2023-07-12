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

void solve()
{

    ll w, h;
    cin >> w >> h;
    ll n;
    cin >> n;
    // dbg;
    vector<pair<ll, ll>> vp;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        vp.push_back({x, y});
    }

    ll nx;
    cin >> nx;
    vector<ll> xaxis(nx);
    for (ll i = 0; i < nx; i++)
        cin >> xaxis[i];
    xaxis.push_back(w);
    // for(auto t: xaxis)cout<<t<<" ";
    ll ny;
    cin >> ny;
    vector<ll> yaxis(ny);
    for (ll i = 0; i < ny; i++)
        cin >> yaxis[i];
    yaxis.push_back(h);

    map<pair<pair<int, int>, pair<int, int>>, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll x1, x2;
        ll ans = -1;
        ll l = 0, r = nx - 1;
        // x kaha pe hoga
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (xaxis[mid] <= vp[i].first)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        x1 = xaxis[ans], x2 = xaxis[ans + 1];
        ll y1, y2;
        ans = -1;
        l = 0, r = ny - 1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (yaxis[mid] <= vp[i].second)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        y1 = yaxis[ans], y2 = yaxis[ans + 1];
        mp[{{x1, x2}, {y1, y2}}]++;
    }
    ll mn = INT_MAX, mx = 0;
    for (auto t : mp)
    {
        // cout << t.second << ln;
        mn = min(mn, t.second);
        mx = max(mx, t.second);
    }
    if (mp.size() != (nx + 1) * (ny + 1))
        mn = 0;
    cout << mn << " " << mx;
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