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
ll boundary = 1e9;

int main(int argc, char const *argv[])
{
	sync;
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	ll t, T=1;
	cin >> t;
	while(t--)
	{
		codejamDebug(T);
		T++;
        stack<ll> dummy2;
		string s, curr="";
		cin >> s;
		curr+="1(";
		curr+=s;
		curr+=")";
		ll len = curr.size();
		pair<ll,pair<ll,bool>> curr1, ans;
		stack<pair<ll,pair<ll,bool>>> dummy1;
		rep(i,len)
		{
			if(curr[i]=='(')
          	{
          		dummy1.push({0,{0,true}});
            }
			else if(curr[i]<='9' && curr[i]>='1')
			{
            	dummy2.push(curr[i]-'0');
            }
          	else if(curr[i]=='N')
          	{
            	dummy1.push({-1,{0,false}});
        	}
        	else if(curr[i]=='S')
          	{
          		dummy1.push({1,{0,false}});
            }
            else if(curr[i]=='E')
          	{
          		dummy1.push({0,{1,false}});
            }
          	else if(curr[i]=='W')
          	{
          		dummy1.push({0,{-1,false}});
            }  	
            else
            {
            	pair<ll,pair<ll,bool>> curr2, topmost;
            	curr2 = {0,{0,false}};
	            while(true)
	            {
	                topmost = dummy1.top();
	                dummy1.pop();
	                ll value;
	                if(topmost.y.y)
	                {
	                	value = dummy2.top();
	                	dummy2.pop();
		                curr2.x = curr2.x*value;
		                curr2.y.x = curr2.y.x*value;
		                curr2.y.x = (curr2.y.x+boundary)%boundary;
		                curr2.x = (curr2.x+boundary)%boundary;
		                dummy1.push(curr2);
		                break;
	                }
	                else
	                {
	                  	curr2.x = curr2.x + topmost.x;
	                 	curr2.y.x = curr2.y.x + topmost.y.x;
	                  	curr2.y.x = (curr2.y.x+boundary)%boundary;
	                  	curr2.x = (curr2.x+boundary)%boundary;
	                }
	          	}
          	}
		}
		ans = dummy1.top();
		cout << (ans.y.x+boundary)%boundary + 1 sp (ans.x+boundary)%boundary + 1 << endl;
	}
	return 0;
}
