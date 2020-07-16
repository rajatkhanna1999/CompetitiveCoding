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
const int N = 500005;
vector<ll> adj[N];
ll up[N][30];
ll numNodes2[N], numNodes1[N];
ll n, a, b;
ll timer, l;
ll tin[N], tout[N];

//cp-algorithms - lca_binary_lifting
void dfs(ll v, ll p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    
    for (int i = 1; i <= l; ++i){
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for (ll u : adj[v]) {
        if (u != p){
            dfs(u, v);
        }
    }
    
    tout[v] = ++timer;
}

void fillNodes(ll v, ll p){
	for(ll u: adj[v]){
		if(u != p){
			fillNodes(u, v);
		}
	}
	
	ll tmp = v, tmp1 = a, tmp2 = b, val = v, idx = 0;
	while(tmp1 > 0){
		if(tmp1%2 == 1){
			val = up[val][idx];
		}
		idx++;
		tmp1 /= 2;
	}
	numNodes1[val] += numNodes1[v];

	val = v, idx = 0;
	while(tmp2 > 0){
		if(tmp2%2 == 1){
			val = up[val][idx];
		}
		idx++;
		tmp2 /= 2;
	}
	numNodes2[val] += numNodes2[v];
}

int main(int argc, char const *argv[])
{
	sync;
	ll t, T = 1;
	cin >> t;
	while(t--)
	{
		codejamDebug(T);
		T++;
		cin >> n >> a >> b;
		for(int i = 0; i <= n; i++){
			numNodes1[i] = 1, numNodes2[i] = 1;
			adj[i].clear();
		}
		ll u;
		for(int i = 1; i < n; i++){
			cin >> u;
			adj[u].pb(i+1);
			adj[i+1].pb(u);
		}
		l = ceil(log2(n));
		dfs(1, 0);
		ld ans = 0;
		ll numerator = 0;
		fillNodes(1,0);
		for(int i = 1; i <= n; i++){
			numerator = numerator + numNodes1[i]*n + numNodes2[i]*n - numNodes1[i]*numNodes2[i];
		}
		ans = (numerator*1.0)/(n*n);
		cout << setprecision (14) << ans << endl;
	}
	return 0;
}
