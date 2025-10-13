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

        ll pre = k;

        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<ll> pf(n + 1, 0);
        for (ll i = 1; i < n + 1; i++)
        {
            pf[i] = pf[i - 1] + v[i - 1];
        }
        ll j = -1;

        if (v[0] > k)
        {
            cout << 0 << endl;
            continue;
        }
        for (ll i = 0; i < n + 1; i++)
        {
            // cout<<pf[i]<<" ";
            if (pf[i] > k)
            {
                break;
            }
            j = i;
        }

        // cout << "j " << j << endl;
        // continue;
        ll count = 0;
        ll x = 0;
        while (j > 0)
        {

            ll diff = k - pf[j];
            // cout << pf[j] << " " << sum << endl;

            ll p = diff / j;
            p++;
            count += (j * (p - x));
            x += (p-x);
            j--;
            // cout << count <<" "<<x <<endl;
        }

        cout << count << endl;
    }
    return 0;
}