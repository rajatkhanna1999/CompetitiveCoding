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
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,x;
		cin>>n;
		vll v;
		ll ans=0;
		rep(i,n)cin>>x,v.pb(x);
		sort(v.begin(),v.end());
		ll len=v.size();
		//rep(i,len)cout<<v[i]<<" ";
		if(len==2)
			ans=v[0]+v[1];
		else
		{
			ll Max=-1,secMax=-1;
			Max=v[len-1];
			fd(i,len-2,0)
			{
				if(v[i]!=Max)
				{
					secMax=v[i];
					break;
				}
			}
			if(secMax==-1)
				ans=2*Max;
			else
			{
				ll gcd1=v[0];
				ll gcd2=v[0];
				f(i,1,len)
				{
					if(v[i]==Max)
						break;
					else
						gcd1=__gcd(v[i],gcd1);
				}
				f(i,1,len)
				{
					if(v[i]==secMax)
						continue;
					else
						gcd2=__gcd(v[i],gcd2);
				}
				ll possibleAns1=Max+gcd1;
				ll possibleAns2=secMax+gcd2;
				//cout<<possibleAns2<<" "<<possibleAns1<<" "<<gcd1<<" "<<gcd2<<" "<<Max<<" "<<secMax;
				ans=max(possibleAns1,possibleAns2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
