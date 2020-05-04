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
int visited[1005][1005];

int main(int argc, char const *argv[])
{
	sync;
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(visited,-1,sizeof(visited));
		int n, m;
		scanf("%d",&n);
		scanf("%d",&m);
		string s[n+5];
		rep(i,n)
		{
			cin >> s[i];
		}
		pair<int,int> st, end;
		rep(i,n)
		{
			rep(j,m)
			{
				if(s[i][j]=='S')
				{
					st.x = i, st.y =j;  
				}
				if(s[i][j]=='F')
				{
					end.x = i, end.y = j;
				}
			}
		}
		//s[i][j]->ith row ka jth col
		queue<pair<int,int> > q;
		q.push(st);
		visited[st.x][st.y] = 0;
		//visited[i][j]-> ith row ka jth col
		while(!q.empty())
		{
			pair<int,int> curr = q.front();
			q.pop();
			for(int i=curr.x+1; i<n; i++)
			{
				//if(visited[i][curr.y]!=-1)continue;

				if(s[i][curr.y]=='.' || s[i][curr.y]=='F')
				{
					if(visited[i][curr.y]==-1 || (visited[curr.x][curr.y] + 1)<visited[i][curr.y])
					{
						q.push({i,curr.y});
						visited[i][curr.y] = visited[curr.x][curr.y] + 1;
					}
				}
				else
				{
					break;
				}
			}
			for(int i=curr.x-1; i>=0; i--)
			{
				//if(visited[i][curr.y]!=-1)continue;

				if(s[i][curr.y]=='.' || s[i][curr.y]=='F')
				{
					if(visited[i][curr.y]==-1 || (visited[curr.x][curr.y] + 1)<visited[i][curr.y])
					{
						q.push({i,curr.y});
						visited[i][curr.y] = visited[curr.x][curr.y] + 1;
					}
				}
				else
				{
					break;
				}
			}
			for(int j=curr.y+1; j<m; j++)
			{
				//if(visited[curr.x][j]!=-1)continue;

				if(s[curr.x][j]=='.' || s[curr.x][j]=='F')
				{
					if(visited[curr.x][j]==-1 || (visited[curr.x][curr.y] + 1)<visited[curr.x][j])
					{
						q.push({curr.x,j});
						visited[curr.x][j] = visited[curr.x][curr.y] + 1;
					}
				}
				else
				{
					break;
				}
			}
			for(int j=curr.y-1; j>=0; j--)
			{
				//if(visited[curr.x][j]!=-1)continue;

				if(s[curr.x][j]=='.' || s[curr.x][j]=='F')
				{
					if(visited[curr.x][j]==-1 || (visited[curr.x][curr.y] + 1)<visited[curr.x][j])
					{
						q.push({curr.x,j});
						visited[curr.x][j] = visited[curr.x][curr.y] + 1;
					}
				}
				else
				{
					break;
				}
			}
			for(int i=curr.x+1, j=curr.y+1; i<n && j<m; i++,j++)
			{
				//if(visited[i][j]!=-1)continue;

				if(s[i][j]=='.'  || s[i][j]=='F')
				{
					if(visited[i][j]==-1 || (visited[curr.x][curr.y] + 1)<visited[i][j])
					{
						q.push({i,j});
						visited[i][j] = visited[curr.x][curr.y] + 1;
					}
				}
				else
				{
					break;
				}
			}
			for(int i=curr.x+1, j=curr.y-1; i<n && j>=0; i++,j--)
			{
				//if(visited[i][j]!=-1)continue;

				if(s[i][j]=='.'|| s[i][j]=='F')
				{
					if(visited[i][j]==-1 || (visited[curr.x][curr.y] + 1)<visited[i][j])
					{
						q.push({i,j});
						visited[i][j] = visited[curr.x][curr.y] + 1;
					}
				}
				else
				{
					break;
				}
			}
			for(int i=curr.x-1, j=curr.y+1; i>=0 && j<m; i--,j++)
			{
				//if(visited[i][j]!=-1)continue;

				if(s[i][j]=='.'|| s[i][j]=='F')
				{
					if(visited[i][j]==-1 || (visited[curr.x][curr.y] + 1)<visited[i][j])
					{
						q.push({i,j});
						visited[i][j] = visited[curr.x][curr.y] + 1;
					}
				}
				else
				{
					break;
				}
			}
			for(int i=curr.x-1, j=curr.y-1; i>=0 && j>=0; i--,j--)
			{
				//if(visited[i][j]!=-1)continue;

				if(s[i][j]=='.'|| s[i][j]=='F')
				{
					if(visited[i][j]==-1 || (visited[curr.x][curr.y] + 1)<visited[i][j])
					{
						q.push({i,j});
						visited[i][j] = visited[curr.x][curr.y] + 1;
					}
				}
				else
				{
					break;
				}
			}
		}
		// rep(i,n)
		// {
		// 	rep(j,m)
		// 	{
		// 		cout << visited[i][j] <<" ";
		// 	}
		// 	cout << endl;
		// }
		cout << visited[end.x][end.y] << endl;
	}
	return 0;
}
