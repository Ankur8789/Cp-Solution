#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int N, idx;
tree<int, null_type, less<int>, rb_tree_tag,
     tree_order_statistics_node_update>
    T;
typedef long long ll;
const ll M = 1e9 + 7;
const ll M_ = 1e7 + 10;
// binary search on real number l=mid||r=mid
// Oredered set functions
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)
//************PRIME CHECK*************
bool isprime(int n)
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
vector<pair<ll, ll>> primefact(ll n)
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
int power(int a, int n)
{
    int res = 1;
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
//**************TRIE************|


int main()
{
    // vector<vector<int> > v;
    int tree_pref[1001][1001];
    int forest[1001][1001];
    int N;
    int Q;
    cin >> N >> Q;
    // read in the initial trees
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            char a;
            cin >> a;
            if (a == '*')
                forest[i][j] = 1;
            else
                forest[i][j] = 0;
        }
    }

    // build the prefix sum array
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            tree_pref[i][j] = forest[i][j] + tree_pref[i - 1][j] + tree_pref[i][j - 1] - tree_pref[i - 1][j - 1];
        }
    }

    while (Q--)
    {
        int from_row, to_row, from_col, to_col;
        cin >> from_row >> from_col >> to_row >> to_col;
        cout << tree_pref[to_row][to_col] - tree_pref[from_row - 1][to_col] - tree_pref[to_row][from_col - 1] + tree_pref[from_row - 1][from_col - 1] << '\n';
    }
    return 0;
}
