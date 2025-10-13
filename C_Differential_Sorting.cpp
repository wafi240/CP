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
        ll indx = -1;
        ll ele = -1;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] >= 0)
            {
                ele = v[i];
                indx = i;
            }
        }
        if (v[n - 1] < v[n - 2])
        {
            cout << -1 << endl;
            continue;
        }
        ll j = n - 3;
        vector<ll> v1;
        bool flag = true;
        while (j >= 0)
        {
            if (v[j] <= v[j + 1])
            {
                j--;
            }
            else
            {
                if (j >= indx)
                {
                    flag = false;
                    break;
                }
                else
                {
                    v[j] = v[j + 1] - ele;
                    v1.push_back(j);
                    v1.push_back(j + 1);
                    v1.push_back(indx);
                    j--;
                }
            }
        }
        if (flag == false)
        {
            cout << -1 << endl;
        }
        else
        {
            ll x = v1.size() / 3;
            cout << x << endl;
            for (ll i = 0; i < v1.size(); i += 3)
            {
                cout << v1[i]+1 << " " << v1[i + 1]+1 << " " << v1[i + 2]+1 << endl;
            }
        }
    }

    return 0;
}