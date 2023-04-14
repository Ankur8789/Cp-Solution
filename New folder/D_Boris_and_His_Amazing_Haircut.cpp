#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int N, idx;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
typedef long long ll;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SORT(A) sort(A.begin(), A.end());
#define REVERSE(A) reverse(A.begin(), A.end());
#define srt(A, n) sort(A, A + n);
const ll M = 1e9 + 7;
const ll M_ = 1e7 + 10;
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
vector<bool> soe(90000001, 1);
void sieve()
{
    for (int i = 2; i * i <= 90000001; i++)
    {
        if (soe[i] == true)
        {
            for (int j = i * i; j <= 90000001; j += i)
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
ll mpw(ll base, ll exp, ll mod)
{ // O(LOGEXP) TIME
    if (exp == 0)
        return 1;
    ll res = mpw(base, exp / 2, mod);
    if (exp % 2 == 1)
        return (((res * res) % mod) * base) % mod;
    else
        return (res * res) % mod;
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
        F[i] = (F[i - 1] * 1LL * i) % M;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    unordered_map<ll, ll> mp;
    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        mp[x]++;
    }
    // if (a == b)
    // {
    //     cout << "YES" << endl;
    //     return;
    // }
    for (ll i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            cout << "NO" << endl;
            return;
        }
    }

    stack<ll> st;
    for (ll i = 0; i < n; i++)
    {
        while (st.size() > 0 && st.top() < b[i])
            st.pop();
        if (b[i] == a[i])
            continue;
        if (st.size() > 0 && st.top() == b[i])
            continue;
        else
        {
            if (mp.find(b[i]) == mp.end())
            {
                cout << "NO" << endl;
                return;
            }
            else
            {
                st.push(b[i]);
                mp[b[i]]--;
                if (mp[b[i]] == 0)
                    mp.erase(b[i]);
            }
        }
    }
    cout << "YES" << endl;
}

int main()
{  fastio();
    ll t = 1;
    // ix();
    cin >> t;
    while (t--)
    {
        solve();
    }
}
