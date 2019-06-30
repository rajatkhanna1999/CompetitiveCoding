#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.14159265358979323
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long int ll;             
typedef unsigned long long int ull;

//handle:cyber_rajat

void index(ll a[] , ll ix , ll n,ll k, ll* arr)
{
	ll iter,ix1=0,ix2=0,value;                 //fval=value,ind =ix1,ind2=ix2
	for(ll j=ix+1 ; j<=k ; j++)
      if(a[ix]>a[j])ix1++;
	for(ll j=ix-1 ; j>=0&&j>=(ix-k) ; j--)
      if(a[ix]>a[j])ix2++;
     	
	
        value=max(ix1,ix2);
        arr[ix]=arr[ix]+value;
        iter=ix;
    
                 while(iter>0)
                 {
                    for(ll i=iter-1; i>=0&&i>=(iter-k) ; i--){
                      if(  a[iter]<a[i]&&arr[iter]>=arr[i] )arr[i]=arr[iter]+1;    //checking small number to left of it

                      else if( a[iter]==a[i]&&( arr[iter]<arr[i]||arr[iter]>arr[i] ))
                      {
                          if(arr[iter]<arr[i])
                            arr[iter]=arr[i];
                          else
                            arr[i]=arr[iter];
                      }  

                      else if( a[iter]>a[i]&&arr[iter]<=arr[i] )arr[iter]=arr[i]+1;
                      }

                    for(ll j=iter+1 ; j<=(iter+k)&&j<=ix ; j++){
                       if( a[iter]<a[j]&&arr[iter]>=arr[j] )arr[j]=arr[iter]+1;   //checking small number to right of it
                 
                       else if(  a[iter]==a[j]&&( arr[iter]<arr[j]||arr[iter]>arr[j] ))
                       {
                            if(arr[iter]<arr[j])
                               arr[iter]=arr[j];
                            else
                               arr[j]=arr[iter];
                        }

                        else if(  a[iter]>a[j]&&arr[iter]<=arr[j] )arr[iter]=arr[j]+1;
                        }
                  
                            iter--;
                  }
 	
}

bool Possiblity(ll a[],ll s,ll k,ll n)
{
  ll* arr=new ll[n];
  ll resum=0;
    for(ll i=0;i<n;i++)
       arr[i]=1;
    for(ll i=0;i<n;i++)
 	      index(a,i,n,k,arr);           //if possible at that k or not
    for(ll i=0;i<n;i++)
        resum=resum+arr[i];
    if(resum>s)
	      return false;
    else
	     return true;
}

int main()
{
	ll T;
	cin>>T;
	while(T--)
	{
		ll n,s;
		cin>>n>>s;
		ll a[n];
		  for(ll i=0;i<n;i++)
			 cin>>a[i];
     ll st=0,e=n,res=-1;             //searching the element
     while(st<=e)
     {
       ll mid=(st+e)/2;
        if(Possiblity(a,s,mid,n))
          res=mid,st=mid+1;
        else
          e=mid-1;
     }
		cout<<res+1<<endl;             //outputting result
	}
	return 0;
}
