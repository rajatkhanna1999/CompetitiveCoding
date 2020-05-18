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
const int N = 200;
ll inff = 1e6-1;
bool visited[N] = {false};
ll a[N];
vector<ll> adj[N];
pll g[1005];

int main(int argc, char const *argv[])
{
	sync;
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	ll t, T = 1;
	cin >> t;
	while(t--)
	{
		codejamDebug(T);
		T++;
		ll c, d;
		cin >> c >> d;
		//cleaning
		memset(a,0,sizeof(a));
		memset(adj,0,sizeof(adj));
		memset(g,0,sizeof(g));
		memset(visited,false,sizeof(visited));

		//dijkstra
		map<pll, ll> minDistance;
		visited[1] = true, a[1] = 0;
		priority_queue<pll> q;
        for(int i = 2; i <= c; i++){
          cin >> a[i];
          q.push({a[i], i});
        }
        rep(i,d){
        	cin >> g[i].x >> g[i].y;
        	minDistance[{g[i].x,g[i].y}] = inff;
        	minDistance[{g[i].y,g[i].x}] = inff;
        	adj[g[i].y].pb(g[i].x);
        	adj[g[i].x].pb(g[i].y);
        }
        while(!q.empty()){
          	pll val = q.top();
          	q.pop();
			for(auto curr : adj[val.y]){
				if(visited[curr]){
					minDistance[{val.y, curr}] = abs(a[curr] - a[val.y]);
					minDistance[{curr, val.y}] = abs(a[curr] - a[val.y]);
					break;
				}
			}
            visited[val.y] = true;
        }
        rep(i,d){
        	cout << minDistance[g[i]] << " ";
        }
        cout << endl;
	}
	return 0;
}
