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
ll euler(ll n)
{
    ll cnt = n;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            cnt -= cnt / i;
        }
    }
    if (n > 1)
    {
        cnt -= cnt / n;
    }
    return cnt;
}
ll divi(ll n)
{
    ll count = 0;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (__gcd(i, n) != i)
            {
                count++;
            }
            ll x = n / i;
            if (__gcd(x, n) != x)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    while (cin >> n)

    {

        ll count =
        divi(n);

        cout << count << endl;
    }
    return 0;
}