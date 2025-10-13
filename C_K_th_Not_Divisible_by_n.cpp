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
#define vi1(n) vector<int> v(n);
#define vl(n) vector<ll> v(n);
#define vl1(n) vector<ll> v(n);
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
        if(k==1)
        {
            cout<<1<<endl;
            continue;
        }
        ll num=k;
        
        while (true)
        {
            ll d=num/n;
            if(num-d==k)
            {
                cout<<num<<endl;
                break;
            }
            num+=(k-(num-d));
        }
        
    }
    return 0;
}