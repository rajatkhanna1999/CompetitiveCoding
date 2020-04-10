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
bool IsPossible(ll val, ll W, ll L, ll N, pll a[])
{
	ll sum = 0, curr = 0;
	rep(i,N)
	{
		curr = a[i].x + val*a[i].y;
		if(curr>=L)sum+=curr;
		if(sum>=W)
		{
			break;
		}
	}
	if(sum>=W)return true;
	return false;
}

int main(int argc, char const *argv[])
{
	sync;
	ll N, W, L;
	cin >> N >> W >> L;
	pll a[N+5];
	rep(i,N)cin >> a[i].x >> a[i].y;

	ll start = 0, end =1e18, ans=1e18;
	while(start<=end)
	{
		ll mid = start + (end-start)/2;
		if(IsPossible(mid,W,L,N,a))
		{
			ans = min(ans,mid);
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
