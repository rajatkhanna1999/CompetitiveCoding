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

int main(int argc, char const *argv[])
{
	sync;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin >> n;
		ll a[n+5];
		rep(i,n)cin >> a[i+1];

		ll dp1[n+5]={0},dp2[n+5]={0};
		ll dp3[n+5]={0},dp4[n+5]={0};
		//prefixMax
		for(int i=1; i<=n; i++)
		{
			dp1[i]=max(dp1[i-1]+a[i],a[i]);
		}
		//prefixMix
		for(int i=1; i<=n; i++)
		{
			dp2[i]=min(dp2[i-1]+a[i],a[i]);
		}
		// suffixMax
		for(int i=n; i>=1; i--)
		{
			dp3[i]=max(dp3[i+1]+a[i],a[i]);
		}
		// suffixMin
		for(int i=n; i>=1; i--)
		{
			dp4[i]=min(dp4[i+1]+a[i],a[i]);
		}
		ll ans = 0;
		ll temp;
		for(int i=1; i<n; i++)
		{
			temp = max(abs(dp1[i]-dp4[i+1]),abs(dp2[i]-dp3[i+1]));
			//cout<<temp sp i sp dp1[i] sp dp2[i] sp dp3[i+1] sp dp4[i+1];
			ans = max(ans,temp);
		}
		cout << ans << endl;
	}
	return 0;
}
