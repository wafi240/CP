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
int main()
{

    tt()
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        vector<ll> p(k);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (ll i = 0; i < k; i++)
        {
            cin >> p[i];
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        sort(p.begin(), p.end());

        ll i = 0;
        ll j = 0;
        while (i < n && j < k)
        {

            // cout << i << " " << p[j] << endl;

            if (i + p[j] - 1 < n)
            {
                v[i + p[j] - 1] = 0;
            }
            else
            {
                break;
            }
            i += p[j];
            j++;
        }
        // for (ll i = 0; i < n; i++)
        // {
        //    cout<<v[i]<<" ";
        // }nl;
        ll sum = accumulate(v.begin(), v.end(), 0LL);
        cout << sum << endl;
    }
    return 0;
}