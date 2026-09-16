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
#define ot(x) cout << x << '\n'
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
void in() {}
template <typename T, typename... Args>
void in(T &first, Args &...rest)
{
    cin >> first;
    in(rest...);
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
class ST
{
private:
    vector<ll> tree;
    ll size;
public:
    ST(ll n)
    {
        size = n;
        tree.resize(4 * n, 0);
    }
    void build(ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node] = 0;
            return;
        }
        ll mid = (start + end) / 2;
        ll leftchild = 2 * node;
        ll rightchild = 2 * node + 1;
        build(leftchild, start, mid);
        build(rightchild, mid + 1, end);
        tree[node] = tree[leftchild] + tree[rightchild];
    }
    void update(ll node, ll start, ll end, ll indx, ll value)
    {
        if (indx < start || indx > end) return;
        if (start == end)
        {
            tree[node] = value;
            return;
        }
        ll mid = (start + end) / 2;
        ll leftchild = 2 * node;
        ll rightchild = 2 * node + 1;
        update(leftchild, start, mid, indx, value);
        update(rightchild, mid + 1, end, indx, value);
        tree[node] = tree[leftchild] + tree[rightchild];
    }
    ll query(ll node, ll start, ll end, ll l, ll r)
    {
        if (l > end || r < start) return 0;
        if (start >= l && end <= r) return tree[node];
        ll mid = (start + end) / 2;
        ll leftchild = 2 * node;
        ll rightchild = 2 * node + 1;
        return query(leftchild, start, mid, l, r) + query(rightchild, mid + 1, end, l, r);
    }
};

int main()
{
    fast
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    deque<pair<int,int>>odd;
    deque<pair<int,int>>even;
    map<pair<int,int>,int>mp;
   
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(i%2==1)
        {
            even.push_back({v[i],i});
        }
        odd.push_back({v[i],i});
    }

    sort(odd.rbegin(),odd.rend());
    sort(even.rbegin(),even.rend());
    int i=0;
    int j=0;
    while(k--)
    {
        int val;
        cin>>val;
        if(val==1)
        {
            while(i<odd.size() && mp[{odd[i].first,odd[i].second}]==1)
            {
                i++;
            }
            if(i>=odd.size())
            {
                cout<<odd[i-1].second+1<<endl;
                mp[{odd[i-1].first,odd[i-1].second}]=1;
            }
            else
            {
                cout<<odd[i].second+1<<endl;
                mp[{odd[i].first,odd[i].second}]=1;
            }
        }
        else{
            while(j<even.size() && mp[{even[j].first,even[j].second}]==1)
            {
                j++;
            }
            if(j>=even.size())
            {
                cout<<even[j-1].second+1<<endl;
                mp[{even[j-1].first,even[j-1].second}]=1;
            }
            else
            {
                cout<<even[j].second+1<<endl;;
                mp[{even[j].first,even[j].second}]=1;
            }
        }

        int x;
        cin>>x;
        cout.flush();
    }

    return 0;
}