#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define PI 3.14159265358979323
#define debug(x) cout<<"Case "<<x<<": "
#define For(i,n) for(long long i=0;i<n;i++)
#define Frabs(i,a,b) for(long long i = a; i < b; i++)
#define Frabr(i,a,b) for(long long i = a; i >=b; i--)
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


int main(int argc, char const *argv[])
{
	sync;
	ll q;
	cin>>q;
	while(q--)
	{
		ll ans=0;
		ll n,a,b;
		cin>>n>>a>>b;
		if(a==b/2)
			ans=n*a;
		else if(a<b/2)
			ans=n*a;
		else
		{
			if(n%2==0)
				ans=(n/2)*b;
			else
				ans=(n/2)*b + a;
		}
		cout<<ans<<endl;
	}
	return 0;
}
