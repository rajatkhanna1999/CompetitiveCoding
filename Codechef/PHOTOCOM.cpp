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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		string s1,s2;
		ll h1,w1,h2,w2;
		cin>>h1>>w1;
		cin>>s1;
		cin>>h2>>w2;
		cin>>s2;
		ll lcm1,lcm2;
		lcm1=(h1*h2)/__gcd(h1,h2);
		lcm2=(w1*w2)/__gcd(w1,w2);
		string l1="xxxxxxxxxxxxxxxxxxxxx",l2="kkkkkkkkkkkkkkkkkkkkkkkkk";
		ll len1=s1.size();
		ll len2=s2.size();

		//cout<<lcm1<<" "<<lcm2<<endl;
		ll ans=lcm2*lcm1;

	while(l1.size()<=ans)
	{
		l1=l1+l1;
		l2=l2+l2;
	}

  ll v1=lcm1/h1;
  ll v2=lcm2/w1;

	for(ll q=0;q<h1;q++)
	{
		for(ll i=0;i<w1;i++)
		{
			for(ll k=0;k<v1;k++)
			{
				for(ll j=0;j<v2;j++)
				{
					l1[(q*lcm2*v1+i*v2+k*lcm2)+j]=s1[q*w1+i];
					//cout<<" S[i] & l "<<s1[i]<<" "<<l1[(k*lcm2)+j]<<" qikj "<<q<<" "<<i<<" "<<j<<" "<<k<<endl;
					//cout<<l1<<endl;
				}
			}
		}

	}
   ll v3=lcm1/h2;
   ll v4=lcm2/w2;

	for(ll q=0;q<h2;q++)
	{
		for(ll i=0;i<w2;i++)
		{
			for(ll k=0;k<(lcm1)/h2;k++)
			{
				for(ll j=0;j<(lcm2/w2);j++)
				{
					l2[q*lcm2*v3+i*v4+k*lcm2+j]=s2[q*w2+i];
					//cout<<" S[i] & l "<<s2[i]<<" "<<l2[(k*lcm2)+j]<<" qikj "<<q<<" "<<i<<" "<<j<<" "<<k<<endl;
					//cout<<l2<<endl;
				}
			}
		}

	}
   ll cnt=0;
   for(ll i=0;i<l1.size();i++){
   		if(l1[i]==l2[i])
   			cnt++;
   }

   		cout<<cnt<<endl;
	}
	return 0;
}
