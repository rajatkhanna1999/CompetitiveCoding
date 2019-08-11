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
	string s;
	cin>>s;
	if(sz(s)==1 || sz(s)==2)cout<<s;
	else
	{
		// bool visited[100005]={false};
		// rep(i,sz(s))
		// {
		// 	ll num=0;
		// 	while(i<sz(s)-1 && s[i]==s[i+1])i++,num++;
		// 	if(num==0)output+=s[i];
		// 	else output+=s[i],output+=s[i];
		// }
		// rep(i,sz(output))
		// {
		// 	if(!visited[i] && i<sz(output)-1 && output[i]==output[i+1])
		// 	{
		// 		if((i+2)<(sz(output)-1) && output[i+2]==output[i+3])
		// 			visited[i+2]=true;
		// 	}
		// }
		// rep(i,sz(output))if(!visited[i])cout<<output[i];
		vector<char> v,output;
		rep(i,sz(s))v.pb(s[i]);
		rep(i,sz(v))
		{
			ll num=0;
			while(i<sz(v)-1 && v[i]==v[i+1])i++,num++;
			if(num==0)output.pb(v[i]);
			else output.pb(v[i]),output.pb(v[i]);
		}
		rep(i,sz(output))
		{
			if(i<sz(output)-1 && output[i]==output[i+1])
			{
				if((i+2)<(sz(output)-1) && output[i+2]==output[i+3])
					output.erase(output.begin()+i+2);
			}
		}
		rep(i,sz(output))cout<<output[i];
	}
	return 0;
}
