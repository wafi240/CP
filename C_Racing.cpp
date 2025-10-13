#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n);
    for (int &x : d)
    {
        cin >> x;
    }
    vector<pair<int, int>> badha(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> badha[i].first >> badha[i].second;
    }

    vector<int> lo(n), hi(n);
    int curr_lo = 0, curr_hi = 0;
    bool possible = true;
    for (int i = 0; i < n; ++i)
    {
        int l = badha[i].first;
        int r = badha[i].second;
        int new_lo, new_hi;
        if (d[i] == 0)
        {
            new_lo = curr_lo;
            new_hi = curr_hi;
        }
        else if (d[i] == 1)
        {
            new_lo = curr_lo + 1;
            new_hi = curr_hi + 1;
        }
        else
        {
            new_lo = curr_lo;
            new_hi = curr_hi + 1;
        }
        new_lo = max(new_lo, l);
        new_hi = min(new_hi, r);
        if (new_lo > new_hi)
        {
            possible = false;
            break;
        }
        lo[i] = new_lo;
        hi[i] = new_hi;
        curr_lo = new_lo;
        curr_hi = new_hi;
    }

    if (!possible)
    {
        cout << -1 << '\n';
        return;
    }

    vector<int> ans = d;
    int h_current = hi.back();
    for (int i = n - 1; i >= 0; --i)
    {
        if (h_current < lo[i] || h_current > hi[i])
        {
            possible = false;
            break;
        }
        if (ans[i] != -1)
        {
            int delta = ans[i];
            int prev_h = h_current - delta;
            if (i > 0)
            {
                if (prev_h < lo[i - 1] || prev_h > hi[i - 1])
                {
                    possible = false;
                    break;
                }
            }
            else
            {
                if (prev_h != 0)
                {
                    possible = false;
                    break;
                }
            }
            h_current = prev_h;
        }
        else
        {
            bool found = false;
            for (int delta : {1, 0})
            {
                int prev_h = h_current - delta;
                bool valid;
                if (i > 0)
                {
                    valid = (prev_h >= lo[i - 1] && prev_h <= hi[i - 1]);
                }
                else
                {
                    valid = (prev_h == 0);
                }
                if (valid)
                {
                    ans[i] = delta;
                    h_current = prev_h;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                possible = false;
                break;
            }
        }
    }
    if (possible && h_current == 0)
    {
        for (int x : ans)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}