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
        string s;
        cin >> s;

        ll cl = 0, cr = 0, cu = 0, cd = 0;
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                cl++;
            else if (s[i] == 'R')
                cr++;
            else if (s[i] == 'U')
                cu++;
            else if (s[i] == 'D')
                cd++;
        }
        if((cl==0 || cr==0)&&(cu==0||cd==0))
        {
            cout<<0<<endl;
            continue;
        }
        if (cd == 0 || cu == 0)
        {
            cout << 2 << endl;
            cout << "LR" << endl;
            continue;
        }
        if (cl == 0 || cr == 0)
        {
            cout << 2 << endl;
            cout << "UD" << endl;
            continue;
        }

        ll mini = min(cl, cr);
        ll mini2 = min(cu, cd);
        cout << (mini + mini2) * 2 << endl;
        for (ll i = 0; i < mini; i++)
        {
            cout << "L";
        }
        for (ll i = 0; i < mini2; i++)
        {
            cout << "U";
        }
        for (ll i = 0; i < mini; i++)
        {
            cout << "R";
        }
        for (ll i = 0; i < mini2; i++)
        {
            cout << "D";
        }
        nl;
    }

    return 0;
}