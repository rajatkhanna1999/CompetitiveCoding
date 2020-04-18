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
int visited[1000000 +5]; 

int main(int argc, char const *argv[])
{
	sync;
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	memset(visited,-1,sizeof(visited));
	queue<int>q;
	q.push(s);
	visited[s] = 0;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		if((curr-d)>=1 && visited[curr-d]==-1)
		{
			q.push(curr-d);
			visited[curr-d] = visited[curr] + 1;
		}
		if((curr+u)<=f && visited[curr+u]==-1)
		{
			q.push(curr+u);
			visited[curr+u] =  visited[curr] + 1;
		}
	}
	if(visited[g]!=-1)
	{
		cout << visited[g] << endl;
	}
	else
	{
		cout << "use the stairs" << endl;
	}
	return 0;
}
