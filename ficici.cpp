#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1e9 + 7;
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define YES puts("YES")
#define NO puts("NO")
#define in(x) cin >> x
#define in2(x, y) cin >> x >> y;
#define in3(x, y, z) cin >> x >> y >> z;
#define ot(x) cout << x << " ";
#define out(x) cout << x << endl;
#define nl cout << endl;
#define vi(n) vector<int> v(n);
#define vi1(n) vector<int> v(n);
#define vl(n) vector<ll> v(n);
#define vl1(n) vector<ll> v(n);
#define tt()  \
    int t;    \
    cin >> t; \
    while (t--)
#define rep1(a, n) for (int i = a; i < (n); ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(a, m) for (int j = a; j < (m); ++j)
int main()
{

    fast;
    tt()
    {
        ll n;
        cin >> n;
        vector<ll> v(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll mini = LLONG_MAX;
        vector<ll> p(n);
        vector<ll> s(n);
        for (ll i = 0; i < n; i++)
        {

            mini = min(mini, v[i]);
            if (v[i] == mini)
            {
                p[i] = 1;
            }
            else
            {
                p[i] = 0;
            }
        }
        // for (ll i = 0; i < n; i++)
        // {
        //     cout << p[i] << " ";
        // }
        // nl;
        ll maxi = LLONG_MIN;
        for (ll i = n - 1; i >= 0; i--)
        {
            maxi = max(maxi, v[i]);
            if (v[i] == maxi)
            {
                s[i] = 1;
            }
            else
            {
                s[i] = 0;
            }
        }
        // reverse(s.begin(), s.end());
        // for (ll i = 0; i < n; i++)
        // {
        //     cout << s[i] << " ";
        // }
        // nl;
        for (ll i = 0; i < n; i++)
        {
            if (p[i] == 1 || s[i] == 1)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        nl;
    }
    return 0;
}