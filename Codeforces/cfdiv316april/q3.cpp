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

#define mod 1000000007
#define PI 3.14159265358979323
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define pqueue priority_queue< ll >
//#define pdqueue priority_queue< ll,vector<ll> ,greater< ll > >
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
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	// ll a[5]={0};
	// ll n=3;
	// rep(i,n)cin>>a[i];
	// if(fish==1)
	// {
	// 	if(chicken>=2)
	// 		cout<<min(2,rabbit)+min(2,chicken)+1<<endl;
	//     else
	// 		cout<<3<<endl;
	// }
	// else if(fish==2)
	// {
	// 	cout<<min(2,rabbit)+min(2,chicken)<<endl;
	// }
	// else
	// {

	// }
	ll week[]={0,0,1,2,0,2,1};
	ll fish,rabbit,chicken;
	cin>>fish>>rabbit>>chicken;
	ll dp[10]={0};
	ll fishq=fish/3;
	ll rabbitq=rabbit/2;
	ll chickenq=chicken/2;
	ll val=min(fishq,min(rabbitq,chickenq));
	ll fishr=fish-val*3;
	ll rabbitr=rabbit-val*2;
	ll chickenr=chicken-val*2;
	ll days=val*7;
	ll extra=0;
	rep(i,7)
	{
		ll currentDay=i;
		ll total=0;
		ll x=fishr,y=rabbitr,z=chickenr;
		while(1)
		{
			if(week[currentDay]==0)
			{
				if(x==0)break;
				x--;
			}
			else if(week[currentDay]==1)
			{
				if(y==0)break;
				y--;
			}
			else
			{
				if(z==0)break;
				z--;
			}
			total++;
			currentDay++;
			currentDay%=7;
		}
		dp[i]=total;
	}
	rep(i,7)extra=max(extra,dp[i]);
	cout<<days+extra<<endl;
}
