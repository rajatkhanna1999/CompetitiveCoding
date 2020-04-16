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
const int N=2000000+5;
int connected; 
int par[N], sz[N], sources[N];

struct DSU
{
    //N to be defined globally
    //const int N=1e5+5;
    // int connected; 
    // int par[N], sz[N], sources[N];

    DSU() {} 

    DSU(int n) 
    {
        for(int i=0;i<=n;i++)
        {
            par[i]=i;
            sz[i]=1;
            sources[i]=0;
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
        sources[par2]+=sources[par1];
        sz[par1]=0;
        par[par1]=par[par2];
    }
};

int decrypt(char a, char b)
{
	int ans = 0;
	if(b>='A' && b<='Z')ans+=(int(b-'A'));
	else ans+=(int(b-'a')+26);

	if(a>='A' && a<='Z')ans+=(52*(int(a-'A')));
	else ans+=(52*(int(a-'a')+26));

	return ans;
}

int main(int argc, char const *argv[])
{
	sync;
	int N, R, C;
	//cin >> N >> R >> C;
	scanf("%d",&N);
	scanf("%d",&R);
	scanf("%d",&C);
	//string s;
	char s[10];
	int u, v, r1, r2, c1, c2;
	DSU dsu(R*C + 1);
	rep(i,N)
	{
		//cin >> s;
		scanf("%s", s);
		if(s[0]=='W')
		{
			c1 = decrypt(s[1],s[2]);
			r1 = decrypt(s[3],s[4]);
			c2 = decrypt(s[5],s[6]);
			r2 = decrypt(s[7],s[8]);
			//cout << c1 sp r1 sp c2 sp r2 << endl;
			c1--, r1--, c2--, r2--;
			r1/=5, r2/=5;
			u = r1*C + c1;
			v = r2*C + c2;
			//cout << 'W' sp u sp v << endl;
			dsu.unite(u,v);
		}
		else if(s[0]=='V')
		{
			c1 = decrypt(s[1],s[2]);
			r1 = decrypt(s[3],s[4]);
			//cout << c1 sp r1 << endl;
			c1--, r1--;
			r1/=5;
			u = r1*C + c1;
			int par = dsu.getPar(u);
			sources[par]++;
			//cout << 'V' sp u sp par sp sources[par] << endl;
		}
		else if(s[0]=='R')
		{
			c1 = decrypt(s[1],s[2]);
			r1 = decrypt(s[3],s[4]);
			//cout << c1 sp r1 << endl;
			c1--, r1--;
			r1/=5;
			u = r1*C + c1;
			int par = dsu.getPar(u);
			sources[par]--;
			//cout << 'R' sp u sp par sp sources[par] << endl;
		}
		else
		{
			c1 = decrypt(s[1],s[2]);
			r1 = decrypt(s[3],s[4]);
			c2 = decrypt(s[5],s[6]);
			r2 = decrypt(s[7],s[8]);
			//cout << c1 sp r1 sp c2 sp r2 << endl;
			c1--, r1--, c2--, r2--;
			r1/=5, r2/=5;
			u = r1*C + c1;
			v = r2*C + c2;
			int par1 = dsu.getPar(u);
			int par2 = dsu.getPar(v);
			//cout <<'L' sp u sp v sp par1 sp sources[par1] sp par2 sp sources[par2] << endl;
			if((sources[par1]>0 && sources[par2]<=0) || (sources[par1]<=0 && sources[par2]>0))
			{
				//cout << "ON" << endl;
				printf("ON\n");
			}
			else
			{
				//cout << "OFF" << endl;
				printf("OFF\n");
			}
		}
	}
	return 0;
}
