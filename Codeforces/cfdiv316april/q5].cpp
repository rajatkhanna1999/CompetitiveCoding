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
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define pqueue priority_queue< ll >
//#define pdqueue priority_queue< ll,vector<ll> ,greater< ll > >
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

const int MOD = 1e9 + 7;
 
void add(int &a, int b) {
  a += b;
  while (a >= MOD) {
    a -= MOD;
  }
  while (a < 0) {
    a += MOD;
  }
}
 
struct BIT {
  int n;
  vector<int> tree;
  BIT (int _n) : n(_n + 1) {
    tree.resize(n + 2);
  }
  inline int lsb(int x) {
    return (x & (-x));
  }
  void update(int pos, int val) {
    ++pos;
    while (pos <= n) {
      add(tree[pos], val);
      pos += lsb(pos);
    }
  }
  int query(int pos) {
    ++pos;
    int ret = 0;
    while (pos) {
      add(ret, tree[pos]);
      pos -= lsb(pos);
    }
    return ret;
  }
};

int main(int argc, char const *argv[])
{
	sync;
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	ll n,k;
	cin>>n>>k;
	ll a[n+5]={0},ans[n+5]={0};
	vll v;
	priority_queue<ll,vector<ll> ,greater< ll > > pq;
	map<ll,ll> mymap;
	rep(i,n)cin>>a[i],pq.push(a[i]),v.pb(a[i]),mymap[a[i]]=i;
	ll flag=1;
	BIT newdp(n+5);
	while(sz(v))
	{
		ll val=pq.top();
		pq.pop();
		ll index=mymap[val];
		ll L=max(index-k,0)
		ll R=min(index+k,n-1);
		newdp.update(L,flag);
		newdp.update(R+1,-flag);
	}


}
