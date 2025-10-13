
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
    string s;
    cin >> s;

    map<ll, ll> mp;
    for (ll i = 0; i < s.size(); i++)
    {
        ll x = s[i] - 'a';
        mp[x]++;
    }
    vector<ll> v;
    auto it = mp.begin();
    while (it != mp.end())
    {
        v.push_back(it->second);

        it++;
    }
    sort(v.begin(), v.end());

    ll sum = 0;
    ll q = mp.size();
    if (q == k)
    {
        cout << 0 << endl;
        return 0;
    }
    if (k > q)
    {
        cout << k - q << endl;
        return 0;
    }
    for (ll i = 0; i < q - k; i++)
    {
        sum += v[i];
    }

    cout << sum << endl;
    return 0;
}