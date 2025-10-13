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

    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> v1(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cin >> v1[i];
    }

    ll d = *min_element(v1.begin(), v1.end());

    for (ll i = 0; i < n; i++)
    {

        mp[v[i]] = v1[i];
    }
    auto it = mp.begin();
    auto itt = mp.begin();
    itt++;bool flag=false;
    while (itt != mp.end())
    {
        if (it->second > itt->second)
        {
            flag = true;
            break;
        }
        itt++;
        it++;
    }

    if (flag==false)
    {
        cout << "Poor Alex" << endl;
    }
    else
    {
        cout << "Happy Alex" << endl;
    }

    return 0;
}