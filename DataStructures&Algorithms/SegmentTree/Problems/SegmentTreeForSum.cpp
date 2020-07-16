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
#define mem(a,b) memset(a,b,sizeof(a))
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

class dat
{
public:
    ll mx;
    dat()
    {
        this->mx = 0;
    }
};

const int N=100005;
int a[N];
dat seg[N<<2];

//update as required
void merge(dat &cur, dat &l, dat &r) 
{
    cur.mx = l.mx + r.mx; 
}

void build(int node, int start, int end)
{
    if(start == end)
    {
        //update as required
        seg[node].mx = a[start];
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
        a[idx] = val;
        seg[node].mx = val;
        return;
    }
    int mid = (start + end)>>1;
    if(start <= idx && idx <= mid)
        update(node<<1, start, mid, idx, val);
    else
        update(node<<1|1, mid+1, end, idx, val);
    merge(seg[node],seg[node<<1],seg[node<<1|1]);

}

dat query(int node, int start, int end, int l, int r)
{
    if(r<start || end<l)
    {
        // range represented by a node is completely outside the given range
        dat d;
        return d;
    }
    if(l<=start && end<=r)
    {
        // range represented by a node is completely inside the given range
        return seg[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end)>>1;
    dat p1 = query(node<<1, start, mid, l, r);
    dat p2 = query(node<<1|1, mid+1, end, l, r);
    dat p;
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
    cout << i << ":" sp seg[i].maxi sp seg[i].secmaxi << endl;
}
*/

int main(int argc, char const *argv[])
{
	sync;
	int n, m;
	cin >> n >> m;
	rep(i,n){
		cin >> a[i];
	}
	build(1,0,n-1);
	int op, u, v;
	rep(i,m){
		cin >> op >> u >> v;
		if(op == 1){
			update(1,0,n-1,u,v);
		}else{
			v--;
			dat ans = query(1,0,n-1,u,v);
			cout << ans.mx << endl;
		}
	}
	return 0;
}

// #include <bits/stdc++.h>
// #include <vector>
// #include <set>
// #include <map>
// #include <string>
// #include <cstdio>
// #include <cstdlib>
// #include <climits>
// #include <utility>
// #include <algorithm>
// #include <cmath>
// #include <queue>
// #include <stack>
// #include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
// //setbase - cout << setbase (16); cout << 100 << endl; Prints 64
// //setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
// //setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
// //cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
// using namespace std;
// using namespace __gnu_pbds;

// #define sp << " " <<
// #define mod 1000000007
// #define PI 3.14159265358979323
// #define y second
// #define x first
// #define pb push_back
// #define mp make_pair
// #define mem(a,b) memset(a,b,sizeof(a))
// #define sz(a) a.size()
// #define pqueue priority_queue< ll >
// //#define pdqueue priority_queue< ll,vector<ll> ,greater< ll > >
// #define codejamDebug(x) cout<<"Case #"<<x<<": ";
// #define debug(x) cout<<#x<<" :"<<x<<endl;
// #define rep(i,n) for(long long i=0;i<n;i++)
// #define f(i,a,b) for(long long i = a; i < b; i++)
// #define fd(i,a,b) for(long long i = a; i >=b; i--)
// #define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// typedef long long int           ll;
// typedef long double             ld;
// typedef unsigned long long int ull;
// typedef vector <int>            vi;
// typedef vector <ll>            vll;
// typedef pair <int, int>        pii;
// typedef pair <ll, ll>          pll;
// typedef vector < pii >        vpii;
// typedef vector < pll >        vpll;
// typedef vector <string>         vs;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// //Handle:cyber_rajat
// //input array
// int a[100005];
// struct dat
// {
// 	//Use required attributes
// 	int mn;

// 	//Default Values
// 	dat() : mn(1e9) {};
// };

// struct SegTree
// {
// 	int N;
// 	vector<dat> st;
// 	vector<bool> cLazy;
// 	vector<int> lazy;

// 	void init(int n)
// 	{
// 		N = n;
// 		st.resize(4 * N + 5);
// 		cLazy.assign(4 * N + 5, false);
// 		lazy.assign(4 * N + 5, 0);
// 	}

// 	//Write reqd merge functions
// 	void merge(dat &cur, dat &l, dat &r) 
// 	{
// 		cur.mn = min(l.mn, r.mn);
// 	}
	
// 	//Handle lazy propagation appriopriately
// 	void propagate(int node, int L, int R)
// 	{
// 		if(L != R)
// 		{
// 			cLazy[node*2] = 1;
// 			cLazy[node*2 + 1] = 1;
// 			lazy[node*2] = lazy[node];
// 			lazy[node*2 + 1] = lazy[node]; 
// 		}
// 		st[node].mn = lazy[node];
// 		cLazy[node] = 0;
// 	}

// 	void build(int node, int L, int R)
// 	{
// 		//Write reqd base case
// 		if(L==R)
// 		{
// 			st[node].mn = a[L];
// 			return;
// 		}
// 		int M=(L + R)/2;
// 		build(node*2, L, M);
// 		build(node*2 + 1, M + 1, R);
// 		merge(st[node], st[node*2], st[node*2+1]);
// 	}

// 	dat Query(int node, int L, int R, int i, int j)
// 	{
// 		if(cLazy[node])
// 			propagate(node, L, R);
// 		if(j<L || i>R)
// 			return dat();
// 		if(i<=L && R<=j)
// 			return st[node];
// 		int M = (L + R)/2;
// 		dat left=Query(node*2, L, M, i, j);
// 		dat right=Query(node*2 + 1, M + 1, R, i, j);
// 		dat cur;
// 		merge(cur, left, right);
// 		return cur;
// 	}

// 	dat pQuery(int node, int L, int R, int pos)
// 	{
// 		if(cLazy[node])
// 			propagate(node, L, R);
// 		if(L == R)
// 			return st[node];
// 		int M = (L + R)/2;
// 		if(pos <= M)
// 			return pQuery(node*2, L, M, pos);
// 		else
// 			return pQuery(node*2 + 1, M + 1, R, pos);
// 	}	

// 	void Update(int node, int L, int R, int i, int j, int val)
// 	{
// 		if(cLazy[node])
// 			propagate(node, L, R);
// 		if(j<L || i>R)
// 			return;
// 		if(i<=L && R<=j)
// 		{
// 			cLazy[node] = 1;
// 			lazy[node] = val;
// 			propagate(node, L, R);
// 			return;
// 		}
// 		int M = (L + R)/2;
// 		Update(node*2, L, M, i, j, val);
// 		Update(node*2 + 1, M + 1, R, i, j, val);
// 		merge(st[node], st[node*2], st[node*2 + 1]);
// 	}

// 	void pUpdate(int node, int L, int R, int pos, int val)
// 	{
// 		if(cLazy[node])
// 			propagate(node, L, R);
// 		if(L == R)
// 		{
// 			cLazy[node] = 1;
// 			lazy[node] = val;
// 			propagate(node, L, R);
// 			return;
// 		}
// 		int M = (L + R)/2;
// 		if(pos <= M)
// 			pUpdate(node*2, L, M, pos, val);
// 		else
// 			pUpdate(node*2 + 1, M + 1, R, pos, val);
// 		merge(st[node], st[node*2], st[node*2 + 1]);
// 	}

// 	dat query(int pos)
// 	{
// 		return pQuery(1, 1, N, pos);
// 	}

// 	dat query(int l, int r)
// 	{
// 		return Query(1, 1, N, l, r);
// 	}

// 	void update(int pos, int val)
// 	{
// 		pUpdate(1, 1, N, pos, val);
// 	}

// 	void update(int l, int r, int val)
// 	{
// 		Update(1, 1, N, l, r, val);
// 	}
// };

// int main(int argc, char const *argv[])
// {
// 	sync;
// 	int n, m;
// 	cin >> n >> m;
// 	rep(i,n){
// 		cin >> a[i+1];
// 	}
// 	SegTree seg;
// 	seg.init(n);
// 	seg.build(1,1,n);
// 	int op, u, v;
// 	rep(i,m){
// 		cin >> op >> u >> v;
// 		if(op == 1){
// 			seg.update(u+1,v);
// 		}else{
// 			dat ans = seg.query(u+1,v);
// 			cout << ans.mn << endl;
// 		}
// 	}
// 	return 0;
// }


// #include <bits/stdc++.h>
// #include <vector>
// #include <set>
// #include <map>
// #include <string>
// #include <cstdio>
// #include <cstdlib>
// #include <climits>
// #include <utility>
// #include <algorithm>
// #include <cmath>
// #include <queue>
// #include <stack>
// #include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
// //setbase - cout << setbase (16); cout << 100 << endl; Prints 64
// //setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
// //setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
// //cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
// using namespace std;
// using namespace __gnu_pbds;

// #define sp << " " <<
// #define mod 1000000007
// #define PI 3.14159265358979323
// #define y second
// #define x first
// #define pb push_back
// #define mp make_pair
// #define mem(a,b) memset(a,b,sizeof(a))
// #define sz(a) a.size()
// #define pqueue priority_queue< ll >
// //#define pdqueue priority_queue< ll,vector<ll> ,greater< ll > >
// #define codejamDebug(x) cout<<"Case #"<<x<<": ";
// #define debug(x) cout<<#x<<" :"<<x<<endl;
// #define rep(i,n) for(long long i=0;i<n;i++)
// #define f(i,a,b) for(long long i = a; i < b; i++)
// #define fd(i,a,b) for(long long i = a; i >=b; i--)
// #define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// typedef long long int           ll;
// typedef long double             ld;
// typedef unsigned long long int ull;
// typedef vector <int>            vi;
// typedef vector <ll>            vll;
// typedef pair <int, int>        pii;
// typedef pair <ll, ll>          pll;
// typedef vector < pii >        vpii;
// typedef vector < pll >        vpll;
// typedef vector <string>         vs;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// //Handle:cyber_rajat
// const int N = 1e5 + 5;
// ll a[N], seg[N<<2];

// void build(int node, int start, int end){
// 	if(start == end){
// 		seg[node] = a[start];
// 		return;
// 	}
// 	int mid = (start + end)/2;
// 	build(2*node, start, mid);
// 	build(2*node + 1, mid + 1, end);
// 	seg[node] = seg[2*node] + seg[2*node + 1];
// }

// void update(int node, int start, int end, int idx, ll val){
// 	if(start == end){
// 		seg[node] = val;
// 		a[node] = val;
// 		return;
// 	}
// 	int mid = (start + end)/2;
// 	if(start <= idx && idx <= mid){
// 		update(2*node,start,mid,idx,val);
// 	}else{
// 		update(2*node+1,mid+1,end,idx,val);
// 	}
// 	seg[node] = seg[2*node] + seg[2*node+1];
// }

// ll query(int node, int start, int end, int l, int r){
// 	if(end < l || start > r){
// 		return 0;
// 	}

// 	if(l <= start && end <= r){
// 		return seg[node];
// 	}
// 	int mid = (start + end)/2;
// 	ll p1 = query(2*node, start, mid, l, r);
// 	ll p2 = query(2*node+1,mid+1,end, l, r);
// 	ll p = p1 + p2;
// 	return p;
// }

// int main(int argc, char const *argv[])
// {
// 	sync;
// 	int n, m;
// 	cin >> n >> m;
// 	rep(i,n){
// 		cin >> a[i];
// 	}
// 	build(1,0,n-1);
// 	int op, u, v;
// 	rep(i,m){
// 		cin >> op >> u >> v;
// 		if(op == 1){
// 			update(1,0,n-1,u,v);
// 		}else{
// 			v--;
// 			ll ans = query(1,0,n-1,u,v);
// 			cout << ans << endl;
// 		}
// 	}
// 	return 0;
// }
