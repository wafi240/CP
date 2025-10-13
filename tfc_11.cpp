#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<pair<ll, ll>> v1;
    ll t = 0;
    while (k--)
    {
        ll p, q;
        cin >> p >> q;
        v1.push_back({p, q});
    }
    // ll j = 0;
    // while (j < v1.size())
    // {
    //     ll i = v1[j].second;
    //     ll sum = 0;
    //     while (i < n)
    //     {
    //         sum += v[i];
    //         i += v1[j].first;
    //     }

    //     j++;
    //     cout << sum << endl;
    // }

    return 0;
}
