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

    //   string s,n;
    //   s="abcdedf";n="d";
    //   int x= s.find(n[0]);
    //   cout<<x<<endl;
    //   x= s.find('r');
    //   cout<<x<<endl;
    tt()
    {
        string s, n;
        cin >> s >> n;
        if (s == n)
        {
            YES;
            continue;
        }
        reverse(s.begin(),s.end());
        reverse(n.begin(),n.end());
        int i = 0, j = 0;
        bool fixi = false;
        vector<int> v(n.size());
        int x = -1;
        while (j < n.size())
        {

            x = s.find(n[j], x + 1);
            int y = s.find(n[j]);
            if (x == -1)
            {
                fixi = true;
                break;
            }
            if (x != y)
            {
                fixi = true;
                break;
            }
            // cout << x << " " << n[j] << endl;
            
            s[x]=')';
            i++;
            j++;
        }
        if (fixi)
        {
            NO;
        }

        else
        {
            YES;
        }
    }

    return 0;
}