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
    int t;    \
    cin >> t; \
    while (t--)
#define rep1(a, n) for (int i = a; i < (n); ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(a, m) for (int j = a; j < (m); ++j)
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    bool second = false;
    ll pod = 0;
    vector<bool> b(n, true);
    while (k--)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll i, x2;
            cin >> i >> x2;
            ll x1 = v[i - 1];
            if (b[i - 1] == false)
            {
                x1 = pod;
            }
            ll diff = (x2 - x1);

            sum += diff;
            
            b[i - 1] = true;
            v[i - 1] = x2;
            cout << sum << endl;
        }
        else
        {
            fill(b.begin(), b.end(), false); // Reset b flags
            ll x3;
            cin >> x3;
            pod = x3;
            sum = (long long)(x3)*n;
            cout << sum << endl;
        }
    }

    return 0;
}