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
#define debug(x) cout<<"Case "<<x<<": "
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

int main(int argc, char const *argv[])
{
	sync;
	freopen("graphs_as_a_service.txt","r",stdin);
	freopen("graphme.txt","w",stdout);
	ll t,T;
	cin>>t;
	ll maxValue=1e9;
	T=1;
	while(t--)
	{
		codejamDebug(T);
		ll n,m;
		cin>>n>>m;
		//dp stores the distance
		ll graph[n+2][n+2],dp[n+2][n+2];
		for(ll i=1; i<=n; i++)
		{
		    for(ll j=1; j<=n; j++)
		    {
			if(i==j)
			{
				graph[i][j]=0;
				dp[i][j]=0;
			}
			else 
			{
				graph[i][j]=maxValue;
				dp[i][j]=maxValue;
			}
		    }
        	}

        //Making a vector
        vector<pair< pair<ll,ll>, ll >> kya;
	//Inputting
        for(ll i=0;i<m;i++)
	{
            ll a,b,c;
            cin>>a>>b>>c;
            graph[a][b]=c;
            graph[b][a]=c;
            dp[a][b]=c;
            dp[b][a]=c;
            kya.pb(mp(mp(a,b), c));
        }


		// ll u[n+5],v[n+5],w[n+5];
		// rep(i,m)
		// {
		// 	ll a,b,c;
		// 	cin>>a>>b>>c;
		//     v.push_back(make_pair(make_pair(x,y), z));

		// 	// u[i]=a,v[i]=b,w[i]=c;
		// 	// graph[a][b]=c;
		// 	// graph[b][a]=c;
		// 	// dp[a][b]=c;
		// 	// dp[b][a]=c;
		// }

        	//Floyad-warshall
		for(ll k=1;k<=n;k++)
		{
		    for(ll i=1;i<=n;i++)
		    {
			for(ll j=1;j<=n;j++)
			{
			    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		    }
        	}

		bool flag=true;
		for(ll i=1;i<=n;i++)
		{
		    for(ll j=1;j<=n;j++)
		    {
			if(graph[i][j]!=maxValue && dp[i][j]!=graph[i][j])
				flag=false;
		    }
		}

		if(!flag)
		{
			cout<<"Impossible"<<endl;
		}
		else
		{
		    cout<<m<<endl;
		    for(ll i=0;i<m;i++)
			cout<<kya[i].x.x sp kya[i].x.y sp kya[i].y<<endl;
		}
		T++;
	}
	return 0;
}
