#include <bits/stdc++.h>
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
using namespace std;

#define sp << " " <<
#define mod 1000000007
#define PI 3.14159265358979323
#define y second
#define x first
#define pb push_back
#define mp make_pair
#define mem(a,b) memset(a,b,sizeof(a))
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
typedef pair <int, int>        pi;
typedef pair <ll, ll>          pll;
typedef vector < pll >        vpll;
typedef vector <string>         vs;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Handle:cyber_rajat
multiset<ll> st[200001];

int main(){
	int n, q;
	cin >> n >> q;
	int a, b;
	unordered_map<int, pi> mp;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		mp[i] = {a, b};
		st[b].insert(a);
	}
	set<pi> high;

	for(int i = 1; i <= 200001; i++){
		if (st[i].empty()){
			continue;
		}
		high.insert({*st[i].rbegin(), i});
	}
	rep(k, q){
		cin >> a >> b;

		int old_kinder = mp[a].y;
		int rating = mp[a].x;

		auto itr = st[old_kinder].find(rating);
		st[old_kinder].erase(itr);

		int early;
		if (st[b].empty()){
			early = -1;
		}
		else{
			early = *st[b].rbegin();
		}

		st[b].insert(rating);
		
		if (high.find({rating, old_kinder}) != high.end()){
			high.erase({rating, old_kinder});
			if (!st[old_kinder].empty()){
				high.insert({*st[old_kinder].rbegin(), old_kinder});
			}
		}

		if (high.find({early, b}) != high.end()){
			high.erase({early, b});
		}

		high.insert({*st[b].rbegin(), b});
		mp[a].y = b;
		pi mtp = *high.begin();
		cout << mtp.x << endl;
	}
}