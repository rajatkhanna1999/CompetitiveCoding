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
const int inf = INT_MAX;

int main(int argc, char const *argv[])
{
	sync;
	ll n, m, x, tp;
	cin >> n >> m >> x;
	pair<ll, vector<ll> > book[n];
	rep(i, n)
	{
		cin >> book[i].first;
		rep(j, m)
		{
			cin >> tp;
			book[i].second.pb(tp);
		}
	}
	ll fans = inf, ans = inf;
	ll val[m];
	for (ll i = 0; i < (1<<n); i++)
	{
		ans = 0;
		memset(val,0,sizeof(val));
		for (ll j = 0; j < n; j++)
		{
			if (i&(1<<j))
			{
				ans += book[j].first;
				rep(k, m)
				{
					val[k] += book[j].second[k];
				}
			}
		}
		bool flag = true;
		rep(k, m) 
		{
			if (val[k]<x)
			{
				flag = false;
			}
		}
		if(flag)
		{
			fans = min(ans, fans);
		}
		
	}
	if (fans == inf){
		 cout << -1 << endl;
	}
	else {
		cout << fans << endl;
	}
	return 0;
}

