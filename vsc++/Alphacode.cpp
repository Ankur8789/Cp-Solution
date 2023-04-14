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
#define SORT(A) sort(A.begin(), A.end());
#define REVERSE(A) reverse(A.begin(), A.end());
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
//**************TRIE**************
struct Node
{
    Node *links[26];
    bool flag = false;
    // checks if the reference trie is present or not
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    // creating reference trie
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    // to get the next node for traversal
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    // setting flag to true at the end of the word
    void setEnd()
    {
        flag = true;
    }
    // checking if the word is completed or not
    bool isEnd()
    {
        return flag;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        // creating new obejct
        root = new Node();
    }

    void insert(string word)
    {
        // initializing dummy node pointing to root initially
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // moves to reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
//***********pop_count*******
ll popcount(ll n)
{
    ll c = 0;
    for (; n; ++c)
        n &= n - 1;
    return c;
}
///*********ncr*********
//  const int N = 1e6 + 100;
//  long long fact[N];
//  initialise the factorial
//  void initfact()
//  {
//  fact[0] = 1;
//    for (int i = 1; i < N; i++)
//    {
//        fact[i] = (fact[i - 1] * i);
//        fact[i] %= MOD;
//    }

//  }
// // modular exponentiation
// long long modpow(long long x, long long n, long long p)
// {

//     if (n == 0)
//         return 1 % p;

//     ll ans = 1, base = x;
//     while (n > 0)
//     {
//         if (n % 2 == 1)
//         {
//             ans = (ans * base) % p;
//             n--;
//         }
//         else
//         {
//             base = (base * base) % p;
//             n /= 2;
//         }
//     }
//     if (ans < 0)
//         ans = (ans + p) % p;
//     return ans;
// }

// // formula for c
//  ll C(ll n, ll i)
// {
//  ll res = fact[n];
//  ll div = fact[n - i] * fact[i];
//  div %= M;
//  div = modpow(div, MOD - 2, MOD);
//  return (res * div) % MOD;
//  }
ll dp[5001];
ll f(string &s, ll i)
{
    if (i == s.length())
        return 1;
    if (dp[i] != -1)
        return dp[i];
    ll ans = 0;
    if (s[i] >= '1')
        ans += f(s, i + 1);
    if (i < s.length() && s[i] == '1')
        ans += f(s, i + 2);
    if (i < s.length() && s[i] == '2' && s[i + 1] <= '6')
        ans += f(s, i + 2);
    return dp[i] = ans;
}
int main()
{
    while (1)
    {
        memset(dp, -1, sizeof(dp));
        string s;
        cin >> s;
        if (s == "0")
            break;
        ll x = f(s, 0);
        cout << x << endl;
    }
}
