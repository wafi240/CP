#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
#define ll long long
int main()
{

    ll n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    vector<ll> b(n + 1, 0);


    for (ll i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin>>b[i];
    }
    vector<vector<ll>>dp(3001,vector<ll>(3001,0));
    for (ll i = a[1]; i <= b[1]; i++)
    {
        dp[1][i]=1;
    }
    for (ll i = 2; i <= n; i++)
    {
        ll sum=0;
        ll j=0;
        for (; j <a[i]; j++)
        {
            sum=(sum+dp[i-1][j])%MOD;
        }
        for (; j <= b[i]; j++)
        {
            sum=(sum+dp[i-1][j])%MOD;
            dp[i][j]=sum;
        }
        
        
    }
    
    
    ll x=0;
    for (ll i = a[n]; i <= b[n]; i++)
    {
        x=(x+dp[n][i])%MOD;
    }
    cout<<x<<endl;
    
    return 0;
}