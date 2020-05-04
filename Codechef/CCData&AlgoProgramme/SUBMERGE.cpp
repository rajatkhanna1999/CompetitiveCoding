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
const int N = 1e5 + 5;

int n, m;
int timer;
int tin[N], low[N];
bool vis[N], isArticulation[N];
vector<int> g[N];

void dfs(int u, int par)
{
	vis[u] = 1;
	tin[u] = low[u] = ++timer;
	int children = 0;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		if(vis[it])
			low[u] = min(low[u], tin[it]);
		else
		{
			dfs(it, u);
			low[u] = min(low[u], low[it]);
			if(low[it] >= tin[u] && par != -1)
				isArticulation[u] = 1;
			children++;
		}
	}
	if(par == -1 && children > 1)
		isArticulation[u] = 1;
}

void articulationPoints()
{
	timer = 0;
	memset(vis, 0, sizeof(vis));
	memset(isArticulation, 0, sizeof(isArticulation));
	memset(tin, -1, sizeof(tin));
	memset(low, -1, sizeof(low));
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
			dfs(i, -1);
	}
}

int main(int argc, char const *argv[])
{
	sync;
	while(true){
		cin >> n >> m;
		if(n==0 && m==0){
			break;
		}
		for(int i=0; i<=n; i++)g[i].clear();
	
		int u, v;
		rep(i,m){
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		articulationPoints();
		int ans = 0;
		for(int i=1; i<=n; i++){
			if(isArticulation[i]==1)ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
