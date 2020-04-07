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
	ll n;
	cin>>n;
	ll a[n+5]={0};
	rep(i,n)cin>>a[i];
	sort(a,a+n);
	set<ll> s;
	rep(i,n)s.insert(a[i]);
	if(sz(s)>3)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	vll v;
	set<ll>::iterator it;
	for(it=s.begin();it!=s.end();it++)
		v.pb(*it);
	if(sz(s)==1)
	{
		cout<<"0"<<endl;
	}
	else if(sz(s)==2)
	{
		ll val=v[1]-v[0];
		if(val%2==0)
			cout<<val/2<<endl;
		else
			cout<<val<<endl;
	}
	else
	{
		ll val1=v[2]-v[1];
		ll val2=v[1]-v[0];
		if(val1==val2)
			cout<<val1<<endl;
		else
			cout<<"-1"<<endl;
	}
}
