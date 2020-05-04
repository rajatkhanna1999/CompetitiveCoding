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
bool visited[60][60];
string s[60];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;

void dfs(int stx, int sty){
	visited[stx][sty] = true;
	int currx, curry;
	rep(i,4){
		currx = stx+dx[i], curry = sty+dy[i];
		if(currx >= 0 && currx < n && curry >=0 && curry < m && !visited[currx][curry] && s[currx][curry]=='#'){
			dfs(currx,curry);
		}
	}
}

int main(int argc, char const *argv[])
{
	sync;
	cin >> n >> m;
	int ans = 2, cnt = 0;
	rep(i,n){
		cin >> s[i];
		rep(j,m){
			if(s[i][j]=='#')cnt++;
		}
	}
	if(cnt <=2 ){
		ans = -1;
		goto mark;
	}
	
	rep(i,n){
		rep(j,m){
			memset(visited,false,sizeof(visited));
			visited[i][j] = true;
			rep(r,n){
				rep(t,m){
					if(s[r][t]=='#' && !visited[r][t]){
						dfs(r,t);
						goto k;
					}
				}
			}
			k:;
			bool flag = false;
			rep(r,n){
				rep(t,m){
					if(s[r][t]=='#' && !visited[r][t]){
						flag = true;
						ans = 1;
						// cout << i sp j sp r sp t << endl;
						goto mark;
					}
				}
			}
		}
	}
	mark: ;
	cout << ans << endl;
	return 0;
}
