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

int main(int argc, char const *argv[])
{
	sync;
	freopen("mr_x.txt","r",stdin);
	freopen("mr_xoutput.txt","w",stdout);
	ll t,T=1;
	cin>>t;
	while(t--)
	{
		codejamDebug(T);
		string s;
		cin>>s;
		ll ans=0;
		if(s=="X" || s=="x")
			cout<<"1"<<endl;
		else if(s=="1" || s=="0")
			cout<<"0"<<endl;
		else
		{
			stack<char> st;
			ll len=s.size();
			rep(i,len)
			{
				if(s[i]==')')
				{
					char operand1=st.top();
					st.pop();
					char operation=st.top();
					st.pop();
					char operand2=st.top();
					st.pop();
					st.pop();
					//string temp = operand2 + operation + operand1;
					if(operation=='|')
					{
						if(operand1=='X' && operand2=='X')
							st.push('X');
						else if(operand1=='x' && operand2=='x')
							st.push('x');
						else if((operand1=='X' && operand2=='x') || (operand1=='x' && operand2=='X'))
							st.push('1');
						else if(operand1=='1' || operand2=='1')
							st.push('1');
						else
						{
							if(operand1=='0')st.push(operand2);
							else st.push(operand1);
						}
					}
					else if(operation=='&')
					{
						if(operand1=='X' && operand2=='X')
							st.push('X');
						else if(operand1=='x' && operand2=='x')
							st.push('x');
						else if((operand1=='X' && operand2=='x') || (operand1=='x' && operand2=='X'))
							st.push('0');
						else if(operand1=='0' || operand2=='0')
							st.push('0');
						else
						{
							if(operand1=='1')st.push(operand2);
							else st.push(operand1);
						}
					}
					else
					{
						if(operand1=='X' && operand2=='X')
							st.push('0');
						else if(operand1=='x' && operand2=='x')
							st.push('0');
						else if((operand1=='X' && operand2=='x') || (operand1=='x' && operand2=='X'))
							st.push('1');
						else if(operand1=='0')
							st.push(operand2);
						else if(operand2=='0')
							st.push(operand1);
						else if(operand1=='1')
						{
							if(operand2=='X')st.push('x');
							else if(operand2=='x')st.push('X');
							else if(operand2=='0')st.push('1');
							else st.push('0');
						}
						else if(operand2=='1')
						{
							if(operand1=='X')st.push('x');
							else if(operand1=='x')st.push('X');
							else if(operand1=='0')st.push('1');
							else st.push('0');
						}
					}
				}
				else
					st.push(s[i]);
			}
			ll ans;
			if(st.top()=='1' || st.top()=='0')ans=0;
			else ans=1;
			//cout<<st.top()<<endl;
			cout<<ans<<endl;
		}
		T++;
	}
	return 0;
}
