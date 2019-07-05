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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,k;
		cin>>n>>m;
		ll a[n+5][m+5];
		if(n==1 && m==1)
		{
			cout<<"1"<<endl;
			cout<<"1"<<endl;
			continue;
		}
		if(n==1 && m==2)
		{
			cout<<"1"<<endl;
			cout<<"1 1"<<endl;
			continue;
		}
		if(n==2 && m==1)
		{
			cout<<"1"<<endl;
			cout<<"1"<<endl;
			cout<<"1"<<endl;
			continue;
		}
		if(n==2 && m==2)
		{
			cout<<"2"<<endl;
			cout<<"1 1"<<endl;
			cout<<"2 2"<<endl;
			continue;
		}
		if(n==1)
		{
			cout<<"2"<<endl;
			ll count=0;
			ll val=1;
			for(ll i=0;i<m;i++)
			{
				if(count==2)
				{
					count=0;
					if(val==1)
						val=2;
					else 
						val=1;
				}
				cout<<val<<" ";
				count++;
			}
			cout<<endl;
			continue;
		}
		if(m==1)
		{
			cout<<"2"<<endl;
			ll count=0;
			ll val=1;
			for(ll i=0;i<n;i++)
			{
				if(count==2)
				{
					count=0;
					if(val==1)
						val=2;
					else 
						val=1;
				}
				cout<<val<<endl;
				count++;
			}
			continue;
		}
		if(n==2)
		{
			cout<<"3"<<endl;
			ll val=1;
			ll count=0;
			ll pval=1;
			for(ll j=0;j<2;j++)
			{
				count=0;
				if(j==0)
					val=1;
				else
					val=2;
				for(ll i=0;i<m;i++){
					if(count==2)
						val=3;
					if(count==3)
					{
						count=0;
						if(pval==1)
							val=2;
						else
							val=1;
					}
					if(val!=3)
						pval=val;
					cout<<val<<" ";
					count++;
					}
					cout<<endl;
			}
			continue;
		}
		if(m==2)
		{
			cout<<"3"<<endl;
			ll temp[n+5][3];
			ll val=1;
			ll count=0;
			ll pval=1;
			for(ll j=0;j<2;j++)
			{
				count=0;
				if(j==0)
					val=1;
				else
					val=2;
				for(ll i=0;i<n;i++){
					if(count==2)
						val=3;
					if(count==3)
					{
						count=0;
						if(pval==1)
							val=2;
						else
							val=1;
					}
					if(val!=3)
						pval=val;
					a[i][j]=val;
					count++;
					}
			}
			for(ll i=0;i<n;i++)
			{
				for(ll j=0;j<2;j++)
				{
					cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
			continue;
		}
		if(n==3)
		{
			cout<<"4"<<endl;
			ll val=1;
			ll pval=3;
			for(ll j=0;j<m;j=j+2)
			{
				if(pval==3)
					val=1;
				else
					val=3;
				for(ll i=0;i<n;i++)
				{
					if(i==0)
						pval=val;
					if(val==5)
						val=1;
					a[i][j]=val;
					if(j!=(m-1))
						a[i][j+1]=val;
					val++;
				}
			}
			for(ll i=0;i<n;i++)
			{
				for(ll j=0;j<m;j++)
				{
					cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
			continue;
		}
		if(n>=4)
		{
			cout<<"4"<<endl;
			ll val=1;
			ll pval=3;
				for(ll j=0;j<m;j=j+2)
				{
					if(pval==1)
						val=3;
					else
						val=1;
					for(ll i=0;i<n;i++)
					{	
						if(i==0)
							pval=val;
						if(val==5)
							val=1;
						a[i][j]=val;
						if(j!=(m-1))
							a[i][j+1]=val;
						val++;
					}
				}
				for(ll i=0;i<n;i++)
				{
					for(ll j=0;j<m;j++)
					{
						cout<<a[i][j]<<" ";
					}
					cout<<endl;
				}
				continue;
		}
	} 	
	return 0;
}
