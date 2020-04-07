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
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin >> t;
	int b;
	cin >> b;
	while(t--)
	{
		if(b==10)
		{
			int temp;
			int a[11];
			for(int i=1; i<=10; i++)
			{
				cout << i << endl;
				cin >> temp;
				a[i-1] = temp;
			}
			for(int i=0; i<10; i++)
			{
				cout << a[i];
			}
			cout << endl;
		}
		else
		{
			//1001101110 1011011101 a
			//0110010001 0100100010 acom
			//1011101101 0111011001 ra
			//0100010010 1000100110 racom
			set<vector<int>> s;
			int temp, cnt=0;
			//140 queries
			//cout<<"no";
			while(cnt<140)
			{
				vector<int> v,v1;
				for(int i=1; i<=10; i++)
				{
					cout << i << endl;
					cin >> temp;
					v.pb(temp);
					v1.pb(1-temp);
					cnt++;
				}
				//cout<<cnt<<endl;
				s.insert(v);
				s.insert(v1);
			}
			//cout<<"yo"<<endl;
			vector<int> front,last;
			if(s.size()==4)
			{
				//141st query
				cout << 1 << endl;
				cin >> temp;
				//check which of 4 string has temp as 1st
				vector<vector<int>> possible;
				for(auto a:s)
				{
					if(a[0]==temp)
					{
						possible.pb(a);
					}
				}
				//142 query
				//query the bit different in 2 sets(atmax 2)
				int pos=0;
				for(int i=0;i<10;i++)
				{
					if(possible[0][i]!=possible[1][i])
					{
						pos=i+1;
						break;
					}
				}
				//142 query
				//query the bit different in 2 sets(atmax 2)
				cout << pos <<endl;
				cin >> temp;
				if(possible[0][pos-1]==temp)
				{
					front = possible[0];
				}
				else
				{
					front = possible[1];
				}

				vector<int> toeras;
				for(auto x:front)
				{
					toeras.pb(x^1);
				}
				s.erase(front);
				s.erase(toeras);
				//143 query
				//Now query the 20th bit
				//the strings complement can't be its back
				//we get resultant
				//output it
				cout << 20 << endl;
				cin >> temp;

				for(auto a:s)
				{
					if(a[0]==temp)
					{
						last = a;
						break;
					}
				}
				for(int i=0; i<10; i++)
				{
					cout << front[i];
				}
				for(int i=9; i>=0; i--)
				{
					cout << last[i];
				}
				cout<<endl;
			}
			else
			{
				cout << 1 << endl;
				cin >> temp;
				for(auto a:s)
				{
					if(a[0]==temp)
					{
						front = a;
						break;
					}
				}
				cout << 20 <<endl;
				cin >> temp;
				for(auto a:s)
				{
					if(a[0]==temp)
					{
						last = a;
						break;
					}
				}
				for(int i=0; i<10; i++)
				{
					cout << front[i];
				}
				for(int i=9; i>=0; i--)
				{
					cout << last[i];
				}
				cout<<endl;
			}	
		}
		char c;
		cin >> c;
		if (c == 'Y') continue;
		else break;
	}
	return 0;
}
