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

    tt()
    {
        ll n, k;
        cin >> n >> k;
        if (n % 2 == 0)
        {
            ll ans=k%n;
            if(ans==0)
            {
                ans=n;
            }
            cout << ans << endl;
        }
        else
        {
            ll d=(n+1)/2;
            if(k<d)
            {
                cout<<k<<endl;continue;
            }
            ll diff=n-d;
            ll x=(k-d)/diff;
            x++;
            ll ans=(k+x)%n;
            if(ans==0)
            {
                ans=n;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}