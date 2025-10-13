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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll r = 0;
    tt()
    {
        r++;
        ll n, x;
        cin >> n >> x;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll mini = LLONG_MAX;
        ll maxi = LLONG_MIN;
        deque<ll> dq;
        vector<ll> v3;
        for (ll i = 0; i < x; i++)
        {
            dq.push_back(v[i]);
        }
        mini = *min_element(dq.begin(), dq.end());
        maxi = *max_element(dq.begin(), dq.end());
        v3.push_back(maxi - mini);
        for (ll i = x; i < n - x; i++)
        {

            dq.pop_front();
            dq.push_back(v[i]);
            mini = *min_element(dq.begin(), dq.end());
            maxi = *max_element(dq.begin(), dq.end());
            v3.push_back(maxi - mini);
        }
        cout << "Case " << r << ": " << *max_element(v3.begin(), v3.end()) << endl;
    }
    return 0;
}