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
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);

	ll T;
	cin>>T;
	while(T--)
	{
		string s1,s2;
		cin>>s1>>s2;
		ll l1,l2;
		l1=s1.size();
		l2=s2.size();
		char arr[l2+2][l1+2];
		for(ll i=1;i<=l1;i++)
			arr[0][i]=s1[i-1];


		for(ll i=1;i<=l2;i++)
			arr[i][0]=s2[i-1];


		for(ll i=1;i<=l2;i++)
		{
			for(ll j=1;j<=l1;j++)
			{
				if(arr[i-1][j]=='0' || arr[i][j-1]=='0')
					arr[i][j]='1';
				else
					arr[i][j]='0';
			}
		}

		ll q;
		cin>>q;
		while(q--)
		{
			ll l,r;
			cin>>l>>r;
			cout<<arr[l][r];
		}
		cout<<endl;
	}

	return 0;
}

