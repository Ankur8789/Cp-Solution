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

#define c 'd'
// const int c = 11

void solve()
{
    int cc = 0;
    for (int i = 100; i <= 200; i++)
    {
        bool t = false;
        for (int j = 2; j <= 8; j++)
        {
            if (i % j == 0)
                t = true;
        }
        if (i % 12 == 0 || i % 14 == 0)
            t = true;
        if (!t)
            cc++;
    }
    cout << cc;
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
class DSU
{
public:
    vector<int> parent;
    vector<int> rank;
    int components;

    DSU(int n)
    {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        rank.resize(n + 1);
        components = n;
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return findParent(parent[node]);
    }

    void unionByRank(int node1, int node2)
    {
        int p1 = findParent(node1);
        int p2 = findParent(node2);

        if (p1 == p2)
        {
            return;
        }
        if (rank[p1] > rank[p2])
        {
            parent[p2] = p1;
        }
        else if (rank[p2] > rank[p1])
        {
            parent[p1] = p2;
        }
        else
        {
            parent[p1] = p2;
            rank[p2]++;
        }
        components--;
    }

    bool isSingle()
    {
        return components == 1;
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {

        DSU Alice(n);
        DSU Bob(n);

        auto lambda = [](vector<int> &a, vector<int> &b)
        {
            return a[0] > b[0];
        };
        sort(edges.begin(), edges.end(), lambda);

        int edge = 0;
        for (auto &ed : edges)
        {
            int type = ed[0];
            int u = ed[1];
            int v = ed[2];

            if (type == 3)
            {
                bool edgeAdded = false;
                if (Alice.findParent(u) != Alice.findParent(v))
                {
                    Alice.unionByRank(u, v);
                    edgeAdded = true;
                }
                if (Bob.findParent(u) != Bob.findParent(v))
                {
                    Bob.unionByRank(u, v);
                    edgeAdded = true;
                }
                if (edgeAdded == true)
                {
                    edge++;
                }
            }
            else if (type == 2)
            {
                if (Bob.findParent(u) != Bob.findParent(v))
                {
                    Bob.unionByRank(u, v);
                    edge++;
                }
            }
            else
            {
                if (Alice.findParent(u) != Alice.findParent(v))
                {
                    Alice.unionByRank(u, v);
                    edge++;
                }
            }
        }
        if (Alice.isSingle() == true and Bob.isSingle() == true)
        {
            return edges.size() - edge;
        }
        return -1;
    }
};
