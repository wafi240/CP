#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1e9 + 7;
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
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
    fast;
    tt()
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<ll> div;
        for (ll i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                div.push_back(i);
                if (n / i != i)
                {
                    div.push_back(n / i);
                }
            }
        }
        // for (ll i = 0; i < div.size(); i++)
        // {
        //     cout << div[i] << " ";
        // }
        // nl;

        ll maxi = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
        ll sum = 0;
        vector<ll> pref(n + 1, 0);
        for (ll i = 1; i < n + 1; i++)
        {
            sum += v[i - 1];
            pref[i] = sum;
        }
        for (ll i = 0; i < div.size(); i++)
        {
            ll count = div[i];
            ll mini = LLONG_MAX;
            ll maxis = LLONG_MIN;
            for (ll j = 1; count * j < pref.size(); j++)
            {
                maxis = max(maxis, pref[count * j] - pref[count * (j - 1)]);
                mini = min(mini, pref[count * j] - pref[count * (j - 1)]);
                // cout<<maxis<<" "<<mini<<endl;
            }
            maxi=max(maxi,maxis-mini);
        }
        cout << maxi << endl;
    }
    return 0;
}