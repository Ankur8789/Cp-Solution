#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>T;
typedef long long ll;
 #define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
 #define SORT(A) sort(A.begin(), A.end());
 #define REVERSE(A) reverse(A.begin(), A.end());
 #define srt(A,n) sort(A,A+n);
 #define ln "\n"
const ll M = 1e9 + 7;
const ll M_ = 1e7 + 10;
typedef priority_queue<int> pq1;
typedef priority_queue<int,vector<int>,greater<int> > pq2;
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
vector<pair<ll, ll> > pf(ll n)
{
    vector<pair<ll, ll> > ans;
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
ll mpw(ll base, ll exp,ll mod)
{ // O(LOGEXP) TIME
    if (exp == 0)
        return 1;
    ll res = mpw(base, exp / 2,mod);
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
	F[0]=F[1]=1;
	for(ll i=2;i<=1000000;i++)
	F[i]=(F[i-1]*1LL*i)%M;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(ll i=0;i<n;i++)cin>>v[i];
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(st.size()==0)
        st.push(v[i]);
        else
        {
            if(v[i]==1 && st.top()==0)
            {
                st.pop();
                st.push(2);
            }
            else if(v[i]==2 && st.top()==1)
            {
                st.pop();
                st.push(3);
            }
            else if(v[i]==3 && st.top()==2)
            {
                st.pop();
                st.push(4);
            }
            else if(v[i]==4 && st.top()==3)
            {
                st.pop();
                st.push(5);
            }
            else if(v[i]==5 && st.top()==4)
            {
                st.pop();
                st.push(6);
            }
            else if(v[i]==6 && st.top()==5)
            {
                st.pop();
                st.push(7);
            }
            else if(v[i]==7 && st.top()==6)
            {
                st.pop();
                st.push(8);
            }
            else if(v[i]==8 && st.top()==7)
            {
                st.pop();
                st.push(9);
            }
            else if(v[i]==9 && st.top()==8)
            {
                st.pop();
                st.push(0);
            }
            else if(v[i]==0 && st.top()==9)
            {
                st.pop();
                st.push(1);
            }
            else
            {
                st.push(v[i]);
            }
        }
    }
    vector<int> ans;
    while(st.size()>0)
    {
        ans.push_back(st.top());
        st.pop();
    }
    REVERSE(ans);
    for(auto t: ans)cout<<t;
    cout<<ln;
    	
}

int main()
{  
  fastio();
    ll t = 1;
    // ix();
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
   

}


