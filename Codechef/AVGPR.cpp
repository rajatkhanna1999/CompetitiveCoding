#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    long int N,arr[100001],A[100001],B[100001],C[1000001]={0};
    cin>>T;
    while(T>0)
    {
        cin>>N;
        long int k=0,j=0,l=0;
        for(long int i=0;i<N;i++)
        {
            cin>>arr[i];
            if(arr[i]%2==0)
            {
                A[k]=arr[i];
              //  cout<<A[k]<<endl;
                k++;
            }
            else
            {
                B[j]=arr[i];
               // cout<<B[j]<<endl;
                j++;
            }
        }
        for(long int i=0;i<k;i++)
        {
            for(long int m=i+1;m<k;m++)
            {
                C[l]=(A[i]+A[m])/2;
               // cout<<C[l]<<endl;
                l++;
            }
        }
        for(long int i=0;i<j;i++)
        {
            for(long int m=i+1;m<j;m++)
            {
                C[l]=(B[i]+B[m])/2;
               // cout<<C[l]<<endl;
                l++;
            }
        }
        long long int cnt=0;
        for(long int i=0;i<l;i++)
        {
             for(long int p=0;p<N;p++)
             {
                 if(C[i]==arr[p])
                 {
                     cnt++;
                   //  cout<<C[i]<<endl;
                     break;
                 }
             }
        }
        cout<<cnt<<endl;

        T--;
    }
    return 0;
}
