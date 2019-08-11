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
	ll n;
	cin>>n;
	ll a[n+5]={0};
	ll sum=0;
	rep(i,n)cin>>a[i],sum+=a[i];
	if(sum%3!=0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	ll val=sum/3;
	ll currSum=0;
	ll cnt=0,count[n+5]={0};
	//setting the value of j , We have to place 2 partions to divide into 3 parts
	fd(i,n-1,0)	
	{
		currSum+=a[i];
		if(currSum==val)
			count[i]=1;
	}
	fd(i,n-2,0)count[i]=count[i]+count[i+1];
	//Partitions
	currSum=0;
	rep(i,n-2)
	{
		currSum+=a[i];
		if(currSum==val)
			cnt+=count[i+2];
	}
	//i+2 is used because if i+1 is used it is for 2 parts for three parts atleast 1 element should be in 3rd part
	cout<<cnt<<endl;
	return 0;
}
