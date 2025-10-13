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
        vector<ll> v(n * k);

        for (ll i = 0; i < (n * k); i++)
        {
            cin >> v[i];
        }
        if (n == 2)
        {
            ll j = v.size() - 2;
            ll count = 0;
            ll tosum = 0;
            while (count < k)
            {
                tosum += v[j];
                j -= 2;
                count++;
            }

            cout << tosum << endl;
            continue;
        }
        ll j = v.size() - 1-(n-1);
        ll sum = 0;
        ll count = 0;
        while (count < k)
        {
            // cout<<v[j]<<" ";
            sum += v[j+1];
            j = j - (n - 1);
            count++;
        }
        cout << sum << endl;
    }

    return 0;
}