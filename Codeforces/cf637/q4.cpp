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
int Num(string s, int a)
{
	string t[10];
	t[0]="1110111";
	t[1]="0010010";
	t[2]="1011101";
	t[3]="1011011";
	t[4]="0111010";
	t[5]="1101011";
	t[6]="1101111";
	t[7]="1010010";
	t[8]="1111111";
	t[9]="1111011";
	int cnt=0;
	for(int i=0; i<=7; i++)
	{
		if(t[a][i]=='1' && s[i]=='0')cnt++;
		if(t[a][i]=='0' && s[i]=='1')
		{
			cnt = -1;
			return -1;
		}
	}
	return cnt;
}

int bits(int a)
{
	int bit[10];
	bit[0]=6;
	bit[1]=2;
	bit[2]=5;
	bit[3]=5;
	bit[4]=4;
	bit[5]=5;
	bit[6]=6;
	bit[7]=3;
	bit[8]=7;
	bit[9]=6;
	return bit[a];
}

int maxfrombit(int a)
{
	if(a==2)return 1;
	else if(a==3)return 7;
	else if(a==4)return 4;
	else if(a==5)return 5;
	else if(a==6)return 9;
	else if(a==7)return 8;
}

int main(int argc, char const *argv[])
{
	sync;
	int n, k;
	cin >> n >> k;
	string s[n+5];
	rep(i,n)cin >> s[i];
	int zeros=0;
	rep(i,n)
	{
		rep(j,8)
		{
			if(s[i][j]=='0')zeros++;
		}
	}
	if(zeros<k)
	{
		cout << "-1" << endl;
		return 0;
	}
	bool flag = true;
	int moves = k;
	int val, idx=-1;
	int a[n+5];
	memset(a,-1,sizeof(a));
	for(int i=0; i<n; i++)
	{
		for(int j=9; j>=0; j--)
		{
			val = Num(s[i],j);
			//cout << "val" sp val sp j << endl;
			if(val==-1 || val>moves)
			{
				continue;
			}
			else
			{
				a[i] = j;
				moves-=val;
				break;
			}
		}
		if(a[i]==-1)
		{
			idx=i;
			flag = false;
			break;
		}
	}
	// //debug

	// rep(i,n)cout << a[i];
	
	// cout << endl << moves << endl;
	// //
	if(!flag)
	{
		for(int i=idx; i<n; i++)
		{
			int miniMoves=10, minValue=0;
			for(int j=9; j>=0; j--)
			{
				val = Num(s[i],j);
				if(val!=-1)
				{
					if(val<miniMoves)
					{
						miniMoves = val;
						minValue = j;
					}
					if(val==miniMoves)
					{
						minValue = max(minValue, j);
					}
				}
			}
			a[i]=minValue;
			moves-=miniMoves;
		}
		// //
		// rep(i,n)cout << a[i];

		// cout << endl << moves << endl;
		// //
		for(int i=idx-1; i>=0; i--)
		{
			int curr = Num(s[i],a[i]);
			int maxMoves=0, maxValue=0;
			for(int j=9; j>=0; j--)
			{
				val = Num(s[i],j);
				if(val!=-1)
				{
					if(val>maxMoves)
					{
						maxMoves = val;
						maxValue = j;
					}
					if(val==maxMoves)
					{
						maxValue = max(maxValue, j);
					}
				}
			}
			int gain =  maxMoves - curr;
			if(gain<=abs(moves))
			{
				a[i] =maxValue;
				moves+=gain;
			}
			else
			{
				for(int j=9; j>=0; j--)
				{
					val = Num(s[i],j);
					if(val!=-1)
					{
						if((val-curr)==abs(moves))
						{
							a[i] = j;
							moves=0;
						}
					}
				}
			}
			if(moves==0)
			{
				flag = true;
				break;
			}
		}
		if(moves==0)
		{
			rep(i,n)cout << a[i];
			return 0;
		}
		if(moves<0)
		{
			cout << "-1" << endl;
			return 0;
		}
	}
	if(moves>0)
	{
		//cout << moves sp a[0] << endl;
		for(int i=n-1; i>=0; i--)
		{
			int curr = Num(s[i],a[i]);
			int maxMoves=0, maxValue=0;
			for(int j=9; j>=0; j--)
			{
				val = Num(s[i],j);
				if(val!=-1)
				{
					if(val>maxMoves)
					{
						maxMoves = val;
						maxValue = j;
					}
					if(val==maxMoves)
					{
						maxValue = max(maxValue, j);
					}
				}
			}
			int gain =  maxMoves - curr;
			//cout << gain << endl;
			if(gain<=moves)
			{
				a[i] = maxValue;
				moves-=gain;
			}
			else
			{
				for(int j=9; j>=0; j--)
				{
					val = Num(s[i],j);
					if(val!=-1)
					{
						if((val-curr)==abs(moves))
						{
							a[i] = j;
							moves=0;
						}
					}
				}
			}
		}
	}
	if(moves>0)
	{
		cout << "-1" << endl;
		return 0;
	}
	rep(i,n)cout << a[i];
	return 0;
}
