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

int main(int argc, char const *argv[])
{
	sync;
	string s;
	cin >> s;
	int n = s.size();
	vector<int> adj[11];
	queue<pair<int,int>> q;
	bool visited[n+5];
	int dist[n+5]={0};
	memset(visited,false,sizeof(visited));
	rep(i,n)
	{
		adj[s[i]-'0'].pb(i);
	}
	q.push({0,0});
	visited[0] = true;
	while(!q.empty())
	{
		pair<int,int> curr = q.front();
		q.pop();
		if((curr.x-1)>=0 && !visited[curr.x-1])
		{
			q.push({curr.x-1,curr.y+1});
			visited[curr.x-1] = true;
			dist[curr.x-1] = curr.y + 1;
		}
		if((curr.x+1)<n && !visited[curr.x+1])
		{
			q.push({curr.x+1,curr.y+1});
			visited[curr.x+1] = true;
			dist[curr.x+1] = curr.y + 1;
		}
		for(auto a:adj[s[curr.x]-'0'])
		{
			if(!visited[a])
			{
				q.push({a,curr.y+1});
				visited[a] = true;
				dist[a] = curr.y + 1;
			}
		}
		adj[s[curr.x]-'0'].clear();
	}
	cout << dist[n-1] << endl;
	return 0;
}
