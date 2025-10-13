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

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << v[i] << " ";
    // }
    // nl;
    ll maxi = v[n / 2];
    ll count = 0;
    ll div = 1;
    ll diff = 0;
    while (k > 0)
    {

        auto it = upper_bound(v.begin(), v.end(), maxi);

        ll indx = it - v.begin();

        // cout << div << endl;
        // cout << indx << endl;
        diff = indx - (n / 2);

        if (indx == n)
        {
            ll vag = (k) / diff;
            maxi += vag;
            break;
        }
        else
        {
            div = (v[indx] - maxi);
        }
        // cout << diff << endl;
        // count = diff;
        // cout << count << endl;

        if (k < div*diff)
        {
           maxi+=k/diff;
            break;
        }
        maxi += div;
        k -= (diff * div);
        // nl;
    }
    cout << maxi << endl;

    return 0;
}