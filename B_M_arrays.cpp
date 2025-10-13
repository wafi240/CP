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

        ll count = 0;
        map<ll, ll> mp;
        for (ll i = 0; i < k; i++)
        {
            mp[i] = 0;
        }

        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i] % k]++;
            // cout<<v[i]%k<<" "<<mp[v[i]%k]<<endl;
        }
        // nl;
        auto it = mp.begin();
        auto itt = mp.end();
        itt--;
        if (it->first == 0 && it->second>0)
        {
            count++;
        }
        it++;

        while (it->first < itt->first)
        {
            // cout<<"in"<<endl;

            // cout << it->first << " " << itt->first << endl;
            // cout << it->second << " " << itt->second << endl;
            ll x = it->second;
            ll y = itt->second;
            if (x > 0 && y > 0)
            {
                ll mini = min(x, y);
                x -= min(x, mini+1);
                y -= min(y, mini+1);
                count++;
                count += x;
                count += y;
                // cout<<"case-1"<<endl;        cout << count << endl;

            }

            else
            {
                count += x;
                count += y;
                // cout<<"case-2"<<endl;        cout << count << endl;

            }
            it++;
            itt--;
            // nl;
        }
        if (k % 2 == 0 && it->second > 0)
        {
            count++;
        }

        // cout<<"count: ";
        cout << count << endl;
    }
    return 0;
}