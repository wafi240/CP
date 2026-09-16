// wafi the laura — farming aura
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#define error(...)
#endif
#define ll long long
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
const ll mod = 1e9 + 7;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ot(x) cout << x << endl
#define in(x) cin >> x
#define nl cout << '\n';
#define tt    \
    ll t;     \
    cin >> t; \
    while (t--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortrv(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define all(x) x.begin(), x.end()
#define setbit(x, i) ((x) | (1LL << (i)))
#define checkbit(x, i) ((x) & (1LL << (i)))
#define togglebit(x, i) ((x) ^ (1LL << (i)))
void in_variadic() {}
template <typename T, typename... Args>
void in_variadic(T &first, Args &...rest)
{
    cin >> first;
    in_variadic(rest...);
}
ll adds(ll a, ll b) { return (a + b) % mod; }
ll subs(ll a, ll b) { return (a - b + mod) % mod; }
ll muls(ll a, ll b) { return (a * b) % mod; }
ll binexp(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = muls(res, a);
        a = muls(a, a);
        b >>= 1;
    }
    return res;
}
ll inv(ll a) { return binexp(a, mod - 2); }
ll divs(ll a, ll b) { return muls(a, inv(b)); }
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
struct PBDS : tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
{
    ll count_less(T x) { return (ll)this->order_of_key(x); }
    ll count_less_equal(T x) { return (ll)this->order_of_key(x + 1); }
    ll count_greater(T x) { return (ll)this->size() - this->order_of_key(x + 1); }
    ll count_greater_equal(T x) { return (ll)this->size() - this->order_of_key(x); }
};
typedef PBDS<tuple<ll, ll, ll>> oset;
// oset s; s.insert(5); s.order_of_key(x); *s.find_by_order(k);
// s.count_less(x) / s.count_less_equal(x) / s.count_greater(x) / s.count_greater_equal(x)

ll func(string &s)
{
    string s1 = "";
    ll pen = 0;
    s1 += s[0];
    s1 += s[1];
    ll x = stoll(s1);
    pen += x * 60 * 60;
    s1 = "";
    s1 += s[3];
    s1 += s[4];
    x = stoll(s1);
    pen += x * 60;
  
    

    return pen;
}
int main()
{
    fast
        ll n,
        k;
    cin >> n >> k;
    map<ll, ll> penalty;
    map<ll, ll> count;
    vector<vector<ll>> v(n + 1, vector<ll>(26, 0));
    vector<vector<bool>> alr(n + 1, vector<bool>(26, false));
    oset st;

const ll y=0;
    for (ll i = 1; i <= n; i++)
    {
        st.insert({0, 0, i});
    }

    for (ll i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        ll team;
        cin >> team;
        char ch;
        cin >> ch;
        string status;
        cin >> status;
        if(alr[team][ch - 'A'])continue;
        if (status == "RJ" && alr[team][ch - 'A'] == false)
        {

            v[team][ch - 'A'] += 1200;
        }
        else if(status=="AC")
        {

            ll x = func(s);
            if (alr[team][ch - 'A'] == false)
            {
                ll pre =  st.count_less({-count[team], penalty[team], team})+1;
                st.erase({-count[team], penalty[team], team});
                penalty[team] += v[team][ch - 'A'] + x;

                count[team]++;
                st.insert({-count[team], penalty[team], team});
                ll curr = st.count_less({-count[team], penalty[team], team})+1;
                alr[team][ch - 'A'] = true;
                if (team == y)
                {
                    cout << s << " " << ch << " #" << pre << " -> #" << curr << endl;
                }
            }
        }
    }

    return 0;
}