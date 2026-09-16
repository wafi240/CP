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

int main()
{
    fast;
    ll n, s;
    cin >> n >> s;

    if (s == 0)
    {
        if (n == 1)
            cout << 0 << " " << 0 << endl;
        else
            cout << -1 << " " << -1 << endl;
        return 0;
    }

    vector<vector<ll>> dp(s + 1, vector<ll>(n + 1, 0));
    dp[0][0] = 1;

    for (ll j = 1; j <= n; j++)
    {
        for (ll i = 0; i <= s; i++)
        {
            for (ll k = 0; k <= 9; k++)
            {
                if (i - k >= 0 && dp[i - k][j - 1])
                {
                    dp[i][j] = 1;
                }
            }
        }
    }

    if (dp[s][n] == 0)
    {
        cout << -1 << " " << -1 << "\n";
        return 0;
    }

    vector<vector<ll>> vs;
    vector<ll> rem;

    for (ll j = 1; j <= 9; j++)
    {
        if (s - j >= 0 && dp[s - j][n - 1] == 1)
        {
            vs.push_back({j});
            rem.push_back(s - j);
        }
    }

    for (ll ij = 0; ij < (ll)vs.size(); ij++)
    {
        for (ll i = n - 1; i >= 1; i--)
        {
            for (ll j = 0; j <= 9; j++)
            {
                if (rem[ij] - j >= 0 && dp[rem[ij] - j][i - 1] == 1)
                {
                    vs[ij].pb(j);
                    rem[ij] -= j;
                    break;
                }
            }
        }
    }

    vector<string> pl;
    for (ll ij = 0; ij < (ll)vs.size(); ij++)
    {
        string st = "";
        for (ll i = 0; i < (ll)vs[ij].size(); i++)
        {
            st += to_string(vs[ij][i]);
        }
        pl.pb(st);
    }

    sort(all(pl));
    string mn = pl.front();


    string mx = "";

    for (ll i = n; i >= 1; i--)
    {
        for (ll j = 9; j >= (i == n ? 1 : 0); j--)
        {
            if (s - j >= 0 && dp[s - j][i - 1] == 1)
            {
                mx += to_string(j);
                s -= j;
                break;
            }
        }
    }

    cout << mn << " " << mx << endl;

    return 0;
}