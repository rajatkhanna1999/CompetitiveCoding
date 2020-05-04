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
#define sc(a) scanf("%d",&a)
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
const int INF = 1e9;
const int N = 1e5 + 5;
vector<pii> adj[N];
int n;
//declare n globally

int dijkstra(int source, int destination, int t) {
    int dist[n+5], parent[n+5];
    bool visited[n+5];
    for(int i=1; i<=n; i++)
    {
    	dist[i] = INF;
    	visited[i] = false;
    	parent[i] = -1;
    }
    dist[source] = 0;
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.push({0,source});
    while(!pq.empty())
    {
    	int u = pq.top().second;
    	pq.pop(); 
    	if(visited[u])continue;

    	visited[u] = true;
    	for(auto it: adj[u])
    	{
    		int v = it.first;
    		int w = it.second;
    		if(dist[v]>(dist[u]+w))
    		{
    			dist[v] = dist[u] + w;
    			parent[v] = u;
    			pq.push({dist[v],v});
    		}
    	}   	
    }
    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
    	if(dist[i]<=t)cnt++;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
	sync;
	sc(n);
	int source, t, m;
	sc(source),sc(t),sc(m);
	int u, v, w;
	rep(i,m)
	{
		sc(u),sc(v),sc(w);
		//Adding Reverse Edge
		adj[v].pb({u,w});
	}
	int ans = dijkstra(source,n,t);
	printf("%d\n",ans);
	return 0;
}
