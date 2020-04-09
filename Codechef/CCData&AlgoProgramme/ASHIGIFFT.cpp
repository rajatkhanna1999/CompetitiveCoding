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
ll B, C, X;
pll a[10000+5];
ll p[10000+5],q[10000+5],r[10000+5];

bool IsPossible(ll num)
{
	int i=0, j=0, cnt=num;
	while(i < B)
	{
		while(j < C && p[j]<=a[i].x)
		{
			if(cnt>=q[j])
			{
				cnt+=r[j];
				j++;
			}
		}
		if(a[i].y > cnt)
		{
			return false;
		}
		else
		{
			cnt-=a[i].y;
			i++;
		}
	}
	if(cnt>=1)return true;
	return false;
}

int main(int argc, char const *argv[])
{
	sync;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> X;
		cin >> B;
		rep(i,B)cin >> a[i].x >> a[i].y;

		cin >> C;
		rep(i,C)cin >> p[i] >> q[i] >> r[i];

		ll start, end=0, mid=0;
		rep(i,B)end+=a[i].y;

		//atleast one person should be left so mi is 1
		//and max is total person+1
		start = 1, end++;
		ll ans=1e18;
		while(start<=end)
		{
			mid = start + (end-start)/2;
			if(IsPossible(mid))
			{
				ans = min(ans,mid);
				end = mid-1;
			}
			else
			{
				start = mid+1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
