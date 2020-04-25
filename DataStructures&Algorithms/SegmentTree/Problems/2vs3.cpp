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
ll powerFast(ll x,ll y)
{
    ll res=1;
    x=x%3;
    while(y>0)
    {
        if(y&1)
            res=(res*x)%3;
        y=y>>1;
        x=(x*x)%3;
    }
    return res;
}

class data
{
public:
    int rem, len;
    data()
    {
        this->rem = 0;
        this->len = 0;
    }
};

const int N=100005;
string a;
data seg[N<<2];

//update as required
void merge(data &cur, data &l, data &r) 
{
	cur.len = l.len + r.len;
    cur.rem =  ((l.rem*powerFast(2,r.len))%3 + r.rem)%3;
}

void build(int node, int start, int end)
{
    if(start == end)
    {
        //update as required
        seg[node].rem = (a[start]=='1'? 1 : 0);
        seg[node].len = 1;
        return ;
    }
    int mid = (start+end)>>1;
    build(node<<1, start, mid);
    build(node<<1|1, mid+1, end);
    merge(seg[node],seg[node<<1],seg[node<<1|1]);
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        //update as required
        if(a[idx]=='0')
        {
        	a[idx]='1';
        	seg[node].rem = 1;
        	seg[node].len = 1;
        }
        return;
    }
    int mid = (start + end)>>1;
    if(start <= idx && idx <= mid)
        update(node<<1, start, mid, idx, val);
    else
        update(node<<1|1, mid+1, end, idx, val);
    merge(seg[node],seg[node<<1],seg[node<<1|1]);

}

data query(int node, int start, int end, int l, int r)
{
    if(r<start || end<l)
    {
        // range represented by a node is completely outside the given range
        data d;
        return d;
    }
    if(l<=start && end<=r)
    {
        // range represented by a node is completely inside the given range
        return seg[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end)>>1;
    data p1 = query(node<<1, start, mid, l, r);
    data p2 = query(node<<1|1, mid+1, end, l, r);
    data p;
    merge(p,p1,p2);
    return p;
}
/*
indexing or array is from 0,n-1
for(int i=0;i<n;i++)cin>>a[i];
build(1,0,n-1);
cin >> x >> y;
cout<<query(1,0,n-1,x-1,y-1)<<endl;
update(1,0,n-1,x-1,y);
for(int i=1; i<=2*n; i++)
{
    cout << seg[i].maxi sp seg[i].secmaxi << endl;
}
*/

int main(int argc, char const *argv[])
{
	sync;
	int n;
	cin >> n;
	cin >> a;

	build(1,0,n-1);
	int q;
	cin >> q;
	int op, u, v;
	while(q--)
	{
		cin >> op;
		if(op==0)
		{
			cin >> u >> v;
			cout << query(1,0,n-1,u,v).rem << endl;
		}
		else
		{
			cin >> u;
			update(1,0,n-1,u,1);
		}
	}
	return 0;
}
