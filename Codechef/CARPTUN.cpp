#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0){
    long n;
    cin>>n;
    long arr[100001];
    long c,d,s;
    long maxval;
   // float ans;
    for(long i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0)
            maxval=arr[i];
            else
                if(arr[i]>maxval)
                maxval=arr[i];
    }
    cin>>c>>d>>s;
   // ans=(double)(c-1)*maxval;
    printf("%f",(double)(c-1)*maxval);
    cout<<endl;
    t--;
    }
    return 0;
}
