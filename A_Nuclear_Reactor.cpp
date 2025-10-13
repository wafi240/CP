#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 998244353;
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
    // vector<ll>diff;
    // for (ll i = 1; i < n; i++)
    // {
    //     diff.push_back(v[i]-v[0]);
    // }
    if (k == 2)
    {
        cout << v[0] << " " << v[n - 1] << endl;
        return 0;
    }
    vector<ll> ans;
    ans.push_back(v[0]);
    // ans.push_back(v[n-1]);
    ll x = v[n - 1] / k;
    ll i = 1;
    ll count = v.size() - 1;
    ll need = k - 2;
    while (i < v.size() && need > 0)
    {
        if (v[i] - v[0] <= x && need <= count)
        {
            i++;
        }
        else if (v[i] - v[0] > x && need > count)
        {
            cout<<"case-2"<<endl;
            ans.push_back(v[i - 1]);
            need--;
        }
        else
        {
            ans.push_back(v[i]);
            i++;
            need--;
        }
        count--;
    }
    ans.push_back(v[n - 1]);
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    nl;

    return 0;
}