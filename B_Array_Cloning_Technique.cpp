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
        ll n;
        cin >> n;
        unordered_map<ll, ll> mp(0);

        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            mp[x]++;
        }
        if (mp.size() == 1)
        {
            cout << 0 << endl;
            continue;
        }
        ll mxcnt = 0;
        ll count = 0;
        auto it = mp.begin();
        while (it != mp.end())
        {
            if (it->second > mxcnt)
            {
                mxcnt = it->second;
            }
            it++;
        }

        ll f = mxcnt;
        ll l = n - mxcnt;
        ll t = 0;
        while (f < n)
        {
            t++;
            l = n - f;
            t += min(f, l);
            f = f * 2;
        }
        cout << t << endl;
    }

    return 0;
}
