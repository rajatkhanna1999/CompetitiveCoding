#include <bits/stdc++.h>
/*
pair<int,pair<int,int>> func(string A,int sum1,int sum2)
{
    pair<int,pair<int,int>>a;
 int len=strlen(A);
 if(A[len-1]=='a')
    sum1++;
    else
    sum2++;

  if(sum1>sum2)


}
*/
using namespace std;

int main()
{
    int T,n;
    string S,S1;
    cin>>T;
    while(T>0)
    {
     int len,s1=0,s2=0,cnt=0;

     cin>>S;
     S1=S;
      len=S.size();
     cin>>n;
     for(int i=1;i<n;i++)
            S+=S1;
   /*  if(S[0]=='a'){
      s1++;
      cnt++;
     }
     else
        s2++;*/
    for(int i=0;i<len*n;i++){
       if(S[i]=='a')
        s1++;
       else
        s2++;
       if(s1>s2)
        cnt++;
    }
    cout<<cnt<<endl;
    T--;
    }

    return 0;
}