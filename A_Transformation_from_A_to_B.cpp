
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define ll long long
const long long mod = 1e9 + 7;
#define YES puts("YES")
#define NO puts("NO")
#define in(x) cin >> x
#define in2(x, y) cin >> x >> y;
#define in3(x, y, z) cin >> x >> y >> z;
#define ot(x) cout << x << " ";
#define out(x) cout << x << endl;
#define nl cout << endl;
#define vi(n) vector<int> v(n);
#define vi1(n) vector<int> v1(n);
#define vl(n) vector<ll> v(n);
#define vl1(n) vector<ll> v1(n);
#define tt()  \
    int t;    \
    cin >> t; \
    while (t--)
#define rep1(a, n) for (int i = a; i < (n); ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(a, m) for (int j = a; j < (m); ++j)
map<ll, vector<ll>> adj;
map<ll, ll> visited;
vector<ll> v;
ll addOneToEnd( ll num)
{
    // Convert number to string
    string numStr = to_string(num);

    // Add "1" at the end
    numStr += "1";

    // Convert back to long long
    return stoll(numStr);
}

bool dfs(ll node, ll k)
{

    if (node > k)
    {
        return false;
    }
    if (node == k)
    {

        v.push_back(k);
        return true;
    }
    visited[node] = 1;
    for (ll ele : adj[node])
    {
        if (!visited[ele])
        {
            if (dfs(ele, k))
            {
                v.push_back(node);
                return true;
            }
        }
    }

    return false;
}

int main()
{

    ll n, k;
    cin >> n >> k;
    ll i = 0;
    v.clear();
    adj.clear();
    visited.clear();
    vector<ll> p;

    set<ll> dupli;
    p.push_back(n);
    dupli.insert(n);
    while (i < p.size())
    {

        ll n1 = p[i] * 2;
        ll n2 = addOneToEnd(p[i]);
        if (n1 <= k && dupli.find(n1) == dupli.end())
        {
            p.push_back(n1);
            dupli.insert(n1);
            adj[p[i]].push_back(n1);
        }
        if (n2 <= k && dupli.find(n2) == dupli.end())
        {
            p.push_back(n2);
            dupli.insert(n2);
            adj[p[i]].push_back(n2);
        }
        i++;
    }

    if (dfs(n, k) == false)
    {
        NO;
    }
    else
    {
        YES;
        sort(v.begin(), v.end());
        cout << v.size() << endl;
        for (ll i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        nl;
    }

    return 0;
}
