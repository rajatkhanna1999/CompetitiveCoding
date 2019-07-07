#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.14159265358979323
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long int ll;             
typedef unsigned long long int ull;

//handle:cyber_rajat

ll gcd(ll a,ll b)
{
 if(b==0)
 	return a;
 else
  return gcd(b,a%b);
}

ll power_fast(ll x , ll p)
{
  if(p==0)
  	return 1;
  if(p%2==0)
     return power_fast((x*x)%mod,p/2);
  	else
     return (x*power_fast((x*x)%mod,p/2))%mod;
}

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		ll a,b,n;
		cin>>a>>b>>n;
        ll var1,var2,var5,var3,var4;
        if((a-b)==0)
        {
          var1=(power_fast(a,n)+power_fast(b,n))%mod;
          cout<<var1<<endl;
        }
        else if(n%2==1)
        {
        	var1=gcd((a+b),(a-b));
        	var2=gcd(a,((a-b)/var1));
        	var3=gcd(b,((a-b)/(var1*var2)));
        	var4=gcd((var1*var2*var3),(a-b));
        	var5=var4%mod;
        	cout<<var5<<endl;
        }
        else if(n%2==0)
        {
        	var1=gcd(a,(a-b));
        	var2=gcd(b,((a-b)/var1));
        	var3=gcd((var2*var1*2),(a-b));
        	var4=var3%mod;
        	cout<<var4<<endl;
        }
	}
	return 0;
}