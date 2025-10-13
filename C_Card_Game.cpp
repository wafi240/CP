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
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n == 2)
        {
            if (s[0] == 'A')
            {
                out("Alice");
                continue;
            }
            else
            {
                out("Bob");
                continue;
            }
        }
        deque<int> a;
        deque<int> b;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
            {
                a.push_back(i + 1);
            }
            else
            {
                b.push_back(i + 1);
            }
        }
        if (b.front() == n)
        {
            out("Alice");
            continue;
        }
        if (a.front() == n)
        {
            out("Bob");
            continue;
        }
        while (a.size() > 0 && b.size() > 0)
        {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            int x = a.back();
            if (x == n && a.front() != 1 && a.size() != 1)
            {
                a.pop_back();
                int j = a.back();
                a.push_back(n);

                x = j;
            }

            // cout << "x: " << x << endl;
            auto a1 = a.begin();
            auto b1 = b.begin();
            // while (a1 != a.end())
            // {
            //     cout << *a1 << " ";
            //     a1++;
            // }
            // nl;
            // while (b1 != b.end())
            // {
            //     cout << *b1 << " ";
            //     b1++;
            // }
            // nl;

            auto it = b.begin();
            while (it != b.end() && *it <= x)
            {
                it++;
            }
            if (x == 1 && *it == n && b.size() == 1)
            {
                a.push_back(n);
                b.pop_back();
                break;
                // cout << "by 1: ";
            }

            else if (x == 1 && b.size() != 1)
            {

                a.pop_back();
                b.push_back(1);

                // cout << "by 2: ";
            }
            else if (x == n && b.front() == 1)
            {
                b.push_back(n);
                a.pop_back();
            }

            else if (it == b.end())

            {
                int p = b.front();

                b.pop_front();
                a.push_back(p);
                // cout << "by 3: ";
            }

            else if (it != b.end())
            {
                int g = a.back();
                a.pop_back();
                b.push_back(g);
                // cout << "by 4: ";
            }
            // else
            // {
            //     cout << "by 5: ";
            // }
        }
        if (a.empty())
        {
            cout << "Bob" << endl;
        }
        else if (b.empty())
        {
            cout << "Alice" << endl;
        }
    }
    return 0;
}