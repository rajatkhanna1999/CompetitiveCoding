#include <bits/stdc++.h>
using namespace std;

#define MAX 1005
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

//Handle:cyber_rajat

ll power_fast(ll x,ll p)
{
	if(p==0)
		return 1;
	if(p%2==0)
		return power_fast((x*x)%mod,p/2);
	return (x*(power_fast((x*x)%mod,p/2))%mod)%mod;
}

ll Pa_triangle[MAX + 6][MAX + 6];

void func() {
    Pa_triangle[0][0] = 1,Pa_triangle[1][0]=1,Pa_triangle[1][1]=1;

    for(ll i = 2; i < MAX; i++) {
        Pa_triangle[i][0] = 1;
        for(ll j = 1; j <= i; j++) {
            Pa_triangle[i][j] = (Pa_triangle[i - 1][j - 1] + Pa_triangle[i - 1][j])%mod;
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	func();
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll arr[1010];
		vector<ll> v1,v2;

		for(ll i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]%2==0)
				v1.push_back(arr[i]);
			else
				v2.push_back(arr[i]);
		}

		ll result=0;
		result=(result+power_fast(2,n-1))%mod;//odd elements added
		//cout<<result<<endl;

		//sorting
		sort(arr,arr+n);

		//Now for even elements
		for(ll i=0;i<n;i++)
		{
			for(ll j=i+1;j<n && (arr[j]==arr[i]);j++)
			{
				//cout<<"hi"<<i<<" "<<j<<endl;
				/*for(ll k=0;k<=i;k++)
				{
					result=(result+(Pa_triangle[n-1-j][k]*Pa_triangle[i][k])%mod)%mod;
				}*/
				//because ic0*n-j-1c0+ic1*n-j-1c1+ic2*n-j-1c2=n+i-j-1
				result=(result+Pa_triangle[n-j+i-1][i])%mod;
			}
		}
		cout<<result<<endl;
	}
	return 0;
}
/*
1
10
1 2 4 2 4 4 8 4 9 8
*/