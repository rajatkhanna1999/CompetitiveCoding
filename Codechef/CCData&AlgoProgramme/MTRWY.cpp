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
const int N=1e6+5;
int adj1[1001][1001], adj2[1001][1001];
int par[N], sz[N];
int oper[N], X1[N], Y1[N], X2[N], Y2[N];

struct DSU
{
    //N to be defined globally
    int connected;

    DSU() {} 

    DSU(int n) 
    {
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            sz[i]=1;
        }
        connected=n;
    }

    int getPar(int k)
    {
        while(k!=par[k])
        {
            par[k]=par[par[k]];
            k=par[k];
        }
        return k;
    }

    int getSize(int k)
    {
        return sz[getPar(k)];
    }

    void unite(int u, int v)
    {
        int par1=getPar(u), par2=getPar(v);

        if(par1==par2)
            return;

        connected--;

        if(sz[par1]>sz[par2])
            swap(par1, par2);

        sz[par2]+=sz[par1];
        sz[par1]=0;
        par[par1]=par[par2];
    }
};

int main(int argc, char const *argv[])
{
	sync;
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, q;
		cin >> n >> m >> q;
		memset(adj1,0,sizeof(adj1));
		memset(adj2,0,sizeof(adj2));
		DSU dsu(n*m);
		rep(i,q)
		{
			cin >> oper[i];
			if(oper[i]==1)
			{
				cin >> X1[i] >> Y1[i];
				X1[i]--;
				adj1[X1[i]][Y1[i]]++;
			}
			else if(oper[i]==2)
			{
				cin >> X1[i] >> Y1[i];
				X1[i]--;
				adj2[X1[i]][Y1[i]]++;
			}
			else if(oper[i]==3)
			{
				cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
				X1[i]--, X2[i]--;
			}
		}
		for(int i=0; i<n; i++)
		{
			for(int j=1; j<m; j++)
			{
				if(adj1[i][j]==0)dsu.unite(i*m+j,i*m+j+1);
			}
		}
		for(int i=0; i<(n-1); i++)
		{
			for(int j=1; j<=m; j++)
			{
				if(adj2[i][j]==0)dsu.unite(i*m+j,(i+1)*m+j);
			}
		}
		
	}
	return 0;
}
