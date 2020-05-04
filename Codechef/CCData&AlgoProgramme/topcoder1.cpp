#include <bits/stdc++.h>
using namespace std;

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

//Handle:cyber_rajat
class AveragePrice
{
public:
	double nonDuplicatedAverage(vector<int> a)
	{
		set<int> s;
		for(auto x:a)
		{
			s.insert(x);
		}
		int sum=0;
		for(auto x:s)
		{
			sum+=x;
		}
		double ans = (1.0*sum)/s.size();
	}
	
};

int main(int argc, char const *argv[])
{
	sync;
	ll t;
	cin >> t;
	while(t--)
	{

	}
	return 0;
}
