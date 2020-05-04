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
const int N = 200000+5;
vector<int> adj[N];
map<pii, int> my;

void bfs(int start, int end, int n)
{
	queue<int> q;
	int parent[n+5];
	bool visited[n+5];
	memset(parent,-1,sizeof(parent));
	memset(visited,false,sizeof(visited));
	q.push(start);
	parent[start]=-1;
	while(!q.empty())
	{
		int curr = q.front();
		if(curr==end)
		{
			break;
		}
		visited[curr] = true;
		q.pop();
		for(auto x:adj[curr])
		{
			if(!visited[x])
			{
				parent[x]=curr;
				q.push(x);
			}
		}
	}
	for(int v=end; v!=-1; v=parent[v])
	{
		if(parent[v]==-1)
		{
			break;
		}
		my[{min(v,parent[v]),max(v,parent[v])}]++;
	}
}

int main(int argc, char const *argv[])
{
	sync;
	int t;
	cin >> t;
	while(t--)
	{
		my.clear();
		memset(adj,0,sizeof(adj));
		int n, m, a ,b ,c;
		cin >> n >> m >> a >> b >> c;
		int p[m+5];
		rep(i,m)cin >> p[i];

		sort(p,p+m);
		rep(i,m)
		{
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		bfs(a,b,n);
		bfs(b,c,n);
		vector<int> ans;
		for(auto x:my)
		{
			ans.pb(x.second);
			//cout << x.second << endl;
		}
		sort(ans.begin(),ans.end());
		reverse(ans.begin(),ans.end());
		int cnt=0;
		ll sum=0;
		for(auto x:ans)
		{
			sum+=(x*p[cnt]);
			cnt++;
		}
		for(int i=cnt; i<m; i++)sum+=p[i];

		cout << sum << endl;
	}
	return 0;
}
