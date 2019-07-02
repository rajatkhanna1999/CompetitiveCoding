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

ll factorial[1005];

void fact()
{
	factorial[0]=1;
	factorial[1]=1;
	for(ll i=2;i<=1005;i++)
	{
		factorial[i] = (factorial[i-1]*i)%mod;
		//cout<<factorial[i]<<" ";
	}

}

int main(int argc, char const *argv[])
{
	sync;
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	    fact();
		ll n;
		ll q;
		cin>>n>>q;
		ll arr[n+5];
		rep(i,n)cin>>arr[i];  
		ll L1,L2,R1,R2;
		ll a=0;
		while(q--)
		{
			ll L,R;
			cin>>L1>>L2>>R1>>R2;
			L = (L1*a + L2)%n;
			R = (R1*a + R2)%n;
			ll lower=min(L,R);
			ll Higher=max(L,R);
			map< ll,ll > mymap;
			f(i,lower,Higher+1)mymap[arr[i]]++;
			map< ll,ll >::iterator it;
			ll denom=1;
			for(it=mymap.begin();it!=mymap.end();it++)
			{
				if((it->second)>1)
					denom=denom*factorial[it->first];
			}
			//cout<<abs(R-L)+1<<endl;
			ll num=factorial[abs(R-L)+1];
			ll ans=num/denom;
			ans = ans % mod;
			a = ans;
			cout<<a<<endl;
		}
	
	return 0;
}