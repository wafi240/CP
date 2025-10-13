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
int main()
{

    tt()
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<ll> p;
        p.push_back(1);
        for (ll i = 1; i < n; i++)
        {
            if (v[i] != v[i - 1])
            {
                p.push_back(i + 1);
            }
        }
        // p.push_back(n);
        // for (ll i = 0; i < p.size(); i++)
        // {
        //     cout << p[i] << " ";
        // }
        // nl;

        ll q;
        cin >> q;
        while (q--)
        {
            ll x, y;
            cin >> x >> y;
            auto e = upper_bound(p.begin(), p.end(), x);
            auto f = upper_bound(p.begin(), p.end(), y);
            ll ab = f - e;
            if (ab < 1)
            {
                cout << -1 << " " << -1 << endl;
                continue;
            }

            --e;

            ll ans1 = *e;
            e++;
            ll ans2 = *e;
            cout << max(x, ans1) << " " << min(y, ans2) << endl;
        }
        nl;
    }

    return 0;
}