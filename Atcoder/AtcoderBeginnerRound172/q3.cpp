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
#define mem(a,b) memset(a,b,sizeof(a))
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
ll n, m ,k;
const int  N = 200005;
ll a[N], b[N], dp[N], pp[N];

int main(int argc, char const *argv[])
{
	sync;
	cin >> n >> m >> k;
	rep(i,n){
		cin >> a[i];
		if(i == 0){
			dp[i] = a[i];
			continue;
		}
		dp[i] = dp[i-1] + a[i];
	}
	rep(i,m){
		cin >> b[i];
		if(i == 0){
			pp[i] = b[i];
			continue;
		}
		pp[i] = pp[i-1] + b[i];
	}
	ll p1 = 0, p2 = 0;
	rep(i,n){
		if(dp[i] <= k){
			p1 = i + 1;
		}
	}
	rep(i,m){
		if(pp[i] <= k){
			p2 = i + 1;
		}
	}
	ll ans = 0;
	rep(i,n){
		ll val = k - dp[i]; 
		if(val < 0){
			break;
		}
		ll pos = lower_bound(pp,pp+m,val) - pp;
		if(pos == m){
			pos--;
		}
		else if(pp[pos] != val){
			pos--;
			if(pos < 0){
				continue;
			}
		}
		//cout << pos sp i << endl;
		ans = max(ans, pos + i + 2);
	}
	ans = max(ans, max(p1,p2));
	cout << ans << endl;
	return 0;
}
