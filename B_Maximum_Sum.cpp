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
        vector<ll> v(n);
        vector<ll> v1(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            v1[i] = v[i];
        }
        sort(v.begin(), v.end());
        sort(v1.begin(), v1.end());
        ll sum1 = 0;
        for (ll i = 0; i < n-k; i++)
        {
            sum1+=v1[i];
        }
        
        ll i = 0, j = n - 1;
        while (k--)
        {
            if (v[i] + v[i + 1] < v[j])
            {
                v[i] = 0;
                v[i + 1] = 0;
                i += 2;
            }
            else
            {
                v[i] = 0;
                i++;
            }
        }
        ll sum = accumulate(v.begin(), v.end(), 0);
        cout<<"sum: "<<sum<<" "<<"sum1: "<<sum1<<endl;
        cout << max(sum,sum1) << endl;
    }

    return 0;
}