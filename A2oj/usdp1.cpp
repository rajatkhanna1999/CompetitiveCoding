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
ll n,k,dp[100005][4],painted[100005];
bool visited[100005][4];
vector<ll> adj[100005];

void dfs(ll parent,ll at,ll color)
{

	if(visited[at][color])
		return;
	visited[at][color]=true;
	if(painted[at]!=0 && painted[at]!=color)
	{
		dp[at][color]=0;
		return;
	}
	ll c1,c2;
	if(color==1)
		c1=2,c2=3;
	else if(color==2)
		c1=1,c2=3;
	else
		c1=1,c2=2;
	dp[at][color]=1;
	for(ll i=0;i<adj[at].size();i++)
	{
		if(adj[at][i]!=parent)
		{
			dfs(at,adj[at][i],c1);
			dfs(at,adj[at][i],c2);
			dp[at][color]*=dp[adj[at][i]][c1]+dp[adj[at][i]][c2];
			dp[at][color]%=mod;
		}
	}
}

int main(int argc, char const *argv[])
{
	ifstream cin("barnpainting.in");
	ofstream cout("barnpainting.out");
	sync;
	cin>>n>>k;
	for(ll i=0;i<n-1;i++)
	{
		ll a,b;
		cin>>a>>b;
		a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(ll i=0;i<k;i++)
	{
		ll a,b;
		cin>>a>>b;
		painted[a-1]=b;
	}
	dfs(-1,0,1);
	dfs(-1,0,2);
	dfs(-1,0,3);
	cout<<(dp[0][1]+dp[0][2]+dp[0][3])%mod<<endl;

	return 0;
}
