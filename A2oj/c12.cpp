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
ll power[1000005]={0};

int main(int argc, char const *argv[])
{
	sync;
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	string s;
	cin>>s;
	ll a,b;
	cin>>a>>b;
	ll j=0;
	bool ans1[1000005]={false},ans2[1000005]={false};
	rep(i,sz(s))
	{
		j=(j*10+s[i]-'0')%a;
		if(!j)ans1[i]=true;
	}
	j=0;
	power[0]=1;
	f(i,1,sz(s)+1)power[i]=(power[i-1]*10)%b;
	fd(i,sz(s)-1,0)
	{
		j=((s[i]-'0')*power[10,sz(s)-i-1] + j)%b;
		if(!j)ans2[i]=true;
	}
	ll index=-1;
	rep(i,sz(s))
	{
		if(i!=sz(s)-1 && ans1[i] && ans2[i+1] && s[i+1]!='0')
			index=i;
	}
	if(index==-1)cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		rep(i,index+1)cout<<s[i];
		cout<<endl;
		f(i,index+1,sz(s))cout<<s[i];
	}
	return 0;
}
