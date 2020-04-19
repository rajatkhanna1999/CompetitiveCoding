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
	int t,T=1;
	cin >> t;
	while(t--)
	{
		codejamDebug(T);
		T++;
		ll R, C;
		cin >> R >> C;
		ll a[R+5][C+5];
		ll sum=0;
		rep(i,R)
		{
			rep(j,C)
			{
				cin >> a[i][j];
				sum+=a[i][j];
			}
		}
		while(1)
		{
			vector<pii> v;
			ll change=0;
			rep(i,R)
			{
				rep(j,C)
				{
					if(a[i][j]==0)continue;
					ll avg=0, cnt=0;
					for(int k=j+1; k<C; k++)
					{
						if(a[i][k]==0)continue;

						avg+=a[i][k];
						cnt++;
						break;
					}
					for(int k=j-1; k>=0; k--)
					{
						if(a[i][k]==0)continue;

						avg+=a[i][k];
						cnt++;
						break;
					}
					for(int k=i+1; k<R; k++)
					{
						if(a[k][j]==0)continue;

						avg+=a[k][j];
						cnt++;
						break;
					}
					for(int k=i-1; k>=0; k--)
					{
						if(a[k][j]==0)continue;

						avg+=a[k][j];
						cnt++;
						break;
					}
					if(cnt!=0)
					{
						ld p1, p2=a[i][j];
						p1 = (1.0*avg)/cnt;
						if(p1>p2)
						{
							v.pb({i,j});
							change++;
						}
					}
					//cout<< avg sp cnt sp change << endl;
				}
			}
			if(change==0)
			{
				break;
			}
			rep(i,v.size())
			{
				a[v[i].x][v[i].y]=0;
			}
			rep(i,R)
			{
				rep(j,C)
				{
					sum+=a[i][j];
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
