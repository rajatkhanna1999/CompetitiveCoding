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
const int N = 1e5 + 5;
int diameter[N]; 
vector<int> adj[N];

int bfs(int init, int n) 
{ 
    // Initializing queue 
    queue<int> q; 
    q.push(init); 
  
    int visited[n + 1]; 
    for (int i = 0; i <= n; i++) { 
        visited[i] = 0; 
        diameter[i] = 0; 
    } 
  
    // Pushing each node in queue 
    q.push(init); 
  
    // Mark the traversed node visited 
    visited[init] = 1; 
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
        for (int i = 0; i < adj[u].size(); i++) { 
            if (visited[adj[u][i]] == 0) { 
                visited[adj[u][i]] = 1; 
  
                // Considering weight of edges equal to 1 
                diameter[adj[u][i]] += diameter[u] + 1; 
                q.push(adj[u][i]); 
            } 
        } 
    } 
  
    // return index of max value in diameter 
    return int(max_element(diameter + 1, diameter + n + 1) - diameter); 
} 
  
int findDiameter(int n) 
{ 
    int init = bfs(1, n); 
    int val = bfs(init, n); 
    return diameter[val]; 
} 

int main(int argc, char const *argv[])
{
	sync;
	ll t;
	cin >> t;
	while(t--)
	{
        memset(adj,0,sizeof(adj));
		int n;
		cin >> n;
		int a, b;
		rep(i,n-1)
		{
			cin >> a >> b;
			a++, b++;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		cout << ceil(findDiameter(n)/2.0) << endl;
	}
	return 0;
}
