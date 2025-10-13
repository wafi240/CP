
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
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    fast;
    tt()
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        vector<ll> pf(n + 1, 0);
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
            pf[i + 1] = pf[i] + v[i];
        }

        ll maxi = 1;
        for (ll i = 1; i < n ; i++)
        {
            // cout << pf[i] << " " << pf[n] - pf[i] << endl;
            ll gd = gcd(min(pf[i], sum - pf[i]), max(pf[i], sum - pf[i]));
            maxi = max(maxi, gd);
        }
        cout << maxi << endl;
    }

    return 0;
}