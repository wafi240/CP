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
#define ot(x) cout << x << endl
#define in(x) cin >> x
#define nl cout << '\n';
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
void in_variadic() {}
template <typename T, typename... Args>
void in_variadic(T &first, Args &...rest)
{
    cin >> first;
    in_variadic(rest...);
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

bool func(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return a.first < b.first;
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

// Template for ordered_set
template <typename T>
using ordered_multiset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
    fast

        ll n,
        q;
    cin >> n >> q;
    ll l1, l2;
    cin >> l1 >> l2;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<pair<ll, pair<ll, ll>>> Q(q);
    vector<pair<ll, ll>> L1;
    vector<pair<ll, ll>> L2;
    for (ll i = 0; i < q; i++)
    {
        cin >> Q[i].first >> Q[i].second.first >> Q[i].second.second;
        if (Q[i].first == 1)
        {
            L1.pb({Q[i].second.first, Q[i].second.second});
        }
        else
        {
            L2.pb({Q[i].second.first, Q[i].second.second});
        }
    }
    // about to get real
    sort(L1.begin(), L1.end(), func);
    sort(L2.begin(), L2.end(), func);

    ordered_multiset<ll> st;
    map<pair<ll, ll>, pair<ll, pair<ll, ll>>> mp1;

    ll curr = 0;
    if (!L1.empty())
    {
        curr = L1[0].first - 1;
        ll si = L1[0].first - 1;
        for (ll j = 0; j < l1; j++)
        {

            st.insert(v[j + si]);
        }
        ll k = L1[0].second;
        ll mn = *st.find_by_order(0);
        ll mx = *st.find_by_order(l1 - 1);
        ll kth = *st.find_by_order(k - 1);
        mp1[{L1[0].first, L1[0].second}] = {mn, {kth, mx}};
    }
    for (ll i = 1; i < L1.size(); i++)
    {
        ll si = L1[i].first - 1;

        ll k = L1[i].second;

        while (curr < si)
    {
        st.erase(st.find(v[curr]));
        curr++;
        st.insert(v[curr + l1 - 1]);  // নোট: l1-1 কারণ curr ইতিমধ্যে increment হয়েছে
    }

        ll mn = *st.find_by_order(0);
        ll mx = *st.find_by_order(l1 - 1);
        ll kth = *st.find_by_order(k - 1);
        mp1[{L1[i].first, L1[i].second}] = {mn, {kth, mx}};
    }

    ordered_multiset<ll> st2;
    map<pair<ll, ll>, pair<ll, pair<ll, ll>>> mp2;
    curr = 0;
    if (!L2.empty())
    {
        curr = L2[0].first - 1;
        ll si = L2[0].first - 1;
        ll k = L2[0].second;

        for (ll j = 0; j < l2; j++)
        {

            st2.insert(v[j + si]);
        }
        ll mn = *st2.find_by_order(0);
        ll mx = *st2.find_by_order(l2 - 1);
        ll kth = *st2.find_by_order(k - 1);
        mp2[{L2[0].first, L2[0].second}] = {mn, {kth, mx}};
    }
    for (ll i = 1; i < L2.size(); i++)
    {
        ll si = L2[i].first - 1;

        ll k = L2[i].second;

         while (curr < si)
    {
        st2.erase(st2.find(v[curr]));
        curr++;
        st2.insert(v[curr + l2 - 1]);  // নোট: l2-1 কারণ curr ইতিমধ্যে increment হয়েছে
    }

        ll mn = *st2.find_by_order(0);
        ll mx = *st2.find_by_order(l2 - 1);
        ll kth = *st2.find_by_order(k - 1);
        mp2[{L2[i].first, L2[i].second}] = {mn, {kth, mx}};
    }

    for (ll i = 0; i < q; i++)
    {

        if (Q[i].first == 1)
        {
            pair<ll, pair<ll, ll>> p = mp1[{Q[i].second.first, Q[i].second.second}];
            cout << p.first << " " << p.second.first << " " << p.second.second << endl;
        }
        else
        {
            pair<ll, pair<ll, ll>> p = mp2[{Q[i].second.first, Q[i].second.second}];
            cout << p.first << " " << p.second.first << " " << p.second.second << endl;
        }
    }

    return 0;
}