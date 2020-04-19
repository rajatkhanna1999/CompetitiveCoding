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
	int t, T=1;
	cin >> t;
	while(t--)
	{
		codejamDebug(T);
		T++;
		int W, H, L, U, R, D;
		cin >> W >> H >> L >> U >> R >> D;
		long double dp[H+5][W+5];
		for(int i=0; i<=H; i++)
		{
			for(int j=0; j<=W; j++)
			{
				dp[i][j] = 0.0;
			}
		}
		bool flag[H+5][W+5];
		memset(flag,false,sizeof(flag));
		for(int i=U; i<=D; i++)
		{
			for(int j=L; j<=R; j++)
			{
				flag[i][j] = true;
			}
		}
		dp[1][1] = 1.0;
		for(int i=1; i<=H; i++)
		{
			for(int j=1; j<=W; j++)
			{
				if(flag[i][j])continue;

				if(i==H)
				{
					dp[i][j+1]+=dp[i][j];
					continue;
				}
				if(j==W)
				{
					dp[i+1][j]+=dp[i][j];
					continue;
				}
				dp[i][j+1]+=(dp[i][j]/2.0);
				dp[i+1][j]+=(dp[i][j]/2.0); 
			}
		}
		// for(int i=1; i<=H; i++)
		// {
		// 	for(int j=1; j<=W; j++)
		// 	{
		// 		if(flag[i][j])cout<<"0 ";
		// 		else cout << dp[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		cout << setprecision(14);
		if(flag[H][W])cout<< "0.0" << endl;
		else cout << dp[H][W] << endl;
	}
	return 0;
}
