#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> lis(vector<ll> &arr, ll k)
{
    ll n = arr.size();
    vector<ll> ans, ans1(n);
    ans.push_back(arr[0]);
    ll ttl = arr[0];
    // cout << ans.back() << " " << ans.size();
    // cout << "\n";
    ll x = ans.back();
    ll y = ans.size();
    if (x < y)
    {
        // cout << "1-1" << endl;
        ll temp = (((k ) * (k + 1 )) / 2);
        ans1[0] = temp + ttl;
    }
    else
    {
        // cout << "1-2" << endl;
        ans1[0] = (y * k) + ttl;
    }
    for (ll i = 1; i < n; i++)
    {
        ttl += arr[i];
        if (arr[i] > ans.back())
            ans.push_back(arr[i]);
        else
        {
            ll low = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[low] = arr[i];
        }
        // cout << ans.back() << " " << ans.size();
        // cout << "\n";
        x = ans.back();
        y = ans.size();
        if (x < y)
        {
            ll temp = (((k+y-1) * (k + 1 +y-1)) / 2) - ((y - 1) * (y) / 2);
            
            ans1[i] = temp + ttl;
        }
        else
        {
            ans1[i] = (y * k) + ttl;
        }
    }
    return ans1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n, 0), ans;
        for (int st = 0; st < n; st++)
            cin >> arr[st];
        ans = lis(arr, k);
        for (auto it : ans)
            cout << it << " ";
        cout << "\n";
    }
}