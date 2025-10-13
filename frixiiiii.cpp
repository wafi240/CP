
#include <bits/stdc++.h>
#include <numeric>
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
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> p(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (ll i = 0; i < n; i++)
    {

        p[i] = (int)log2(v[i]) + 1;
    }

    for (ll i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    nl;

    deque<ll> dq;
    for (ll i = 0; i < n; i++)
    {
        dq.push_back(v[i]);
    }

    ll maxi = *max_element(v.begin(), v.end());

    auto it = dq.begin();
    auto itt = dq.end();
    itt--;
    while (true)
    {
        /* code */
    }
    
    ll sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;

    return 0;
}