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
	int t, T = 1;
	cin >> t;
	while(t--)
	{
		codejamDebug(T);
		T++;
		int n;
		cin >> n;
		string a[n+5];
		rep(i,n)cin >> a[i];

		int maxPre = 0, maxSuf = 0, index1 = -1, index2 = -1;
		int len, cnt=0;
		int b[n+5]={0};
		rep(i,n)
		{
			len = a[i].size();
			rep(j,len)
			{
				if(a[i][j]=='*')b[i]++;
			}
		}
		rep(i,n)
		{
			len = a[i].size();
			cnt = 0;
			rep(j,len)
			{
				if(a[i][j]=='*')
				{
					break;
				}
				cnt++;
			}
			if(cnt>maxPre)
			{
				maxPre = cnt;
				index1 = i;
			}
		}
		rep(i,n)
		{
			len = a[i].size();
			cnt = 0;
			for(int j=len-1; j>=0; j--)
			{
				if(a[i][j]=='*')
				{
					break;
				}
				cnt++;
			}
			if(cnt>maxSuf)
			{
				maxSuf = cnt;
				index2 = i;
			}
		}
		//cout << index1 sp index2<<endl;
		vector<char> v;
		rep(i,n)
		{
			if(b[i]>=2)
			{
				int j = 0, temp=0;
				while(j<a[i].size())
				{
					if(a[i][j]=='*')
					{
						temp++;
						j++;
						continue;
					}
					if(temp>=1 && temp<b[i])
					{
						v.pb(a[i][j]);
					}
					j++;
				}
			}
		}
		//cout<<v.size()<<endl;
		vector<char> ans;
		if(index1!=-1)
		{
			for(int j=0; j<a[index1].size(); j++)
			{
				if(a[index1][j]=='*')
				{
					break;
				}
				ans.pb(a[index1][j]);
			}
		}
		for(int i=0; i<v.size(); i++)
		{
			ans.pb(v[i]);
		}
		
		if(index2!=-1)
		{
			vector<char> v2;
			for(int j=a[index2].size()-1; j>=0; j--)
			{
				if(a[index2][j]=='*')
				{
					break;
				}
				v2.pb(a[index2][j]);
			}
			for(int j=v2.size()-1; j>=0; j--)
			{
				ans.pb(v2[j]);
			}
		}
		bool flag = true;
		rep(i,n)
		{
			int j=0, k=0;
			while(j<a[i].size())
			{
				if(a[i][j]=='*')
				{
					break;
				}
				if(a[i][j]!=ans[k])
				{
					flag = false;
					break;
				}
				j++;
				k++;
			}
			j=a[i].size()-1;
			k=ans.size()-1;
			while(j>=0)
			{
				if(a[i][j]=='*')
				{
					break;
				}
				if(a[i][j]!=ans[k])
				{
					flag = false;
					break;
				}
				j--;
				k--;
			}
		}
		if(flag)
		{
			for(auto x:ans)
			{
				cout << x;
			}
			cout << endl;
		}
		else
		{
			cout << "*" << endl;
		}
	}
	return 0;
}
