#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0){
    int m;
    long n,x,k;
    cin>>n>>m>>x>>k;
    char arr[1000000];
    long sume=0,sumo=0;
    for(long i=0;i<k;i++)
    {
        cin>>arr[i];
        if(arr[i]=='E')
            sume=sume+1;
        else if(arr[i]=='O')
            sumo=sumo+1;
    }
        int e=0,o=0;
       if(m==1)
       {
          e=0;
          o=1;
       }
       else if(m==2)
       {
           e=1;
           o=1;
       }
       else if(m==3)
       {
           e=1;
           o=2;
       }
       else if(m==4)
       {
           e=2;
           o=2;
       }
       else if(m==5)
       {
           e=2;
           o=3;
       }
       else if(m==6)
       {
           e=3;
           o=3;
       }
       else if(m==7)
       {
           e=3;
           o=4;
       }
       else if(m==8)
       {
           e=4;
           o=4;
       }
       else if(m==9)
       {
           e=4;
           o=5;
       }
       else if(m==10)
       {
           e=5;
           o=5;
       }
       else if(m==11)
       {
           e=5;
           o=6;
       }
       else if(m==12)
       {
           e=6;
           o=6;
       }
       long odd,even;
    long a = o*x;
    long b = e*x;
    if(b>sume)
        even=sume;
    else
        even=b;
        
    if(a>sumo)
        odd=sumo;
    else
        odd=a;
     
   
    long c=even+odd;
    
    if(c<n)
        cout<<"no"<<endl;
    else
        cout<<"yes"<<endl;
        
        t--;
    }
    return 0;
}
