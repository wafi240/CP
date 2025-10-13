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
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll lo = 1, hi = n;
        ll i = 0, j = n - 1;
        while (i < j)
        {
            if (v[i] == lo || v[i] == hi)
            {
                if (v[i] == lo)
                {
                    lo++;
                }
                else
                {
                    hi--;
                }
                i++;
            }
            if (v[j] == lo || v[j] == hi)
            {
                if (v[j] == lo)
                {
                    lo++;
                }
                else
                {
                    hi--;
                }
                j--;
            }
            if (v[i] != lo && v[i] != hi && v[j] != lo && v[j] != hi)
            {
                break;
            }
        }
        if (i >= j)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << i + 1 << " " << j + 1 << endl;
        }
    }
    return 0;
}

//        }
// bool all_inc = true;
// bool all_dec = true;
// for (ll i = 1; i < n; i++)
// {
//     if (v[i] > v[i - 1])
//     {
//         all_dec = false;
//     }
//     else
//     {
//         all_inc = false;
//     }
// }
// if (all_dec == true || all_inc == true)
// {
//     cout << -1 << endl;
//     continue;
// }
// if (v[1] > v[0])
// {
//     bool flag = true;
//     ll indx = -1;

//     for (ll i = 0; i < n; i++)
//     {
//         if (v[i] < v[i - 1])
//         {
//             indx = i - 1;
//             break;
//         }
//     }
//     for (ll i = indx; i < n - 1; i++)
//     {
//         if (v[i] < v[i + 1])
//         {
//             flag = false;
//             break;
//         }
//     }
//     if (flag)
//     {
//         cout << -1 << endl;
//         continue;
//     }
// }
// else
// {
//     if (v[1] < v[0])
//     {
//         bool flag = true;
//         ll indx = -1;

//         for (ll i = 0; i < n; i++)
//         {
//             if (v[i] > v[i - 1])
//             {
//                 indx = i - 1;
//                 break;
//             }
//         }
//         for (ll i = indx; i < n - 1; i++)
//         {
//             if (v[i] > v[i + 1])
//             {
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag)
//         {
//             cout << -1 << endl;
//             continue;
//         }
//     }
// }
