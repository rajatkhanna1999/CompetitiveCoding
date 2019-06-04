#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define PI 3.14159265358979323
#define debug(x) cout<<"Case "<<x<<": "
#define codejamDebug(x) cout<<"Case #"<<x<<": ";
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
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	ll t,T;
	cin>>t;
	for(ll T=1;T<=t;T++)
	{
		ll index=0,rem=0;
		codejamDebug(T);
		string s,temp,output;
		cin>>s;
		temp=s;
		bool flag=false;
		for(ll i=0;i<temp.size();i++)
		{
			if(temp[i]=='4')
			{
				temp[i]='3';
				output=output+"1";
				flag=true;
			}
			else
			{
				if(flag)
				output=output+"0";
			}
		}
		cout<<output<<" "<<temp<<endl;
	}

	return 0;
}
