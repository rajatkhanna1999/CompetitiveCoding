// #include <bits/stdc++.h>
// #include <vector>
// #include <set>
// #include <map>
// #include <string>
// #include <cstdio>
// #include <cstdlib>
// #include <climits>
// #include <utility>
// #include <algorithm>
// #include <cmath>
// #include <queue>
// #include <stack>
// #include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
// //setbase - cout << setbase (16); cout << 100 << endl; Prints 64
// //setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
// //setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
// //cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
// using namespace std;
// using namespace __gnu_pbds;

// #define sp << " " <<
// #define mod 1000000007
// #define PI 3.14159265358979323
// #define y second
// #define x first
// #define pb push_back
// #define mp make_pair
// #define sz(a) a.size()
// #define pqueue priority_queue< ll >
// //#define pdqueue priority_queue< ll,vector<ll> ,greater< ll > >
// #define codejamDebug(x) cout<<"Case #"<<x<<": ";
// #define debug(x) cout<<#x<<" :"<<x<<endl;
// #define rep(i,n) for(long long i=0;i<n;i++)
// #define f(i,a,b) for(long long i = a; i < b; i++)
// #define fd(i,a,b) for(long long i = a; i >=b; i--)
// #define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// typedef long long int           ll;
// typedef long double             ld;
// typedef unsigned long long int ull;
// typedef vector <int>            vi;
// typedef vector <ll>            vll;
// typedef pair <int, int>        pii;
// typedef pair <ll, ll>          pll;
// typedef vector < pii >        vpii;
// typedef vector < pll >        vpll;
// typedef vector <string>         vs;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// //Handle:cyber_rajat

// int main(int argc, char const *argv[])
// {
// 	sync;
// 	while(true)
// 	{
// 		string s;
// 		cin >> s;
// 		int n = s.size();
// 		if(s[0]=='-')return 0;

// 		stack<char> st;
// 		int cnt=0;
// 		rep(i,n)
// 		{
// 			if(s[i]=='{')st.push('{');
// 			else if(!st.empty() && st.top()=='{')
// 			{
// 				st.pop();
// 			}
// 			else
// 			{
// 				st.push('{');
// 				cnt++;	
// 			}
// 		}
// 		while(!st.empty())
// 		{
// 			if(st.top()=='{')
// 			{
// 				st.pop();
// 				st.pop();
// 				cnt++;
// 			}
// 		}
// 		cout<<cnt<<endl;
// 	}
// 	return 0;
// }
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
	int t=1;
	while(true)
	{
		string s;
		cin >> s;
		int n = s.size();
		if(s[0]=='-')return 0;
 
		stack<char> st;
		int cnt=0;
		rep(i,n)
		{
			if(s[i]=='{')st.push('{');
			else
			{
				if(!st.empty())
				{
					if(st.top()=='}')
					{
						cnt++;
					}
					st.pop();
				}
				else
				{
					st.push('{');
					cnt++;
				}
			}
		}
		while(!st.empty())
		{
			if(st.top()=='{')
			{
				st.pop();
				st.pop();
				cnt++;
			}
		}
		cout<<t<<". "<<cnt<<endl;
		t++;
	}
	return 0;
}

