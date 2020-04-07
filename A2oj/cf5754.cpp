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
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		ll len=s.size();
		string dumm1="RGB",dumm2="GBR",dumm3="BRG";
		ll i=0;
		ll ans=10000000;
		string start="";
		while(i+k<=len)
		{
			ll pos1=0,pos2=0,pos3=0;
			ll index=0;
			f(j,i,i+k)
			{
				if(s[j]!=dumm1[index%3])
					pos1++;
				index++;
			}
			index=0;
			f(j,i,i+k)
			{
				if(s[j]!=dumm2[index%3])
					pos2++;
				index++;
			}
			index=0;
			f(j,i,i+k)
			{
				if(s[j]!=dumm3[index%3])
					pos3++;
				index++;
			}
			ans=min(ans,min(pos1,min(pos2,pos3)));
			i++;
		}
		cout<<ans<<endl;
	}
	// if(j==i)
				// {
				// 	if(s[j]=='R')
				// 		start=start+"R";
				// 	else if(s[j]=='G')
				// 		start=start+"G";
				// 	else
				// 		start=start+"B";
				// }
	return 0;
}