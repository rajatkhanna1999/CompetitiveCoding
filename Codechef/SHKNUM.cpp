#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.14159265358979323
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long int ll;             
typedef unsigned long long int ull;

//Rajat Khanna
//handle : cyber_rajat

ll calc(ll y)
{
  return y^(y&(y-1));        //did not know how to calculate rightmost saw this from net
} 

ll sol(ll x)
{
	ll cnt=0;
	for(ll j=31;j>=0;j--)           //shifting it 1 bit to right
		if((x&(1<<j))!=0)cnt++;			
	
		return cnt;               //outputting number of one's
} 

int main()
{
	ll T;
	cin>>T;                      //Test case
	while(T--)
	{
		ll n,res;
		cin>>n;                  //Inputting 
	    res=sol(n);
	    if(n==1)
			cout<<2;            //edge case
	    else if(res==3)
	       cout<<calc(n);
		else if(res==2)         //nothing required
          cout<<0;
		else if(res==1)         //one thing to add2^0;
			cout<<1;
		else
		{
			ll count,possiSum=0,possiAns=0,i,j;
			count=res;
			for(i=0;i<=31;i++)
			{
				if((n&(1<<i))!=0)possiSum+=pow(2,i),count--;  //1101101
				if(count==2)                                  //1011101
					break;                                    //0111101
			}
            	j=i+1;

            	if((n&(1<<j))==0)            //1st case 
              	possiAns=possiSum;                            //these are the only possible cases 
            	else                                          //and i have handelde these
            	{
            		j=j+1;
            		if((n&(1<<j))!=0)          //3nd case
            		{
            	  		ll temp , tempv;
                   		 temp=pow(2,j-1);
                  		 tempv=temp-possiSum+1;
                  		 possiAns=min(possiSum,tempv);
            		}
            		else                       //2nd case
            		{
            	 		ll temp;
                 		temp=pow(2,j-1);
                 		possiAns=temp-possiSum;
            		}
           		}
            cout<<possiAns;
		}
        cout<<endl;

	}
	return 0;
}
