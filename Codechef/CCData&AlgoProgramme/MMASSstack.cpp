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
	string s;
	cin >> s;
	map<char,int> mass;
	mass['H']=1;
	mass['C']=12;
	mass['O']=16;
	int n = s.size();
	int sum=0;
	stack<int> st; 
	rep(i,n)
	{
		if(s[i]=='(')
		{
			st.push(-1);
		}
		else if(s[i]=='H' || s[i]=='O' || s[i]=='C')
		{
			st.push(mass[s[i]]);
		}
		else if(s[i]>='2' && s[i]<='9')
		{
			int curr=st.top();
			st.pop();
			st.push(curr*(s[i]-'0'));
		}
		else
		{
			int curr=0;
			while(st.top()!=-1)
			{
				curr+=st.top();
				st.pop();
			}
			st.pop();
			st.push(curr);
		}
	}
	while(!st.empty())
	{
		sum+=st.top();
		st.pop();
	}
	cout<<sum<<endl;
	return 0;
}
