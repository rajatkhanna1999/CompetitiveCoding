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
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	int t,T;
	cin>>t;
	T=1;
	while(t--)
	{
		codejamDebug(T);
		T++;
		int n,k,p;
		cin>>n>>k>>p;
        int dp[n+1][p+1];
        int a[n+1][k+1];
        int b[n+1][k+1]; 
        rep(j,k)
        {
            a[0][j] = 0;
            b[0][j] = 0;
        }
       	rep(j,p)
       	{
       		dp[0][j] = 0;
       	}
        
        for(int i=1;i<=n;i++)
        {
            b[i][0] = 0;
            dp[i][0] = 0;
            for(int j=1;j<=k;j++)
            {
                cin>>a[i][j];
                b[i][j] = b[i][j-1] + a[i][j];
            }
            
        }
        
        for(int i=1;i<=n;i++)
        {
            int index = min(i*k, p);
            for(int j=1;j<=index;j++)
            {
                dp[i][j] = 0;
                int end = min(j,k);
                for(int m=0;m<=end;m++)
                {
                    dp[i][j] = max(dp[i-1][j-m] + b[i][m] , dp[i][j]);
                }
            }
            
            for(int  j=index+1;j<=p;j++)
                dp[i][j] = dp[i][j-1];
        }
        cout<<dp[n][p]<<endl;
    }
	return 0;
}
