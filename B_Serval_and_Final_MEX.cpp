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

ll calculateMex(const std::vector<ll> &vec, ll start, ll end)
{
    // Find the maximum element in the range to determine frequency array size
    ll max_element = *std::max_element(vec.begin() + start, vec.begin() + end + 1);

    // Create a frequency array (add +2 to handle case where all numbers 0..max are present)
    std::vector<bool> present(max_element + 2, false);

    // Mark present elements
    for (ll i = start; i <= end; ++i)
    {
        if (vec[i] >= 0)
        { // Only consider non-negative numbers for MEX
            present[vec[i]] = true;
        }
    }

    // Find the first non-present number
    for (ll i = 0; i < present.size(); ++i)
    {
        if (!present[i])
        {
            return i;
        }
    }

    return present.size(); // This line is theoretically unreachable
}
int main()
{
    tt()
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        if (v[0] == 0 && v[n - 1] == 0)
        {
            ll indx = -1;
            for (ll i = 2; i < n - 2; i++)
            {
                if (v[i] == 0)
                {
                    indx = i;
                    break;
                }
            }
            if (indx == -1)
            {
                cout << 3 << endl;
                cout << n - 1 << " " << n << endl;
                cout << 1 << " " << 2 << endl;

                cout << 1 << " " << n-2 << endl;
            }
            else
            {
                cout << 4 << endl;
                cout << n - 1 << " " << n << endl;
                // cout << 1 << " " << indx+1 << endl;
                cout << 3 << " " << n - 1 << endl;
                cout << 1 << " " << 2 << endl;
                cout << 1 << " " << 2 << endl;
            }
        }
        else if (v[0] == 0)
        {
            cout << 2 << endl;
            cout << 1 << " " << n - 1 << endl;
            cout << 1 << " " << 2 << endl;
        }
        else if (v[n - 1] == 0)
        {
            cout << 2 << endl;
            cout << 2 << " " << n << endl;
            cout << 1 << " " << 2 << endl;
        }
        else
        {
            ll indx = -1;
            for (ll i = 0; i < n; i++)
            {
                if (v[i] == 0)
                {
                    indx = i + 1;
                    break;
                }
            }
            if (indx == -1)
            {
                cout << 3 << endl;
                cout << 1 << " " << n - 2 << endl;
                cout << 1 << " " << 2 << endl;
                cout << 1 << " " << 2 << endl;
            }
            else
            {
                cout << 2 << endl;
                cout << 1 << " " << n - 1 << endl;
                cout << 1 << " " << 2 << endl;
            }
        }
    }
}