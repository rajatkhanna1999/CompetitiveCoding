#include <iostream>

using namespace std;

int main()
{
 long long t,n;
  cin>>t;
  for(;t>0;t--)
  {
  cin>>n;
  long long arr[700][700];
  for(long long i=0;i<n;i++)
  {
    for(long long j=0;j<n;j++)
    {
        cin>>arr[i][j];
    }
  }
  long long ans[700], a=1;
   long long input[700];
  long long m,b;
long long  maximum=arr[n-1][0];
  for(long long i=1;i<n;i++)
  {
      if(arr[n-1][i]>=maximum)
        maximum=arr[n-1][i];
  }
  ans[0]=maximum;

  for(long long g=1;a<n && g<n;g++)
  {
      m=0;
  for(long long j=0;j<n;j++)
  {
    if(arr[n-1-g][j]<maximum)
    {
        input[m]=arr[n-1-g][j];
        m++;
    }
  }
  input[m]=-2;
   b=0;
  for(long long w=0;input[w]!=-2;w++)
  {
      b++;
  }
  if(b==0)
  {
  cout<<"-1"<<endl;
    break;
  }
int   inmax = input[0];
for(long long q=1;q<b;q++)
{
    if(input[q]>inmax)
        inmax=input[q];
}
ans[a]=inmax;
a++;
maximum=inmax;
  }
  if(b==0)
  continue;
  long long sum=0;
  for(long long s=0;s<n;s++)
  {
      sum=sum+ans[s];
  }
  cout<<sum<<endl;
}
    return 0;
}
