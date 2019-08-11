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
ll a[2005][2005]={0};
ll dp1[2005][2005]={0},dp2[2005][2005]={0};
ll dp3[2005][2005]={0},dp4[2005][2005]={0};

int main(int argc, char const *argv[])
{
	sync;
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	ll n;
	cin>>n;
	f(i,1,n+1)
	{
		f(j,1,n+1)
		{
			cin>>a[i][j];
		}
	}
	f(i,1,n+1)
	{
		f(j,1,n+1)
		{
			dp1[i][j]=dp1[i-1][j-1]+a[i][j];
			dp2[i][j]=dp2[i-1][j+1]+a[i][j];
		}
	}
	fd(i,n,1)
	{
		f(j,1,n+1)
		{
			dp3[i][j]=dp3[i+1][j-1]+a[i][j];
			dp4[i][j]=dp4[i+1][j+1]+a[i][j];
		}
	}
	ll dp[2]={-1,-1};
	ll x[2]={0},y[2]={0};
	f(i,1,n)
	{
		f(j,1,n)
		{
			ll bit=(i+j)&1;
			ll val=dp1[i][j]+dp2[i][j]+dp3[i][j]+dp4[i][j]-3*a[i][j];
			if(val>dp[bit])
			{
				dp[bit]=val;
				x[bit]=i;
				y[bit]=j;
			}
		}
	}
	cout<<dp[0]+dp[1]<<endl;
	cout<<x[0] sp y[0] sp x[1] sp y[1]<<endl;
	return 0;
}
