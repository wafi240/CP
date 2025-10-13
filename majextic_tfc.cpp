#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {

        ll n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        vector<pair<ll, ll>> v;
        vector<pair<ll, ll>> v2;
        v.push_back(make_pair(a[0], 1));
        for (ll i = 0; i < n; i++)
        {
            v.push_back(make_pair(a[i], 1));
        }

        // maxi = max(count, maxi);

        // cout << maxi << endl;
    }

    return 0;
}