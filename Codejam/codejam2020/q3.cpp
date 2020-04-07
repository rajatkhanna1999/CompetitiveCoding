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
#define codejamDebug(x) cout << "Case #" << x << ": ";
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
class event{
public:
	int start,end,index;
};

int a[1500];
vector<char> ans(1500);

bool update(int start, int end, int index)
{
	int c0 = 0, c1 = 0, c2 = 0, c3 = 0;
	int target = end - start;
	for(int i=start; i<end; i++)
	{
		if(a[i]==0)c0++;
		else if(a[i]==1)c1++;
		else if(a[i]==2)c2++;
		else c3++;
	}
	if(c0==target)
	{
		for(int i=start; i<end; i++)
		{
			a[i]+=1;
		}
		ans[index]='C';
		return true;
	}
	else if(c3>0)
	{
		return false;
	}
	else if(c1>0)
	{
		for(int i=start; i<end; i++)
		{
			a[i]+=2;
		}
		ans[index]='J';
		return true;
	}
	else
	{
		for(int i=start; i<end; i++)
		{
			a[i]+=1;
		}
		ans[index]='C';
		return true;
	}
}

bool compare(event b, event c)
{
	if(b.start==c.start)
	{
		return b.end<c.end;
	}
	return b.start<c.start;
}

int main(int argc, char const *argv[])
{
	sync;
	int t,T=1;
	cin>>t;
	while(t--)
	{
		codejamDebug(T);
		T++;
		int n;
		cin >> n;
		memset(a,0,sizeof(a));
		ans.clear();
		bool possible=true;
		event events[n+5];
		rep(i,n)
		{
			cin >> events[i].start >> events[i].end;
			events[i].index = i;
		}
		sort(events,events+n,compare);
		rep(i,n)
		{
			possible&=update(events[i].start,events[i].end,events[i].index);
		}
		if(!possible)
		{
			cout << "IMPOSSIBLE" << endl;
		}
		else
		{
			rep(i,n)
			{
				cout << ans[i];
			}
			cout << endl;
		}
	}
	return 0;
}
