#include <bits/stdc++.h>
#include <numeric>   // fixed syntax
using namespace std; // fixed syntax

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

void getPrimeFactorMap(ll n, unordered_map<ll, ll> &divi)
{
    if (n <= 1)
        return;

    // Handle factor 2
    while (n % 2 == 0)
    {
        divi[2]++;
        n /= 2;
    }

    // Handle odd factors
    for (ll i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            divi[i]++;
            n /= i;
        }
    }

    // Handle remaining prime factor
    if (n > 1)
    {
        divi[n]++;
    }
}

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

        // Use unordered_map instead of huge vector
        unordered_map<ll, ll> divi;

        for (ll i = 0; i < n; i++)
        {
            getPrimeFactorMap(v[i], divi);
        }

        bool flag = true;
        for (auto &p : divi)
        {
            if (p.second % n != 0)
            {
                flag = false;
                break;
            }
        }

        if (!flag)
            NO;
        else
            YES;
    }

    return 0;
}
