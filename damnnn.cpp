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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n == 2)
    {
        cout << max(v[0], v[1]) << endl;
        return 0;
    }
    vector<ll> pf(n - 1, 0);
    pf[0] = (v[0]);
    vector<ll> pf2(n - 1, 0);
    pf2[n - 2] = v[n - 1];
    ll ele = -1;
    ll indx = -1;
    for (ll i = 1; i < n - 1; i++)
    {
        pf[i] = __gcd(pf[i - 1], v[i]);
    }
    for (ll i = n - 3; i >= 0; i--)
    {
        pf2[i] = __gcd(pf2[i + 1], v[i + 1]);
    }

    // for (ll i = 0; i < pf.size(); i++)
    // {
    //     cout << pf[i] << " ";
    // }
    // nl;
    // for (ll i = 0; i < pf2.size(); i++)
    // {
    //     cout << pf2[i] << " ";
    // }
    // nl;
    ll maxi = 0;

    for (ll i = 1; i < n - 1; i++)
    {
        if (__gcd(pf[i - 1], pf2[i]) > maxi)
        {
            maxi = __gcd(pf[i - 1], pf2[i]);
            indx = i;
        }
    }
    if (pf[n - 2] > maxi)
    {
        indx = n - 1;
    }
    if (pf2[0] > maxi)
    {
        indx = 0;
    }
    bool flag = false;
    if (pf2[0] == maxi)
    {
        flag = true;
    }
    ll sum2 = 0;
    if (flag == true)
    {
        vector<ll> v2;
        v2.push_back(v[1]);
        for (ll i = 2; i < n; i++)
        {
            v2.push_back(__gcd(v2[v2.size() - 1], v[i]));
        }

        sum2 = accumulate(v2.begin(), v2.end(), 0);
    }
    vector<ll> v1;
    ll i = 1;
    if (indx == 0)
    {
        v1.push_back(v[1]);
        i++;
    }
    else
    {
        v1.push_back(v[0]);
    }
    for (; i < n; i++)
    {
        if (i == indx)
        {
            continue;
        }
        else
        {
            v1.push_back(__gcd(v1[v1.size() - 1], v[i]));
        }
    }
    ll sum = accumulate(v1.begin(), v1.end(), 0);
    cout << max(sum2, sum) << endl;

    return 0;
}

/*        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        if (n == 2)
        {
            cout << 3 << endl;
            continue;
        }
        if (n == 3)
        {
            cout << 7 << endl;
            continue;
        }
        vector<ll> v(n + 1, 0);
        ll i = n;
        // cout<<i<<endl;
        while (i >= 4)
        {
            ll x = sqrt(i);
            // cout<<x<<endl;
            if (x*x == i)
            {
                v[x] = 1;
                // cout<<x<<endl;
            }
            i--;
        }
        ll count = 1;
        for (ll i = 2; i <= n; i++)
        {
            if (v[i] != 0)
            {

                count++;
            }
            else
            {
                count += n;
            }
        }
        cout << count << endl;

*/