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
const int N=1e5+5;

struct DSU
{
    //N to be defined globally
    //const int N=1e5+5;
    int connected;
    int par[N], sz[N];

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
	int n, m;
	scanf("%d",&n);
	scanf("%d",&m);
	DSU dsu(n);
	int a, b;
	rep(i,m)
	{
		scanf("%d",&a);
		scanf("%d",&b);	
		dsu.unite(a,b);
	}
	int value[n+5]={0};
	rep(i,n)
	{
		scanf("%d",&value[i+1]);
	}
	map<int,int> my;
	for(int i=1; i<=n; i++)
	{
		int par = dsu.getPar(i);
		if(my.find(par)==my.end())
		{
			if(value[i] >= 0)my[par] = value[i];
			else my[par] = INT_MAX;
		}
		else
		{
			if(value[i] >= 0)my[par] = min(my[par],value[i]);
		}
	}
	if(dsu.connected==1)
	{
		printf("0\n");
		return 0;
	}
	ll ans = 0;
	int minVal=INT_MAX;
	bool flag = false;
	for(auto a:my)
	{
		if(a.y!=INT_MAX)
		{
			ans+=a.y;
			minVal = min(minVal,a.y);
		}
		else
		{
			flag = true;
			break;
		}
	}
	ans = ans - minVal + (dsu.connected-1)*minVal;
	if(flag)printf("-1\n");
	else printf("%lld\n",ans);

	return 0;
}
