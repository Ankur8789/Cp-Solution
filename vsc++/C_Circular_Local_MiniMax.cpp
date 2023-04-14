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
const ll modx = 1e7 + 10;
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
ll F[1000001];
void ix()
{
    F[0] = F[1] = 1;
    for (ll i = 2; i <= 1000000; i++)
        F[i] = (F[i - 1] * 1LL * i) % mod;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    if (n % 2 != 0)
    {
        cout << "NO" << ln;
        return;
    }
    vector<ll> ev(n / 2);
    vector<ll> od(n / 2);
    SORT(v);
    for (ll i = 0; i < n / 2; i++)
        ev[i] = v[i];
    for (ll i = n / 2; i < n; i++)
        od[i - (n / 2)] = v[i];
    vector<ll> ans;
    for (ll i = 0; i < n / 2; i++)
    {
        ans.push_back(ev[i]);
        ans.push_back(od[i]);
    }
    for (ll i = 1; i < n - 1; i++)
    {
        if (ans[i] > ans[i + 1] && ans[i] > ans[i - 1])
            continue;
        if (ans[i] < ans[i + 1] && ans[i] < ans[i - 1])
            continue;
        cout << "NO" << ln;
        return;
    }
    cout << "YES" << ln;
    for (auto t : ans)
        cout << t << " ";
    cout << ln;
}

int main()
{
    fastio();
    ll t = 1;
    // ix();
    cin >> t;
    while (t--)
    {
        solve();
    }
}
