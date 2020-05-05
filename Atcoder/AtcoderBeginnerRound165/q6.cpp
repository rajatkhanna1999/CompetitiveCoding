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

const int N = 200005;
ll arr[N], dp[N]; 
vector<ll> g[N];
vector< vector< ll > > ans1;

void lis(vector<ll> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<ll> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), arr[a[i]]) - d.begin();
        if (d[j-1] < arr[a[i]] && arr[a[i]] < d[j])
            d[j] = arr[a[i]];
    }

    int ans = 1;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
        dp[a[i]] = ans;
    }
}
//Handle:cyber_rajat

void dfs(ll start, ll par, vector<ll>& v){
	vector<ll> path;
	path = v;
	path.pb(start);
	for(auto x: g[start]){
		if(x==par)continue;
		dfs(x,start,path);
	}
	if(g[start].size()==1){
		ans1.pb(path);
	}
}

int main(int argc, char const *argv[])
{
	sync;
	ll n;
	cin >> n;
	memset(dp,0,sizeof(dp));
	rep(i,n)cin >> arr[i];

	ll u, v;
	rep(i,n-1){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<ll> v1;
	dfs(1,0,v1);
	memset(dp,-1,sizeof(dp));
	for(auto x: ans1){
		lis(x);
		break;
	}
	// for(int i=1; i<=n ;i++){
	// 	cout << dp[i] << endl;
	// }
	return 0;
}
