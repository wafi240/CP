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
        ll n;
        cin >> n;
        vector<ll> v(n);
        vector<ll> biggi(n);
        vector<ll> summy(n);
        ll sum = 0;
        ll maxi = -1, indx = -1;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] > maxi)
            {
                maxi = v[i];
            
            }
            biggi[i] = maxi;
            sum += v[i];
            summy[i] = sum;
        }
        if (n == 1 && v[0]==0)
        {
            cout << 1 << endl;
            continue;
        }
        if (n == 1 && v[0]==1)
        {
            cout << 0 << endl;
            continue;
        }
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            if (summy[i] == 2* biggi[i])
            {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}