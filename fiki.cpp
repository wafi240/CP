#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g; // Graph adjacency list
vector<bool> vis;      // Visited nodes

void dfs(int u)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // Initialize vectors with size n
    g.resize(n);
    vis.resize(n, false);

    // Read existing roads (using 0-based indexing)
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--; // Convert to 0-based
        v--; // Convert to 0-based
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> components;

    // Find all connected components
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            components.push_back(i);
            dfs(i);
        }
    }

    // Output number of new roads needed
    cout << components.size() - 1 << "\n";

    // Suggest new roads (convert back to 1-based for output)
    for (int i = 0; i < components.size() - 1; ++i)
    {
        cout << components[i] + 1 << " " << components[i + 1] + 1 << "\n";
    }

    return 0;
}