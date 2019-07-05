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
#define debug(x) cout<<"Case "<<x<<": "
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

ll parent[100+5]={0};
bool isLeaf[100+5]={0};
vector<ll> leaf;


ll query(ll start,ll end)
{
	string s;
	ll x,a=start,b=end;
	f(i,start,end+1)
	{
		if(isLeaf[i]==true)
			continue;
		x=i;
		cout<<"Q"<<" "<<x<<" "<<a<<" "<<b<<endl;;
		cin>>s;
		if(s=="Yes")
		{
			return x;
		}
	}
}

void binSearch(ll start,ll end,ll prevRoot)
{
	ll cnt=0;
	f(i,start,end+1)
	{
		if(isLeaf[i]==true)cnt++;
	}
	if(start==end)
	{
		parent[start]=prevRoot;
		return;
	}
	if(start>end)
	{
		return ;
	}
	if(cnt==abs(end-start))
	{
		ll temproot;
		f(i,start,end+1)
		{
			if(isLeaf[i]==false)
			{
				parent[i]=prevRoot;
				temproot=i;
				break;
			}
		}
		f(i,start,end+1)
		{
			if(isLeaf[i]==true)
				parent[i]=temproot;
		}
	}
	else
	{
		ll root = query(start,end);
		parent[root]=prevRoot;
		//cout<<parent[root];
		binSearch(start,root-1,root);
		binSearch(root+1,end,root);
	}
}

int main(int argc, char const *argv[])
{
	sync;
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	ll t;
	cin>>t;
	while(t--)
	{
		memset(parent,0,sizeof(parent));
		memset(isLeaf,0,sizeof(isLeaf));
		leaf.clear();
		ll n;
		string s;
		cin>>n;
		if(n==1)
		{
			cout<<"A "<<"-1"<<endl;
			continue;
		}
		ll x,a=1,b=n,root;
		//To find the root node - N Queries
		// f(i,1,n+1)
		// {
		// 	x=i;
		// 	cout<<"Q"<<" "<<x<<" "<<a<<" "<<b;
		// 	cin>>s;
		// 	if(s=="Yes")
		// 	{
		// 		root=x;
		// 		parent[x]=-1;
		// 		break;
		// 	}
		// }
		//To find the leaf nodes - N Queries
		// cout<<"huuuuu"<<endl;
		// f(i,1,n+1)
		// {
		// 	x=i,a=i,b=i;
		// 	cout<<"Q"<<" "<<x<<" "<<a<<" "<<b<<endl;
		// }
		f(i,1,n+1)
		{
			x=i,a=i,b=i;
			cout<<"Q"<<" "<<x<<" "<<a<<" "<<b<<endl;
			cin>>s;
			if(s=="Yes")
			{
				isLeaf[i]=true;
				leaf.pb(i);
			}
		}
		//To check on left and right of root
	    binSearch(1,n,-1);
		cout<<"A ";
		f(i,1,n+1)cout<<parent[i]<<" ";
		cout<<endl;
	}
	return 0;
}
