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

//Handle:cyber_rajat

int main()
{
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		if(k==0)
			cout<<fixed<<setprecision(6)<<1.0/n<<endl;
		else if(n==1)
			cout<<"1.000000"<<endl;
		else if(n==2)
			cout<<"0.500000"<<endl;
		else 
		{
			if(n%4==0)
			{
				n=n/2;
			}
			else
			{
				n=(n/2)+1;
			}
			for(ll i=k-1;i>0;i--)
			{
				if(n<=1)
				{
					break;
				}
				if(n%2!=0)
				{
					n=(n/2)+1;
				}
				else
				{
					n=n/2;
				}
			}
			ld val=1.0/n;
			cout<<fixed<<setprecision(6)<<val<<endl;
		}
	}

	return 0;
}