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

//Handle:cyber_rajat

int main()
{
	ll n;
	cin>>n;
	ll a[30],b[30],c[30];
	for(ll i=0;i<=n;i++)
	{
		a[i]=i;
		b[i]=i;
    c[i]=i;
	}

	//Maximum Wala Case
  ll x=(n+1)/2+1; //Is element ko last me
  c[x]=1;         //1 ko is index pe
  c[n+1]=x;

  for(ll i=2;i<=n+1;i++)
    cout<<c[i]<<" ";

  cout<<endl;

	//Minimum Wala Case
    b[0]=a[n];
    for(ll i=0;i<n;i++)
    	cout<<b[i]<<" ";

    cout<<endl;
	return 0;
}
