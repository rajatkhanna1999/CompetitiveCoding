#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
using namespace std;
using namespace __gnu_pbds;

#define sp << " " <<
#define mod 1000000007
#define PI 3.14159265358979323
#define y second
#define x first
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define pqueue priority_queue< ll >
//#define pdqueue priority_queue< ll,vector<ll> ,greater< ll > >
#define codejamDebug(x) cout<<"Case #"<<x<<": ";
#define debug(x) cout<<#x<<" :"<<x<<endl;
#define rep(i,n) for(long long i=0;i<n;i++)
#define f(i,a,b) for(long long i = a; i < b; i++)
#define fd(i,a,b) for(long long i = a; i >=b; i--)
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long int           ll;
typedef long double             ld;
typedef unsigned long long int ull;
typedef vector <int>            vi;
typedef vector <ll>            vll;
typedef pair <int, int>        pii;
typedef pair <ll, ll>          pll;
typedef vector < pii >        vpii;
typedef vector < pll >        vpll;
typedef vector <string>         vs;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Handle:cyber_rajat
class data
{
public:
    ll s, ss;
    data()
    {
        this->s = 0;
        this->ss = 0;
    }
};

const ll N=100005;
ll a[N];
pair<int,int> lazy[N<<2];
data seg[N<<2];

//update as required
void merge(data &cur, data &l, data &r) 
{
    cur.ss = l.ss + r.ss;
    cur.s = l.s + r.s;
}

void build(ll node, ll start, ll end)
{
    if(start == end)
    {
    	seg[node].ss = a[start]*a[start];
        seg[node].s = a[start];
        return ;
    }
    ll mid = (start+end)>>1;
    build(node<<1, start, mid);
    build(node<<1|1, mid+1, end);
    merge(seg[node],seg[node<<1],seg[node<<1|1]);
}

void update(ll node,ll start,ll end,ll l,ll r,ll val, ll qtype){
    if(lazy[node].y!=0)
    {
    	seg[node].ss=(end-start+1)*(lazy[node].y)*(lazy[node].y);
        seg[node].s=(end-start+1)*(lazy[node].y);
        if(start!=end)
        {
            lazy[node<<1].y=lazy[node].y;
            lazy[node<<1].x=0;
            lazy[node<<1|1].x=0;
            lazy[node<<1|1].y=lazy[node].y;
        }
        lazy[node].y=0;
    }
    if(lazy[node].x!=0)
    {
    	seg[node].ss+=((end-start+1)*lazy[node].x*lazy[node].x + 2*lazy[node].x*seg[node].s);
        seg[node].s+=(end-start+1)*lazy[node].x;
        if(start!=end)
        {
            lazy[node<<1].x+=lazy[node].x;
            lazy[node<<1|1].x+=lazy[node].x;
        }
        lazy[node].x=0;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r)
    {
    	if(qtype==0)
        {
            seg[node].ss=(end-start+1)*val*val;
            seg[node].s=(end-start+1)*val;
            //cout<<"hh";
            if(start!=end)
            {
                lazy[node<<1].y=val;
                lazy[node<<1].x=0;
                lazy[node<<1|1].x=0;
                lazy[node<<1|1].y=val;
            }
        }
        else
        {
            seg[node].ss+=((end-start+1)*val*val + 2*val*seg[node].s);
            seg[node].s+=(end-start+1)*val;
            if(start!=end)
            {
                lazy[node<<1].x+=val;
                lazy[node<<1|1].x+=val;
            }
        }
        return ;
    }
    ll mid=(start+end)>>1;
    update(node<<1,start,mid,l,r,val,qtype);
    update(node<<1|1,mid+1,end,l,r,val,qtype);
    merge(seg[node],seg[node<<1],seg[node<<1|1]);
}

data query(ll node,ll start,ll end,ll l,ll r)
{
    if(start>end || start>r || end<l)
    {
        // range represented by a node is completely outside the given range
        data d;
        return d;
    }
    if(lazy[node].y!=0)
    {
        seg[node].s=(end-start+1)*(lazy[node].y);
        seg[node].ss=(end-start+1)*(lazy[node].y)*(lazy[node].y);
        if(start!=end)
        {
            lazy[node<<1].y=lazy[node].y;
            lazy[node<<1|1].y=lazy[node].y;
            lazy[node<<1].x=0;
            lazy[node<<1|1].x=0;
        }
        lazy[node].y=0;
    }
    if(lazy[node].x!=0)
    {
        seg[node].ss+=((end-start+1)*lazy[node].x*lazy[node].x + 2*lazy[node].x*seg[node].s);
        seg[node].s+=(end-start+1)*lazy[node].x;
        if(start!=end)
        {
            lazy[node<<1].x+=lazy[node].x;
            lazy[node<<1|1].x+=lazy[node].x;
        }
        lazy[node].x=0;
    }
    if(start>=l && end<=r)
    {
        // range represented by a node is completely inside the given range
        return seg[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    ll mid=(start+end)>>1;
    data p1=query(node<<1,start,mid,l,r);
    data p2=query(node<<1|1,mid+1,end,l,r);
    data p;
    merge(p,p1,p2);
    return p;
}

/*
for(int i=0;i<n;i++)cin>>a[i];
build(1,0,n-1);
cin >> x >> y;
cout<<query(1,0,n-1,x-1,y-1)<<endl;
update(1,0,n-1,x-1,y-1,v);
for(int i=1; i<=2*n; i++)
{
    cout << seg[i].maxi sp seg[i].secmaxi << endl;
}
*/

int main(int argc, char const *argv[])
{
	sync;
	ll t, T = 1;
	cin >> t;
	while(t--)
	{
		cout << "Case" sp T << ":" << endl;
		T++;
		ll n, q;
		cin >> n >> q;
		rep(i,n)cin >> a[i];

		build(1,0,n-1);
		ll op, u, v, val;
		while(q--)
		{
			cin >> op;
			if(op==2)
			{
				cin >> u >> v;
				u--, v--;
				cout << query(1,0,n-1,u,v).ss << endl;
			}
			else if(op==1)
			{
				cin >> u >> v >> val;
				u--, v--;
				update(1,0,n-1,u,v,val,1);
			}
			else
			{
				cin >> u >> v >> val;
				u--, v--;
				update(1,0,n-1,u,v,val,0);
			}	
			// for(int i=1; i<=2*n; i++)
			// {
	  //  			 cout << seg[i].ss sp seg[i].s << endl;
			// }
			// cout << "Lazy";
			// for(int i=1; i<=2*n; i++)
			// {
	  //  			 cout << lazy[i].x sp lazy[i].y << endl;
			// }
		}
	}
	return 0;
}
/*
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1
*/