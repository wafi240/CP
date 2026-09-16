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
const ll mod = 1e9 + 7;
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
        if (indx < start || indx > end)
            return;
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
        if (l > end || r < start)
            return 0;
        if (start >= l && end <= r)
            return tree[node];
        ll mid = (start + end) / 2;
        ll leftchild = 2 * node;
        ll rightchild = 2 * node + 1;
        return query(leftchild, start, mid, l, r) + query(rightchild, mid + 1, end, l, r);
    }
};
struct RollingHash
{
    static const ll mod1 = 1000000007LL;
    static const ll mod2 = 1000000009LL;
    static const ll base = 32LL;
    vector<ll> pref1, pref2;
    vector<ll> power1, power2;
    RollingHash(const string &s)
    {
        ll n = s.size();
        pref1.assign(n + 1, 0);
        pref2.assign(n + 1, 0);
        power1.assign(n + 1, 1);
        power2.assign(n + 1, 1);
        for (ll i = 0; i < n; i++)
        {
            ll val = s[i] - 'a' + 1;
            power1[i + 1] = (power1[i] * base) % mod1;
            power2[i + 1] = (power2[i] * base) % mod2;
            pref1[i + 1] = (pref1[i] * base + val) % mod1;
            pref2[i + 1] = (pref2[i] * base + val) % mod2;
        }
    }
    pair<ll, ll> get (ll l, ll r)
    {
        ll x1 = pref1[r + 1] - (pref1[l] * power1[r - l + 1]) % mod1;
        ll x2 = pref2[r + 1] - (pref2[l] * power2[r - l + 1]) % mod2;
        if (x1 < 0)
            x1 += mod1;
        if (x2 < 0)
            x2 += mod2;
        return {x1, x2};
    }
};
int main()
{
    fast

        string s1,
        s2;
    cin >> s1 >> s2;
    ll n = s1.size();
    ll m = s2.size();
    if (m > n)
    {
        cout << 0 << endl;
        return 0;
    }
    RollingHash hs(s1), hp(s2);
    auto it = hp.get(0, m - 1);
    ll ans = 0;
    for (ll i = 0; i + m <= n; i++)
    {
        if (hs.get(i, i + m - 1) == it)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}