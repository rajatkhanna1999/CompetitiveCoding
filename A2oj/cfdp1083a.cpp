#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define PI 3.14159265358979323
#define debug(x) cout<<"Case "<<x<<": "
#define For(i,n) for(long long i=0;i<n;i++)
#define Frabs(i,a,b) for(long long i = a; i < b; i++)
#define Frabr(i,a,b) for(long long i = a; i >=b; i--)
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

//Handle:cyber_rajat
ll gas[300005],dp[300005];
vector<pair<ll,ll> > adj[300005];
ll ans=0;
bool visited[300005]={0};

void dfs(ll a)
{
	dp[a]=gas[a];
	ans=max(dp[a],ans);
	visited[a]=true;
	for(ll i=0;i<adj[a].size();i++)
	{
		if(!visited[adj[a][i].first])
		{
			dfs(adj[a][i].first);
			ans=max(ans,dp[a]+dp[adj[a][i].first]-adj[a][i].second);
			dp[a]=max(dp[a],dp[adj[a][i].first]+gas[a]-adj[a][i].second);
		}
	}
}

int main(int argc, char const *argv[])
{
	sync;
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>gas[i];
	for(ll i=1;i<n;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
