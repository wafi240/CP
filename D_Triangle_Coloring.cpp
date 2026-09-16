// wafi the laura — farming aura
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#define error(...)
#endif
#define ll long long
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
const ll mod = 998244353;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ot(x) cout << x << '\n'
#define tt    \
    ll t;     \
    cin >> t; \
    while (t--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortrv(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define all(x) x.begin(), x.end()
#define setbit(x, i) ((x) | (1LL << (i)))
#define checkbit(x, i) ((x) & (1LL << (i)))
#define togglebit(x, i) ((x) ^ (1LL << (i)))
void in() {}
template <typename T, typename... Args>
void in(T &first, Args &...rest)
{
    cin >> first;
    in(rest...);
}
ll adds(ll a, ll b) { return (a + b) % mod; }
ll subs(ll a, ll b) { return (a - b + mod) % mod; }
ll muls(ll a, ll b) { return (a * b) % mod; }
ll binexp(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = muls(res, a);
        a = muls(a, a);
        b >>= 1;
    }
    return res;
}
ll inv(ll a) { return binexp(a, mod - 2); }
ll divs(ll a, ll b) { return muls(a, inv(b)); }
class ST
{
private:
    vector<ll> tree;
    ll size;
public:
    ST(ll n)
    {
        size = n;
        tree.resize(4 * n, 0);
    }
    void build(ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node] = 0;
            return;
        }
        ll mid = (start + end) / 2;
        ll leftchild = 2 * node;
        ll rightchild = 2 * node + 1;
        build(leftchild, start, mid);
        build(rightchild, mid + 1, end);
        tree[node] = tree[leftchild] + tree[rightchild];
    }
    void update(ll node, ll start, ll end, ll indx, ll value)
    {
        if (indx < start || indx > end) return;
        if (start == end)
        {
            tree[node] = value;
            return;
        }
        ll mid = (start + end) / 2;
        ll leftchild = 2 * node;
        ll rightchild = 2 * node + 1;
        update(leftchild, start, mid, indx, value);
        update(rightchild, mid + 1, end, indx, value);
        tree[node] = tree[leftchild] + tree[rightchild];
    }
    ll query(ll node, ll start, ll end, ll l, ll r)
    {
        if (l > end || r < start) return 0;
        if (start >= l && end <= r) return tree[node];
        ll mid = (start + end) / 2;
        ll leftchild = 2 * node;
        ll rightchild = 2 * node + 1;
        return query(leftchild, start, mid, l, r) + query(rightchild, mid + 1, end, l, r);
    }
};

ll func(ll x,ll y, ll z)
{
    ll count=0;
    
    vector<ll>sd;
    sd.pb(x);
    sd.pb(y);
    sd.pb(z);
    sortv(sd);
    if(x==y && y==z)
    {
        return 3;
    }
    if( (sd[0]==sd[1]) )
    {
        return 2;
    }

    return 1;
}
ll comb(ll N_, ll C_) {
    const ll NUM_ = 400001;
    static ll fact[400002], factr[400002], inv[400002];
    if (fact[0] == 0) {
        inv[1] = fact[0] = factr[0] = 1;
        for (ll i = 2; i <= NUM_; ++i)
            inv[i] = inv[mod % i] * (mod - mod / i) % mod;
        for (ll i = 1; i <= NUM_; ++i) {
            fact[i] = fact[i - 1] * i % mod;
            factr[i] = factr[i - 1] * inv[i] % mod;
        }
    }
    if (C_ < 0 || C_ > N_) return 0;
    return factr[C_] * fact[N_] % mod * factr[N_ - C_] % mod;
}
int main()
{
    fast
    ll n;cin>>n;
    vector<ll>v(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    ll x=1;
    for (ll i = 0; i < n; i+=3)
    {
         ll d=func(v[i],v[i+1],v[i+2]);
         x=muls(x,d);
        //  cout<<x<<" ";
    }
    // cout<<endl;
    ll div=n/3;
// cout<<comb(div,div/2)<<" "<<x<<endl;
    ll ans=comb(div,div/2);
    ans=muls(ans,x);
    cout<<ans<<endl;

    
    
    return 0;
}