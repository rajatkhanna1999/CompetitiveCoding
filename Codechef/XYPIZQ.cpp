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
	ll T;
	cin>>T;
	while(T--)
	{
		ll n;
		cin>>n;
		ll x,y,z,t;
		cin>>t>>x>>y>>z;
		if(t==1)
		{
			if(x>y && y>z)
			{
				ll val=__gcd(2*n-y+2,2*n+1);
				cout<<(2*n-y+2)/val<<" "<<(2*n+1)/val<<endl;
			}
			else if(x<y && y<z)
			{
				ll val=__gcd(2*n-y,2*n+1);
				cout<<(2*n-y)/val<<" "<<(2*n+1)/val<<endl;
			}
			else if(x==z && x>y)
			{
				ll val=__gcd(y+1,2*n+1);
				cout<<(y+1)/val<<" "<<(2*n+1)/val<<endl;
			}
			else if(x==z && x<y)
			{
				ll val=__gcd(y-1,2*n+1);
				cout<<(y-1)/val<<" "<<(2*n+1)/val<<endl;
			}
		}
		else if(t==2)
		{
			if(x>y && y>z)
			{
				ll val=__gcd(2*n+1-2*y,2*n+1);
				cout<<(2*n+1-2*y)/val<<" "<<(2*n+1)/val<<endl;
			}
			else if(x<y && y<z)
			{
				ll val=__gcd(2*n+1-2*y,2*n+1);
				cout<<(2*n+1-2*y)/val<<" "<<(2*n+1)/val<<endl;
			}
			else if(x==z && x>y)
			{
				cout<<"0"<<" "<<"1"<<endl;
			}
			else if(x==z && x<y)
			{
				cout<<"0"<<" "<<"1"<<endl;
			}
		}
		else if(t==3)
		{
			if(x>y && y>z)
			{
				ll val=__gcd(2*n-y,2*n+1);
				cout<<(2*n-y)/val<<" "<<(2*n+1)/val<<endl;
			}
			else if(x<y && y<z)
			{
				ll val=__gcd(2*n-y+2,2*n+1);
				cout<<(2*n-y+2)/val<<" "<<(2*n+1)/val<<endl;
			}
			else if(x==z && x>y)
			{
				ll val=__gcd(y+1,2*n+1);
				cout<<(y+1)/val<<" "<<(2*n+1)/val<<endl;
			}
			else if(x==z && x<y)
			{
				ll val=__gcd(y-1,2*n+1);
				cout<<(y-1)/val<<" "<<(2*n+1)/val<<endl;
			}
		}
		else
		{
			if(x>y && y>z)
			{
				ll val=__gcd(2*n+1-2*y,2*n+1);
				cout<<(2*n+1-2*y)/val<<" "<<(2*n+1)/val<<endl;
			}
			else if(x<y && y<z)
			{
				ll val=__gcd(2*n+1-2*y,2*n+1);
				cout<<(2*n+1-2*y)/val<<" "<<(2*n+1)/val<<endl;
			}
			else if(x==z && x>y)
			{
				cout<<"0"<<" "<<"1"<<endl;
			}
			else if(x==z && x<y)
			{
				cout<<"0"<<" "<<"1"<<endl;
			}
		}
		//ll k=__gcd(2*n-y,2*n+1);
		//cout<<k<<endl;
		//cout<<(2*n-y)/k<<" "<<(2*n+1)/k<<endl;
	}
	return 0;
}
