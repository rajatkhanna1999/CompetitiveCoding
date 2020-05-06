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
typedef pair <int, int>        pi;
typedef pair <ll, ll>          pll;
typedef vector < pii >        vpii;
typedef vector < pll >        vpll;
typedef vector <string>         vs;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Handle:cyber_rajat

int main() {
	ll n, m, s, u, v, a, b;
	cin >> n >> m >> s;
	s = min(s, 2500ll);
	ll c[n + 1], d[n + 1];
	vector<pair<ll, pi > > graph[n + 1];
	rep(i, m) {
		cin >> u >> v >> a >> b;
		graph[u].pb({v, {a, b}});
		graph[v].pb({u, {a, b}});
	}
	for(int i=1; i<n; i++) {
		cin >> c[i] >> d[i];
	}
	bool visited[n + 1][2501];
	ll minTime[n + 1][2501];
	ll ans[n + 1];
	memset(visited, false, sizeof(visited));
	for(int i=1; i<n; i++) {
		rep(j, 2501) minTime[i][j] = INT64_MAX;
		ans[i] = INT64_MAX;
	}

	set<pair<ll, pi > > pq;
	ll j = s;
	ll t = 0;
	while (j < 2501)
	{
		pq.insert({t, {j, 1}});
		minTime[1][j] = t;
		// cout << t << " " << j << endl;
		j += c[1];
		t += d[1];
	}

	while (!pq.empty())
	{
		auto entry = *pq.begin();
		pq.erase(entry);
		ll time = entry.ff;
		ll node = entry.ss.ss;
		ll coins = entry.ss.ff;
		for (auto x : graph[node])
		{
			if (coins - x.ss.ff < 0)
				continue;

			ll tmp = time + x.ss.ss;
			ll cns = coins - x.ss.ff;
			ll j = cns;
			ll t = tmp;
			while (j < 2501)
			{
				if (t < minTime[x.ff][j])
					pq.erase({minTime[x.ff][j], {j, x.ff}}), minTime[x.ff][j] = t, pq.insert({t, {j, x.ff}});
				j += c[x.ff];
				t += d[x.ff];
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 2500; j++) {
			ans[i] = min(ans[i], minTime[i][j]);
		}
	}
	for (int i = 2; i <= n; i++) cout << ans[i] << endl;

}