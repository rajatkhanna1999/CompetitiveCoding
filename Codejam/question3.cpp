#include <bits/stdc++.h>

using namespace std;

void TripleSort(long int n,long int input[])
{
    long int i,k=0,l=0,z=0,x=0,B[100001],C[100001];
    for(i=0;i<n;i++)
    {
     if(i%2==0){
         B[k]=input[i];
         k++;
     }
     else
     {
         C[l]=input[i];
         l++;
     }
    }
    sort(B,B+k);
    sort(C,C+l);
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        {
         input[i]=B[z];
         z++;
        }
        else
        {
        input[i]=C[x];
        x++;
        }
    }
}
/*
void tripleSort(long int n,long int input[])
{



    long int i,j;
    for(j=1;j<=n-2;j++){
    for(i=0;i<=n-3;i++)
    {
        if(input[i]>input[i+2])
        {
            long int temp=input[i+2];
            input[i+2]=input[i];
            input[i]=temp;
        }
    }
    }
}*/

int main()
{
   int t,T;
   cin>>T;
   for(t=1;t<=T;t++)
   {

       long int n,i,input[100001],A[100001];
       cin>>n;
       for(i=0;i<n;i++)
       {
           scanf("%ld",&input[i]);
           A[i]=input[i];
       }
       cout<<"Case #"<<t<<": ";
       sort(A,A+n);
       TripleSort(n,input);
       for(i=0;i<n;i++)
       {
           if(A[i]!=input[i])
           {
               cout<<i<<endl;
               goto r;
           }
       }
       cout<<"OK"<<endl;
       r:;
   }
    return 0;
}
