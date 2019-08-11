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
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	ll n;
	cin>>n;
	ll t1=n,t2=n;
	ll s1=0,f1=0,s2=0,f2=0;
	if(n<18)
	{
		if(n==4)cout<<"4";
		else if(n==7)cout<<"7";
		else if(n==14)cout<<"77";
		else if(n==8)cout<<"44";
		else if(n==12)cout<<"444";
		else if(n==16)cout<<"4444";
		else if(n==11)cout<<"47";
		else if(n==15)cout<<"447";
		else cout<<"-1";
		return 0;
	}
	while(t1)
	{
		if(t1%7==0)t1-=7,s1++;
		else t1-=4,f1++;
	}
	while(t2)
	{
		if(t2%4==0)t2-=4,f2++;
		else t2-=7,s2++;
	}
	ll cnt1=s1+f1,cnt2=s2+f2;
	if(cnt1<cnt2)
	{
		rep(i,f1)cout<<"4";
		rep(i,s1)cout<<"7";
	}
	else if(cnt2<cnt1)
	{
		rep(i,f2)cout<<"4";
		rep(i,s2)cout<<"7";
	}
	else
	{
		if(s1<s2)
		{
			rep(i,f1)cout<<"4";
			rep(i,s1)cout<<"7";
		}
		else
		{
			rep(i,f2)cout<<"4";
			rep(i,s2)cout<<"7";
		}
	}
	return 0;
}
