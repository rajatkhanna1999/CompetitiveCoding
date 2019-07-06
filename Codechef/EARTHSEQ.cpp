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
bool primes[1000005];
vector<ll> v;

void Sieve() 
{ 
    memset(primes, true, sizeof(primes)); 
    for (ll i=2; i*i<=1000000; i++) 
    { 
        if (primes[i] == true) 
        {   
            for (ll j=i*i; j<=1000000; j += i) 
                primes[j] = false; 
        } 
    } 
  
    for (ll i=2; i<=1000000; i++) 
       if (primes[i]) 
          v.push_back(i); 
} 

int main(int argc, char const *argv[])
{
	sync;
	ll t;
	cin>>t;
	Sieve();
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n+5]={0};
		bool flag=false;
		for(ll i=1;i<=n;i++)
		{
			if(i==3201)
			{
				//a[i]=v[i-1]*v[0];
				flag=true;
				break;
			}
			if(i==n){
				a[i]=v[i-1]*v[0];
				break;
			}
			else
				a[i]=v[i-1]*v[i];
		}

		if(flag)
		{
			ll k=3201;
			ll i=3200;
			ll j=2;
			while(k<=(n-2))
			{
				if(j==250)
					j=2;
				a[k]=v[i]*v[j];
				a[k+1]=v[i+1]*v[j];
				k=k+2;
				i++;
				j++;
			}
			if(n%2==0){
				//a[k]=v[i]*v[0];
				a[k]=v[i]*v[j];
				a[k+1]=v[j]*v[0];
			}
			else
			{
				//a[k]=v[i]*v[j];
				//a[k+1]=v[j]*v[0];
				a[k]=v[i]*v[0];
			}
		}
		for(ll i=1;i<=n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
