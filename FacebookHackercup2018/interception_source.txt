#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("interception-1.txt", "r", stdin);
    freopen("interseption_solution2.txt", "w", stdout);
  int t,j,T;
  cin>>T;
  j=1;
  t=T;
  while(t--)
  {
  	int N;
    cin>>N;

   int a[52];
   for(int i=0;i<=N;i++)
   {
   	cin>>a[i];
   }

  if(N%2==0)
  {
   cout<<"Case #"<<j<<": 0"<<endl;
  }
  else
  {
   cout<<"Case #"<<j<<": 1"<<endl;
   cout<<"0.0"<<endl; 
  }

  j++;
  }

}
