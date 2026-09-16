#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

#define yes cout << "YES\n"
#define no cout << "NO\n"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// TEMPLATE VERSION (IMPORTANT FIX)
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

int main()
{
    fast

        ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        ordered_set<ll> st0, st1;
        vector<ll> v(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        // split into even / odd
        for (ll i = 0; i < n; i++)
        {
            if (v[i] % 2 == 0)
                st0.insert(v[i]);
            else
                st1.insert(v[i]);
        }

        bool f = true;

        for (ll i = 0; i < n; i++)
        {
            if (v[i] % 2 == 0)
            {
                continue;
            }
            else
            {
                ll k = st1.order_of_key(v[i]);
                if (k == 0)
                {
                    f = false;
                    break;
                }
            }
        }
        // cout<<f<<endl;

        bool f1 = true;

        for (ll i = 0; i < n; i++)
        {
            if (v[i] % 2 != 0)
            {
                continue;
            }
            else
            {
                ll k = st1.order_of_key(v[i]);
                if (k == 0)
                {
                    f1 = false;
                    break;
                }
            }
        }

        if (f==false && f1==false)
            no;
        else
            yes;
    }

    return 0;
}