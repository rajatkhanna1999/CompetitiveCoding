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
struct BIT
{
	ll N;
	vector<ll> bit;

	void init(ll n)
	{
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(ll index, ll value)
	{
		while(index <= N)
		{
			bit[index] += value;
			index += index & -index;
		}
	}

	ll query(ll index)
	{
		ll ans = 0;
		while(index > 0)
		{
			ans += bit[index];
			index -= index & -index;
		}
		return ans;
	}

	ll queryRange(ll l, ll r)
	{
		return query(r) - query(l - 1);
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
		ll b[n+5],a[n+5];
		rep(i,n){
			cin >> b[i+1];
			a[i+1] = sign*b[i+1];
			sign *= -1;
		}
		BIT fenw;
		BIT prefix;
		fenw.init(n);
		prefix.init(n);
		for(int i = 1; i <= n; i++){
			fenw.update(i,i*a[i]);
			prefix.update(i,a[i]);
		}
		rep(i,q){
			char c;
			ll u, v;
			cin >> c >> u >> v;
			if(c == 'U'){
				if(u%2 == 0){
					v *= -1;
				}
				fenw.update(u,-1*u*a[u]);
				fenw.update(u,u*v);
				prefix.update(u,-1*a[u]);
				prefix.update(u,v);
				a[u] = v;
			}else{
				ll temp = fenw.queryRange(u,v);
				//cout << temp << endl;
				ll temp1 = prefix.queryRange(u,v);
				//cout << temp1 << endl;
				temp -= temp1*(u-1);
				if(u%2 == 0){
					temp *= -1;
				}
				ans += temp;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
