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
bool compare(pll a, pll b){
	if(a.x == b.x){
		return a.y < b.y;
	}
	return a.x < b.x;
}

int main(int argc, char const *argv[])
{
	sync;
	ll t, T = 1;
	cin >> t;
	while(t--)
	{
		codejamDebug(T);
		T++;
		ll n;
		cin >> n;
		pll points[n+5];
		map<ll,ll> my1, my2;
		rep(i,n){
			cin >> points[i].x >> points[i].y;
			my1[points[i].y]++;
			my2[points[i].x]++;
		}
		// if(n <= 4){
		// 	cout << n << endl;
		// 	continue;
		// }
		//horizontal
		ll ans1 = 0, cnt1 = 0;
		for(auto a: my1){
			if(a.second >= 2){
				ans1 += a.second;
			}else{
				cnt1++;
			}
		}
		if(cnt1 >=2 ){
			ans1 += 2;
		}else{
			ans1 += cnt1;
		}
		//vertical
		ll ans2 = 0, cnt2 = 0;
		for(auto a: my2){
			if(a.second >= 2){
				ans2 += a.second;
			}else{
				cnt2++;
			}
		}
		if(cnt2 >=2 ){
			ans2 += 2;
		}else{
			ans2 += cnt2;
		}
		//slope
		map<pll,set<int>> lol;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				ll y1 = points[j].y - points[i].y;
				ll x1 = points[j].x - points[i].x;
				if(y1 == 0 || x1 == 0)continue;
				ll gc = __gcd(abs(y1),abs(x1));
				y1 /= gc, x1 /= gc;
				cout << y1 sp x1 sp i sp j << endl;
				lol[{y1,x1}].insert(i);
				lol[{y1,x1}].insert(j);
 			}
		}
		ll ans = 0;
		for(auto a: lol){
			ll cnt = a.second.size();
			cout << cnt sp a.first.first sp a.first.second << endl;
			// for(auto kya: a.second){
			// 	cout << kya << " ";
			// }
			// cout << endl;
			cnt += 2;
			if(cnt >= n)cnt = n;
			ans = max(ans,cnt);
		}
		//cout << ans sp ans2 sp ans1 << endl;
		cout << max(ans,max(ans1,ans2)) << endl;
	}
	return 0;
}
/*
5
0 0
1 1
2 3
4 7
19 20
*/
