#include <bits/stdc++.h>
#define D 1000000007
using namespace std;

long long power_fast(long long int a,long long int n)
{
    if(n==0)
    return 1;
    if(n%2==0)
    return power_fast((a*a)%D,n/2);
    return (a*power_fast((a*a)%D,n/2))%D;
}
int main()
{
    long long int N,W,T;
    //long int D;
    
   // D=pow(10,9)+7;
    //cout<<y<<endl;
    cin>>T;
    while(T>0)
    {
        long long int product=1;
        cin>>N;
        cin>>W;
        long long int n=N-2;
        long long int count1=0;
        product=power_fast(10,n);
      //  cout<<product<<endl;
       /* for(int i=1;i<=N-2;i++)
        {
            product=(product*10)%D;
        }*/
        
       /* while(n>0)
        {
          if(n%2==0)
          {
          product=(product*100)%D;
          n=n/2;
          }
          else
          {
              product=(10*((product*100)%D))%D;
              n=n/2;
          }
        }*/
        for(int i=0;i<=9;i++)
        {
         for(int j=1;j<=9;j++)
         {
             if(i-j==W)
                count1++;
         }
        }
        cout<<(count1*product)%D<<endl;
        T--;
    }
    return 0;
}
