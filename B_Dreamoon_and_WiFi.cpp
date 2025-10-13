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

ll nCr(ll n, ll r)
{
    if (r > n)
        return 0;
    if (r == 2)
        return (n * (n - 1)) / 2;
    if (r == 1)
        return n;
    if (r == 0 || r == n)
        return 1;

    ll res = 1;
    for (ll i = 1; i <= r; i++)
    {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    string s, s1;
    cin >> s >> s1;
    ll c1 = 0;
    ll cp1 = 0;
    ll cm1 = 0;

    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '+')
        {
            c1++;
            cp1++;
        }
        else
        {
            c1--;
            cm1++;
        }
    }
    ll q = 0;
    ll c2 = 0;
    ll cp2 = 0;
    ll cm2 = 0;

    for (ll i = 0; i < s1.size(); i++)
    {
        if (s1[i] == '+')
        {
            c2++;
            cp2++;
        }
        else if (s1[i] == '-')
        {
            c2--;
            cm2++;
        }
        else
        {
            q++;
        }
    }
    if (q == 0)
    {
        if (c1 != c2)
        {
            cout << fixed << setprecision(12) << 0.0 << endl;
            return 0;
        }
        else

        {
            cout << fixed << setprecision(12) << 1.0 << endl;
            return 0;
        }
    }
    ll sum = pow(2, q);
    ll tot = abs(cp1-cp2);
    // if (c1 == c2)

    // {

    //     if (q % 2 == 0)
    //     {
    //         cout << 0.500000000000 << endl;
    //         return 0;
    //     }
    //     else
    //     {

    //         cout << 0.000000000000 << endl;
    //         return 0;
    //     }
    // }
    if (cp1<cp2 || cm1<cm2)
    {
        // cout<<"case-1"<<endl;
        cout << fixed << setprecision(12) << 0.0 << endl;
        return 0;
    }
    // cout<<"case-2"<<endl;
    ll x = nCr(q, tot);
    // cout << x << endl;
    // cout << sum << endl;
    double ans = (x * 1.0) / sum;
    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}