#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define PI 3.14159265358979323
#define debug(x) cout<<"Case "<<x<<": "
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

//Handle: cyber_rajat

bool PerfectSqr(ll u) {
  long double xp=sqrt(u);
    if(xp==floor(xp))
        return true;
    else
        return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		ll a[n+1];
		for(ll i=1;i<=n;i++)
			cin>>a[i];
		while(q--)
		{
			ll l,r;
			cin>>l>>r;
		    	ll x;
			ll cnt=0;
			for(ll i=l;i<=r;i++)
			{
				x=a[i];
				for(ll j=i;j<=r;j++)
				{
					x=x&a[j];
					if(PerfectSqr(x))
						cnt++;
				}
			}
			cout<<cnt<<endl;
		}
	}

	return 0;
}