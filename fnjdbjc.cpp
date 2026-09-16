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

int main()
{
    fast
        ll n,
        a, b;
    cin >> n >> a >> b;

    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll x1;
        cin >> x1;
        mp[x1] = i + 1;
    }

    ll c = 0;

    ll ans = LLONG_MAX;
    ll i = 0;
    ll y = n - 1 - i;
    // cout << y << " ";
    y += n - mp[v[i]];
    // cout << y << " ";
    ll x = 0;
    // cout << x << " "<<n<<" "<<mp[v[i]]<<" "<<c<<endl;
    x += (mp[v[i]] - c - 1);
    // cout << x << " ";
    ll ans2 = max(y * b, x * a);
    ans = ans2;
    i++;
    c = 1;
    for (; i < n; i++)
    {

        ll u2 = v[i];
        ll u1 = v[i - 1];
        y = n - 1 - i;
        // cout << y << " ";
        y += n - mp[v[i]];
        // cout << y << " ";
        x = i;
        // cout << x << " ";
        x += mp[v[i]] - 1;
        // cout << x << " ";
        ans2 = max(y * b, x * a);
        ans = min(ans, ans2);
        // cout << endl;

        if (mp[u2] - mp[u1] == 1)
        {
            c++;
        }
        else
        {
            c = 1;
        }
        // cout << c << endl;
        y = n - 1 - i;
        // cout << y << " ";
        y += n - mp[v[i]];
        // cout << y << " ";
        x = i + 1 - c;
        // cout << x << " ";
        x += mp[v[i]] - c;
        // cout << x << " ";
        ans2 = max(y * b, x * a);
        // cout << endl;
        // cout << endl;
        ans = min(ans, ans2);
    }
if(c!=1)
{    // cout << c << endl;
    y = n - 1 - i;
    // cout << y << " ";
    y += n - mp[v[i]];
    // cout << y << " ";
    x = i + 1 - c;
    // cout << x << " ";
    x += mp[v[i]] - c;
    // cout << x << " ";
    ans2 = max(y * b, x * a);
    // cout << endl;
    // cout << endl;
    ans = min(ans, ans2);
}    
    cout << ans<< endl;

    return 0;
}