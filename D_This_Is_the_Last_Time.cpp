#include <bits/stdc++.h>
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

int main()
{
    tt()
    {
        ll n, k;
        cin >> n >> k;
        vector<pair<ll, pair<ll, ll>>> v;
        for (ll i = 0; i < n; i++)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            v.emplace_back(x, make_pair(l, r));
        }
        vector<ll> v1;
        v1.push_back(k);
        sort(v.begin(), v.end());
        auto it = v.begin();
        ll maxi = -1;

        auto itt = lower_bound(v1.begin(), v1.end(), it->second.first);
        if (itt != v1.end() && *itt <= it->second.second && *itt >= it->second.first)
        {
            v1.push_back(it->first);
            maxi = max(maxi, it->first);
        }
        it++;

        while (it != v.end())
        {
            // Find first element in v1 >= interval end
            // sort(v1.begin(),v1.end());
             itt = lower_bound(v1.begin(), v1.end(), it->second.first);
            if (itt != v1.end() && *itt <= it->second.second && *itt >= it->second.first)
            {
                v1.push_back(it->first);
                maxi = max(maxi, it->first);
            }
            it++;
        }
        cout << max(maxi, k) << endl;
    }
    return 0;
}