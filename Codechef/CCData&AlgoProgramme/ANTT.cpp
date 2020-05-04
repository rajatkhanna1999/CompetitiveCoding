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
    int connected; //Number of connected components
    int par[N], sz[N];

    DSU() {} 

    DSU(int n) 
    {
        //Indexing is from 1 
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

    //returns size of the component of which k is part
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

struct pt {
    long long x, y;
    pt() {}
    pt(long long _x, long long _y) : x(_x), y(_y) {}
    pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt& p) const { return x * p.y - y * p.x; }
    long long cross(const pt& a, const pt& b) const { return (a - *this).cross(b - *this); }
};

int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(long long a, long long b, long long c, long long d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}

int main(int argc, char const *argv[])
{
	sync;
	ll t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		vector<pt> points1, points2;
		int a, b, c ,d;
		rep(i,n){
			cin >> a >> b >> c >> d;
			points1.pb(pt(a,b));
			points2.pb(pt(c,d));
		}
		DSU dsu(n);
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				bool check = check_inter(points1[i-1],points2[i-1],points1[j-1],points2[j-1]);
				int par1 = dsu.getPar(i);
				int par2 = dsu.getPar(j);
				if(par1!=par2 && check){
					dsu.unite(i,j);
				}
			}
		}
		rep(i,m){
			cin >> a >> b;
			int par1 = dsu.getPar(a);
			int par2 = dsu.getPar(b);
			if(par1==par2)cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}
