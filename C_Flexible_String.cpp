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
    fast tt
    {
        ll n, k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;
        vector<ll> vis(26, 0);
        vector<ll> dis;
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {
                if (vis[s[i] - 'a'] == 0)
                {
                    dis.pb(s[i] - 'a');
                    vis[s[i] - 'a']++;
                    cnt++;
                }
            }
        }
        if (cnt <= k)
        {
            cout << (n * (n + 1)) / 2 << endl;
            continue;
        }
        ll mx = 1 << dis.size();
        ll ans = 0;

        for (ll mask = 0; mask < mx; mask++)
        {
            ll c = __builtin_popcountll(mask);
            if (c > k)
                continue;
            vector<ll> temp(26, 0);

            for (ll j = 0; j < dis.size(); j++)
            {
                if (mask & (1 << j))
                {
                    temp[dis[j]] = 1;

                }
            }
            ll len = 0, tot = 0;
            for (ll i1 = 0; i1 < n; i1++)
            {
                if (temp[s[i1] - 'a'] == 1 || s[i1] == t[i1])
                {
                    len++;
                }
                else
                {
                    tot += (len * (len + 1)) / 2;
                    len = 0;
                }
            }
            tot += (len * (len + 1)) / 2;
            ans = max(ans, tot);
        }
        cout << ans << endl;
    }
    return 0;
}