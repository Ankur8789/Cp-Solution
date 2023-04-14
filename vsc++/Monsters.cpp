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
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define SORT(A) sort(A.begin(), A.end());
#define REVERSE(A) reverse(A.begin(), A.end());
#define srt(A, n) sort(A, A + n);
#define ln "\n"
const ll mod = 1e9 + 7;
const ll modx = 998244353;
typedef priority_queue<int> pq1;
typedef priority_queue<int, vector<int>, greater<int>> pq2;
// binary search on real number l=mid||r=mid
// Oredered set functions
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
{ // O(LOGEXP) TIME
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
//**********ncr**************
// ll F[1000001];
// void ix()
// {
//     F[0] = F[1] = 1;
//     for (ll i = 2; i <= 1000000; i++)
//         F[i] = (F[i - 1] * 1LL * i) % mod;
// }
///////
ll n, m;
string temp = "";
// bool possible;
bool p;
bool check(ll i, ll j, vector<vector<ll>> &vis, vector<string> &v)
{

    if (i < 0 || j < 0 || i >= m || j >= n)
        return false;
    if (vis[i][j] == 1)
        return false;
    if (v[i][j] != '.')
        return false;
    return true;
}

void f(ll i, ll j, vector<vector<ll>> &dis, vector<string> &v, string str, vector<vector<ll>> &ps, ll time)
{

    if (p)
        return;
    if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
    {
        temp = str;
        p = true;
        return;
    }
    ps[i][j] = 1;
    if (check(i + 1, j, ps, v))
    {
        if (time + 1 < dis[i + 1][j])
        {
            f(i + 1, j, dis, v, str + 'D', ps, time + 1);
        }
    }
    if (check(i - 1, j, ps, v))
    {
        if (time + 1 < dis[i - 1][j])
        {
            f(i - 1, j, dis, v, str + 'U', ps, time + 1);
        }
    }
    if (check(i, j + 1, ps, v))
    {
        if (time + 1 < dis[i][j + 1])
        {
            f(i, j + 1, dis, v, str + 'R', ps, time + 1);
        }
    }
    if (check(i, j - 1, ps, v))
    {
        if (time + 1 < dis[i][j - 1])
        {
            f(i, j - 1, dis, v, str + 'L', ps, time + 1);
        }
    }
    ps[i][j] = 0;
}

void solve()
{
    cin >> m >> n;
    vector<string> v;
    for (ll i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    p = false;
    queue<pair<ll, ll>> q;
    vector<vector<ll>> dis(m, vector<ll>(n, 1e10));
    vector<vector<ll>> vis(m, vector<ll>(n, 0));
    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (v[i][j] == 'M')
            {
                q.push({i, j});
                dis[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    // possible = false;
    while (q.size() > 0)
    {
        pair<ll, ll> p = q.front();
        q.pop();
        ll x = p.first;
        ll y = p.second;
        if (check(x + 1, y, vis, v))
        {
            vis[x + 1][y] = 1;
            q.push({x + 1, y});
            dis[x + 1][y] = dis[x][y] + 1;
        }
        if (check(x - 1, y, vis, v))
        {
            vis[x - 1][y] = 1;
            q.push({x - 1, y});
            dis[x - 1][y] = dis[x][y] + 1;
        }
        if (check(x, y + 1, vis, v))
        {
            vis[x][y + 1] = 1;
            q.push({x, y + 1});
            dis[x][y + 1] = dis[x][y] + 1;
        }
        if (check(x, y - 1, vis, v))
        {
            vis[x][y - 1] = 1;
            q.push({x, y - 1});
            dis[x][y - 1] = dis[x][y] + 1;
        }
    }
    ll idx = -1, idy = -1;
    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (v[i][j] == 'A')
            {
                idx = i;
                idy = j;
                break;
            }
        }
    }

    string str = "";
    vector<vector<ll>> ps(m, vector<ll>(n));
    f(idx, idy, dis, v, str, ps, 0);
    if (!p)
    {
        cout << "NO" << ln;
        return;
    }
    cout << "YES" << ln;
    cout << temp.size() << ln;
    cout << temp << ln;
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
