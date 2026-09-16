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
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>one;
    vector<int>onetwo;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]==1)
        {
            one.push_back(i);
            onetwo.push_back(i);
        }
        if(v[i]==2)
        {
            onetwo.push_back(i);
        }
    }
    int ans=0;
    if(one.size()>=2)
    {
        int l=0;
        int r=1;
        while(r<one.size())
        {
            int id1=one[l];
            int id2=one[r];
            bool zero=false;
            bool flag=true;
            while(id1<id2)
            {
                if(v[id1]==0)
                {
                    zero=true;
                }
                else{
                    flag=false;
                    break;
                }
                id1++;
            }
            if(!flag)
            {
                r++;
                l++;
                continue;
            }

            if(!zero)
            {
                id1=one[l];
                int val=id1;
                while(val>0 && v[val]==0)
                {
                    val--;
                }
                int ml1=id1-val;
                val=id2;
                while(val<n && v[val]==0)
                {
                    val++;
                }
                int ml2=val-id2;
                int pl=ml1*(ml2+1)+ml2;
                ans+=pl;
                id2=one[r];
            }
            else{
                id1=one[l];
                int val=id1;
                while(val>0 && v[val]==0)
                {
                    val--;
                }
                int ml1=id1-val;
                val=id2;
                while(val<n && v[val]==0)
                {
                    val++;
                }
                int ml2=val-id2;
                int pl=(ml1+1)*(ml2+1);
                ans+=pl;
                id2=one[r];
            }
            r++;
            l++;
        }
    }
    if(onetwo.size()>=2)
    {
        int l=0;
        int r=1;
        while(r<onetwo.size())
        {
            int id1=onetwo[l];
            int id2=onetwo[r];
            bool zero=false;
            bool flag=true;
            while(id1<id2)
            {
                if(v[id1]==0)
                {
                    zero=true;
                }
                else{
                    flag=false;
                    break;
                }
                id1++;
            }
            if(!flag)
            {
                r++;
                l++;
                continue;
            }

            if(!zero)
            {
                id1=onetwo[l];
                int val=id1;
                while(val>0 && v[val]==0)
                {
                    val--;
                }
                int ml1=id1-val;
                val=id2;
                while(val<n && v[val]==0)
                {
                    val++;
                }
                int ml2=val-id2;
                int pl=ml1*(ml2+1)+ml2;
                ans+=pl;
                id2=onetwo[r];
            }
            else{
                id1=onetwo[l];
                int val=id1;
                while(val>0 && v[val]==0)
                {
                    val--;
                }
                int ml1=id1-val;
                val=id2;
                while(val<n && v[val]==0)
                {
                    val++;
                }
                int ml2=val-id2;
                int pl=(ml1+1)*(ml2+1);
                ans+=pl;
                id2=onetwo[r];
            }
            r++;
            l++;
        }
    }

    cout<<ans<<endl;
    return 0;
}