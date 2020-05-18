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
	ll t, T = 1;
	cin >> t;
	while(t--)
	{
		codejamDebug(T);
		T++;
		int r, c;
		cin >> r >> c;
		string s[r+5];
		int freq[30]={0};
		rep(i,r){
			cin >> s[i];
			for(auto ch: s[i]){
				freq[ch-'A']++;
			}
		}
		int dp[r+5][c+5];
		vector<int> v;
		memset(dp,-1,sizeof(dp));
		for(int j = 0; j < c; j++){
			dp[r][j] = 0;
		}
		int cnt = 0;
		bool visted[30] = {false};
		bool flag;
		while(cnt < r*c){
			flag = false;
			rep(k,26){
				if(visted[k])continue;
				int num = 0;
				char curr = 'A' + k;
				for(int i = r-1; i >= 0; i--){
					for(int j = c-1; j >=0 ; j--){
						if(s[i][j] == curr && dp[i+1][j]!=-1){
							num++;
							dp[i][j] = 0;
						}
					}
				}
				//cout << curr sp num << endl;
				if(num == freq[k] && num!=0){
					cnt += freq[k];
					visted[k] = true;
					flag = true;
					v.pb(k);
					break;
				}else{
					//clean
					for(int i = r-1; i >= 0; i--){
						for(int j = c-1; j >=0 ; j--){
							if(s[i][j] == curr){
								dp[i][j] = -1;
							}	
						}
					}
				}
			}
			if(!flag){
				break;
			}
		}
		if(!flag)cout << "-1" << endl;
		else {
			for(auto c: v){
				cout << char(c + 'A');
			}
			cout << endl;
		}
	}
	return 0;
}
