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
//input array
ll a[200005];
struct data
{
	//Use required attributes
	ll val;

	//Default Values
	data() : val(0) {};
};

struct SegTree
{
	ll N;
	vector<data> st;
	vector<bool> cLazy;
	vector<ll> lazy;

	void init(ll n)
	{
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	void merge(data &cur, data &l, data &r) 
	{
		cur.val = l.val + r.val;
	}
	
	//Handle lazy propagation appriopriately
	void propagate(ll node, ll L, ll R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = lazy[node];
			lazy[node*2 + 1] = lazy[node]; 
		}
		st[node].val = lazy[node];
		cLazy[node] = 0;
	}

	void build(ll node, ll L, ll R)
	{
		//Write reqd base case
		if(L==R)
		{
			st[node].val = L*a[L];
			return;
		}
		ll M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	data Query(ll node, ll L, ll R, ll i, ll j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return data();
		if(i<=L && R<=j)
			return st[node];
		ll M = (L + R)/2;
		data left=Query(node*2, L, M, i, j);
		data right=Query(node*2 + 1, M + 1, R, i, j);
		data cur;
		merge(cur, left, right);
		return cur;
	}

	void pUpdate(ll node, ll L, ll R, ll pos, ll val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		ll M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	data query(ll l, ll r)
	{
		return Query(1, 1, N, l, r);
	}

	void update(ll pos, ll val)
	{
		pUpdate(1, 1, N, pos, val);
	}
};

struct SegTree1
{
	ll N;
	vector<data> st;
	vector<bool> cLazy;
	vector<ll> lazy;

	void init(ll n)
	{
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	void merge(data &cur, data &l, data &r) 
	{
		cur.val = l.val + r.val;
	}
	
	//Handle lazy propagation appriopriately
	void propagate(ll node, ll L, ll R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = lazy[node];
			lazy[node*2 + 1] = lazy[node]; 
		}
		st[node].val = lazy[node];
		cLazy[node] = 0;
	}

	void build(ll node, ll L, ll R)
	{
		//Write reqd base case
		if(L==R)
		{
			st[node].val = a[L];
			return;
		}
		ll M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	data Query(ll node, ll L, ll R, ll i, ll j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return data();
		if(i<=L && R<=j)
			return st[node];
		ll M = (L + R)/2;
		data left=Query(node*2, L, M, i, j);
		data right=Query(node*2 + 1, M + 1, R, i, j);
		data cur;
		merge(cur, left, right);
		return cur;
	}

	void pUpdate(ll node, ll L, ll R, ll pos, ll val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		ll M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	data query(ll l, ll r)
	{
		return Query(1, 1, N, l, r);
	}

	void update(ll pos, ll val)
	{
		pUpdate(1, 1, N, pos, val);
	}
};

int main(int argc, char const *argv[])
{
	sync;
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	ll t, T =1;
	cin >> t;
	while(t--)
	{
		codejamDebug(T);
		T++;
		ll n, q, ans = 0;
		cin >> n >> q;
		int sign = 1;
		ll b[200005];
		rep(i,n){
			cin >> b[i+1];
			a[i+1] = sign*b[i+1];
			sign *= -1;
		}
		SegTree seg;
		seg.init(n);
		seg.build(1,1,n);
		SegTree1 pre;
		pre.init(n);
		pre.build(1,1,n);
		rep(i,q){
			char c;
			ll u, v;
			cin >> c >> u >> v;
			if(c == 'U'){
				if(u%2 == 0){
					v *= -1;
				}
				seg.update(u,u*v);
				pre.update(u,v);
			}else{
				ll temp = seg.query(u,v).val;
				cout << temp << endl;
				ll temp1 = pre.query(u,v).val;
				cout << temp1 << endl;
				temp -= temp1*(u-1);
				if(u %2 == 0){
					temp *= -1;
				}
				//cout << temp << endl;
				ans += temp;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
