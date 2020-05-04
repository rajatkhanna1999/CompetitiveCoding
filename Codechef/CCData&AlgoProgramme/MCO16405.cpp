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
int a[N];
int n, m, grp = 0;
vector<int> ng[N], g[N], rg[N], todo;
int comp[N], indeg[N];
ll sum[N], dp[N]; 
bool vis[N], visited[N];

void dfs(int k)
{
	vis[k]=1;
	for(auto it:g[k])
	{
		if(!vis[it])
			dfs(it);
	}
	todo.push_back(k);
}

void dfs2(int k, int val)
{
	comp[k]=val;
	for(auto it:rg[k])
	{
		if(comp[it]==-1)
			dfs2(it, val);
	}
}

void sccAddEdge(int from, int to)
{
	g[from].push_back(to);
	rg[to].push_back(from);
}

void scc()
{
	for(int i=1;i<=n;i++)
		comp[i]=-1;

	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
			dfs(i);
	}

	reverse(todo.begin(), todo.end());

	for(auto it:todo)
	{
		if(comp[it]==-1)
		{
			dfs2(it, ++grp);
		}
	}
}

vector<int> topo;

void dfss(int k)
{
	visited[k]=true;
	for(auto it:ng[k])
	{
		if(!visited[it]){
			dfss(it);
		}
	}
	topo.pb(k);
}

int main(int argc, char const *argv[])
{
	sync;

	cin >> n >> m;
	for(int i=1; i<=n; i++)cin >> a[i];

	int u, v;
	rep(i,m){
		cin >> u >> v;
		sccAddEdge(u,v);
	}
	scc();
	memset(sum,0,sizeof(sum));
	memset(dp,0,sizeof(dp));
	for(int i=1; i<=n; i++){
		sum[comp[i]] += a[i];
	}
	for(int i=1; i<=n; i++){
		for(auto x:g[i]){
			if(comp[i]!=comp[x]){
				ng[comp[i]].pb(comp[x]);
			}
		}
	}

	memset(visited,false,sizeof(visited));
	for(int i=1; i<=grp; i++){
		if(!visited[i]){
			dfss(i);
		}
	}

	//To topoligically sort -> reverse
	//reverse(topo.begin(),topo.end());

	for(auto v: topo){
		dp[v] = sum[v];
		for(auto x: ng[v]){
			dp[v] = max(dp[v],sum[v]+dp[x]);
		}
	}

	for(int i=1; i<=n; i++){
		cout << dp[comp[i]] << " ";
	}
	cout << endl;
	return 0;
}
