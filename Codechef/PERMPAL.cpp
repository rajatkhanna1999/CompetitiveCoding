#include <iostream>
#include <stdio.h>
using namespace std;
//rajat khanna-feb long challenge

bool helper(int s , int e , pair<int,char>*b)
{
    if(s>=e)
        return true;
    int j;
    if(b[e].second!=b[s].second)
    {
    for(j=s+1;j<e;j++)
    {
    if(b[j].second==b[s].second)
    {
        int p;
        char t;
        t=b[j].second;
        b[j].second=b[e].second;
        b[e].second=t;

        p=b[j].first;
        b[j].first=b[e].first;
        b[e].first=p;

        break;

    }
    else if(b[j].second==b[e].second)
    {
         int p;
        char t;
        t=b[j].second;
        b[j].second=b[s].second;
        b[s].second=t;

        p=b[j].first;
        b[j].first=b[s].first;
        b[s].first=p;

        break;

    }

    }
    if(e-1<j)
        return false;
    }
    return helper(s+1,e-1,b);
}

int main()
{
int t;
cin>>t;
while(t>0)
{
    //pair class can store two things in array like 2 int , 1in1 i char or both char
    string S;
    cin>>S;
    long len=S.length();
    pair<int,char>*a=new pair<int,char>[len];

    for(int k=0;k<len;k++)
    {
        a[k].first=k+1;
        a[k].second=S[k];
    }
     bool result;
     result  = helper(0,len-1,a);

     if(result==false)
     {
         printf("-1\n");
         continue;
     }
     for(int j=0;j<len;j++)
     {
         cout<<a[j].first;
         printf(" ");
     }
     printf("\n");
    t--;
}

    return 0;
}
