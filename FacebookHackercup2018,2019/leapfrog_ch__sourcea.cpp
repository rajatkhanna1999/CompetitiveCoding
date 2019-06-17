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
	freopen("leapfrog_ch_.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	ll t,T=1;
	cin>>t;
	while(t--)
	{
		codejamDebug(T);
		ll cntA=0,cntB=0,cntDot=0;
		string s;
		cin>>s;
		ll len=s.size();
		rep(i,len)
		{
			if(s[i]=='A')
				cntA++;
			else if(s[i]=='B')
				cntB++;
			else
				cntDot++;
		}
		if(cntDot==0)
			cout<<"N"<<endl;
		else if(cntA==0)
			cout<<"N"<<endl;
		else
		{
			if((len-1)%2==0)
			{
				ll val=(len-1)/2;
				if(cntB>=val && cntB<(len-1))
					cout<<"Y"<<endl;
				else
					cout<<"N"<<endl;
			}
			else
			{
				ll val=(len-1)/2 + 1;
				if(cntB>=val && cntB<(len-1))
					cout<<"Y"<<endl;
				else
					cout<<"N"<<endl;
			}
		}
		T++;
	}
	return 0;
}
