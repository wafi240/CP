// wafi is too lazy to code
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
    ll t;     \
    cin >> t; \
    while (t--)
#define rep1(a, n) for (int i = a; i < (n); ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(a, m) for (int j = a; j < (m); ++j)
int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);
    tt()
    {
        ll n;
        cin >> n;
        ll diff0 = 0;
        ll diff1 = 0;
        ll count = 0;
        vector<pair<ll, ll>> v1(n);
        vector<pair<ll, ll>> v2(n);
        for (ll i = 0; i < n; i++)
        {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            v1.push_back({a, b});
            v2.push_back({c, d});
            if (a > c)
            {
                diff0 = a - c;
            }
            else
            {
                diff0 = 0;
            }
            if (b > d)
            {
                diff1 = b - d;
            }
            else
            {
                diff1 = 0;
            }
            count += (diff0);
            if (diff1 > 0)
            {
                count += (diff1 + a - diff0);
            }
            // cout << count << endl;
        }
        for (ll i = 0; i < n; i++)
        {

            ll a = v1[i].first;
            ll c = v2[i].first;
            ll b = v1[i].second;
            ll d = v2[i].second;
            if (a > c)
            {
                diff0 = a - c;
            }
            else
            {
                diff0 = 0;
            }
            if (b > d)
            {
                diff1 = b - d;
            }
            else
            {
                diff1 = 0;
            }
            count += (diff0);
            if (diff1 > 0)
            {
                count += (diff1 + a - diff0);
            }
        }

        // nl;
        cout << count << endl;
    }

    return 0;
}