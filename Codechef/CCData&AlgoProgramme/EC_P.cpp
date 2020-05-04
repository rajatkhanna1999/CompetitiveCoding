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
const int M = 1e5 + 5;
int tim=0;
int u[N], v[N], vis[N];
int tin[N], tout[N], isBridge[M], minAncestor[N];
vector<pair<int, int> > g[N]; //vertex, index of edge

void dfs(int k, int par)
{
	vis[k]=1;
	tin[k]=++tim;
	minAncestor[k]=tin[k];
	for(auto it:g[k])
	{
		if(it.first==par)
			continue;
		if(vis[it.first])
		{	
			minAncestor[k]=min(minAncestor[k], tin[it.first]);
			continue;
		}
		dfs(it.first, k);
		minAncestor[k]=min(minAncestor[k], minAncestor[it.first]);
		if(minAncestor[it.first]>tin[k])
			isBridge[it.second]=1;
	}
	tout[k]=tim;
}

int main(int argc, char const *argv[])
{
	sync;
	int t, T = 1;
	cin >> t;
	while(t--)
	{
		cout << "Caso #"<< T <<endl;
		T++;
		tim = 0;
		memset(vis, 0, sizeof(vis));
		memset(isBridge, 0, sizeof(isBridge));
		memset(g, 0, sizeof(g));
		int n, m;
		cin >> n >> m;
		for(int i=1; i<=m; i++){
			cin >> u[i] >> v[i];
			g[u[i]].pb({v[i],i});
			g[v[i]].pb({u[i],i});
			if(u[i]>v[i])swap(u[i],v[i]);
		}
		dfs(1,0);
		vector<pair<int,int>> ans;
		for(int i=1; i<=m; i++){
			if(isBridge[i])ans.pb({u[i],v[i]});
		}
		sort(ans.begin(),ans.end());
		if(!ans.size())cout<<"Sin bloqueos"<<endl;
		else {
			cout<<ans.size()<<endl;
			for(auto it:ans)cout<<it.first<<" "<<it.second<<endl;
		}
	}
	return 0;
}
