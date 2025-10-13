#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tt()  \
    int t;    \
    cin >> t; \
    while (t--)

vector<vector<ll>> adj;
vector<ll> visited;
vector<ll> v; // stores values from dfs
map<pair<ll, ll>, pair<ll, ll>> mp;

void dfs(ll pre, ll curr) {
    visited[curr] = 1;

    if (pre == -1) {
        v[curr] = 0; // root
    } else {
        auto it = mp.find({min(pre, curr), max(pre, curr)});
        if (it != mp.end()) {
            ll x = it->second.first;
            ll y = it->second.second;
            if (x > y) {
                v[curr] = v[pre] + 1;
            } else {
                v[curr] = v[pre] - 1;
            }
        }
    }

    for (ll u : adj[curr]) {
        if (!visited[u]) {
            dfs(curr, u);
        }
    }
}

int main() {
    tt() {
        ll n;
        cin >> n;
        adj.assign(n + 1, {});
        visited.assign(n + 1, 0);
        v.assign(n + 1, 0);
        mp.clear();

        for (ll i = 0; i < n - 1; i++) {
            ll a, b, x, y;
            cin >> a >> b >> x >> y;
            adj[a].push_back(b);
            adj[b].push_back(a);
            mp[{min(a, b), max(a, b)}] = {x, y};
        }

        dfs(-1, 1); // root = 1

        // Normalize v to get a permutation
        vector<pair<ll, ll>> nodes;
        for (ll i = 1; i <= n; i++) {
            nodes.push_back({v[i], i});
        }

        // Sort by v-value
        sort(nodes.begin(), nodes.end());

        // Assign ranks 1 to n
        vector<ll> permu(n + 1);
        for (ll i = 0; i < n; i++) {
            permu[nodes[i].second] = i + 1;
        }

        // Output the permutation
        for (ll i = 1; i <= n; i++) {
            cout << permu[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}