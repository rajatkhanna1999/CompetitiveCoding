#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
 
void printPowerSet(  long*input , long set_size ,long x)
{
 
    long   pow_set_size = pow(2,set_size);
    long  counter, j;
    long  natsum=0;
    for( long i=1;i<=set_size;i++)
    {
        natsum=natsum+i;
    }
    long  natsumm=natsum-x;
    long  arr[1000000]={0};
   /* for(long long i=0;i<set_size;i++)
    {
        arr[i]=1;
    }*/
    
    arr[x-1]=2;
    
    /*if(natsum%2!=0)
    {
        cout<<"impossible"<<endl;
        printf("impossible");
    }*/
    if(natsum%2!=0 && x%2==0)
    cout<<"impossible"<<endl;
    else if(natsum%2==0 && x%2!=0)
        cout<<"impossible"<<endl;
    else{
    for(counter = 0; counter < (pow_set_size)/2; counter++)
    {
        long  sum=0;
      for(j = 0; j < set_size; j++)
       {
          
          if(counter & (1<<j))
          {
               long w=j;
              if(w!=(x-1))
              {
            sum=sum+input[j];
            arr[j]=1;
                  
             }
          }
       }
       
       if(sum==(natsumm/2))
       {
           for( long i=0;i<set_size;i++)
           {
              cout<<arr[i];
             /*  if(arr[0]==0)
               cout<<arr[i];
               else if (arr[0]=1)
               {
                   if(arr[i]==0)
                   cout<<1;
                   else if(arr[i]==1)
                   cout<<0;
                   else if(arr[i]==2)
                   cout<<2;
               }
               else if(arr[0]==2)
               cout<<arr[i];*/
           }
           cout<<endl;
           return ;
       }
       for(long i=0;i<set_size;i++)
    {
        arr[i]=0;
    }
    
    arr[x-1]=2;
      
    }
    cout<<"impossible"<<endl;
    }
    
}
 
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int  t;
    cin>>t;
    while(t>0){
    long  n,x;
    cin>>x>>n;
    long  input[1000000];
    for( long i=1;i<=n;i++)
    {
        input[i-1]=i;
    }
    
    printPowerSet( input, n , x);
    t--;
    }
    return 0;
}
 