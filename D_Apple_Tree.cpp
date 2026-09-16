#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#define error(...)
#endif

#define ll long long
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);

#define tt ll t; cin >> t; while(t--)
#define pb push_back
#define ot(x) cout << x << '\n'

const int N = 2e5 + 5;

vector<ll> adj[N];
ll sub[N];


void dfs(ll u, ll p = -1)
{

    if (p != -1 && adj[u].size() == 1)
    {
        sub[u] = 1;
        return;
    }

    for (auto v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}

int main()
{
    fast

    tt
    {
        ll n;
        cin >> n;


        for (ll i = 1; i <= n; i++)
        {
            adj[i].clear();
            sub[i] = 0;
        }


        for (ll i = 1; i < n; i++)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }


        dfs(1);

        ll q;
        cin >> q;

        while (q--)
        {
            ll u, v;
            cin >> u >> v;

            ot(sub[u] * sub[v]);
        }
    }

    return 0;
}