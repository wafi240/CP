// wafi the laura — farming aura
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
// #include "debug.hpp"
#else
#define debug(...)
#define error(...)
#endif
#define ll long long
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

#define tt    \
    ll t;     \
    cin >> t; \
    while (t--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())

vector<ll> func(ll n)
{
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i <= 26)
                divs.pb(i);
            if (i != n / i && n / i <= 26)
                divs.pb(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

ll cost(map<ll, ll> &mp, ll k, ll n)
{
    ll x = n / k;

    vector<ll> freq;

    for (auto &[c, f] : mp)
        freq.pb(min(f, x));

    sort(freq.rbegin(), freq.rend());

    ll keep = 0;
    for (ll i = 0; i < k && i < (ll)freq.size(); i++)
        keep += freq[i];

    return n - keep;
}

int main()
{
    fast tt
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        vector<ll> divs = func(n);

        map<ll, ll> mp;
        map<ll, vector<ll>> adj;

        for (ll i = 0; i < n; i++)
        {
            mp[s[i] - 'a']++;
            adj[s[i] - 'a'].pb(i);
        }

        ll best_k = divs[0], best_cost = LLONG_MAX;
        for (ll k : divs)
        {
            ll c = cost(mp, k, n);
            if (c < best_cost)
            {
                best_cost = c;
                best_k = k;
            }
        }

        ll k = best_k;
        ll x = n / k;

        vector<pair<ll, ll>> char_v;
        for (auto &[c, f] : mp)
            char_v.pb({f, c});

        sortv(char_v);
        reverse(char_v.begin(), char_v.end());

        set<ll> st;
        for (ll i = 0; i < k && i < (ll)char_v.size(); i++)
            st.insert(char_v[i].second);

        vector<ll> buffer;

        for (ll c = 0; c < 26; c++)
        {
            if (st.count(c) == 0 && adj.count(c))
            {
                for (ll pos : adj[c])
                    buffer.pb(pos);
                adj[c].clear();
            }
        }

        for (ll c : st)
        {
            while ((ll)adj[c].size() > x)
            {
                buffer.pb(adj[c].back());
                adj[c].pop_back();
            }
        }

        for (ll c : st)
        {
            while ((ll)adj[c].size() < x)
            {
                adj[c].pb(buffer.back());
                buffer.pop_back();
            }
        }

        if (!buffer.empty())
        {
            for (ll i = 0; i < 26; i++)
            {
                if (buffer.empty())
                    break;

                if (st.count(i) == 0 && mp.count(i) == 0)
                {
                    while ((ll)adj[i].size() < x && !buffer.empty())
                    {
                        adj[i].pb(buffer.back());
                        buffer.pop_back();
                    }
                    st.insert(i);
                }
            }
        }

        string ans(n, '#');
        for (ll c : st)
        {
            for (ll pos : adj[c])
                ans[pos] = c + 'a';
        }

        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] != ans[i])
                count++;
        }
        cout << count << "\n"
             << ans << "\n";
    }
    return 0;
}