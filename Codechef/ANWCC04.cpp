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
	sync;
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll total_ans1=0,total_ans2=0;
		ll ans=0,ans1=0;
		char pchar='+';
		bool f=false;
		for(ll i=0;i<s.size();i++)
		{
			//cout<<ans<<" "<<i<<f<<" "<<total_ans1<<" "<<total_ans2<<endl;
			if(s[i]!='+' && s[i]!='-' && s[i]!='='){
				ans=ans*10+(s[i]-'0');
				continue;
			}
			if(pchar=='+' && (s[i]=='+' || s[i]=='-' || s[i]=='='))
			{
				if(f)
					total_ans2+=ans;
				else
					total_ans1+=ans;
			}
			else if(pchar=='-' && (s[i]=='+' || s[i]=='-' || s[i]=='='))
			{
				if(f)
					total_ans2-=ans;
				else
					total_ans1-=ans;
			}
			if(s[i]=='+')
				pchar='+',ans=0;
			else if(s[i]=='-')
				pchar='-',ans=0;
			else if(s[i]=='=')
				pchar='+',f=true,ans=0;
		}
		if(pchar=='+')
			total_ans2+=ans;
		else
			total_ans2-=ans;
		//cout<<total_ans2<<" "<<total_ans1<<endl;
		if(total_ans1!=total_ans2)
			cout<<"Invalid Equation"<<endl;
		else
			cout<<"Valid Equation"<<endl;
	}
	return 0;
}
