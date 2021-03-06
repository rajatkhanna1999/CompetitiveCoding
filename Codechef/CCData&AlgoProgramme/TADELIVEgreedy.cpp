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
bool compare(pll a, pll b)
{
	if(abs(a.x-a.y)==abs(b.x-b.y))
	{
		return a.x>b.x;
	}
	return abs(a.x-a.y)>abs(b.x-b.y);
}

int main(int argc, char const *argv[])
{
	sync;
	ll n, a1, a2;//a1=Andy a2=Bob
	cin >> n >> a1 >> a2;
	pll a[n+5];
	rep(i,n)cin >> a[i].x;//Andy

	rep(i,n)cin >> a[i].y;//Bob

	sort(a,a+n,compare);

	ll ans=0, c1=0, c2=0;
	rep(i,n)
	{
		if(a[i].x>a[i].y)
		{
			if(c1<a1)
			{
				ans+=a[i].x;
				a1++;
			}
			else
			{
				ans+=a[i].y;
				a2++;
			}
		}
		else
		{
			if(c2<a2)
			{
				ans+=a[i].y;
				a2++;
			}
			else
			{
				ans+=a[i].x;
				a1++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
