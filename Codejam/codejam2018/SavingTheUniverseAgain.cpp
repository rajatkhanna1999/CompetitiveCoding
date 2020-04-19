#include <bits/stdc++.h>

using namespace std;

long int func(string S)
{
    long int k=1,damage=0;
                       for(int i=0;i<S.length();i++)
                        {
                        if(S[i]=='S')
                        damage+=k;
                        else if(S[i]=='C')
                        k=k*2;
                        }
    return damage;
}
int main()
{
    int T,t;
    cin>>T;
    for(t=1;t<=T;t++){
    long int j,i,m,D,p,damage=0,y=0,k=1,num=0,cnt=0;
    cin>>D;
    string S;
    cin>>S;
    cout<<"Case #"<<t<<": ";
    for(i=0;i<S.length();i++)
    {
        if(S[i]=='S')
        {
            damage+=k;
        }
        else if(S[i]=='C')
        {
            k=k*2;
        }
    }
    if(D>=damage){
    cout<<"0"<<endl;
    continue;
    }
    else if(D<damage)
    {
        long int ans;
        for(j=S.length()-1;j>=0;j--)
        {
            if(S[j]=='S')
                {
                 k=j-1;
                 p=j;
                 if(S[k]=='C')
                 {
                    z:;
                    if(y!=1){
                    S[j]='C';
                    S[k]='S';
                    }
                    if(y==1){
                    S[p]='C';
                    S[p-1]='S';
                    y=0;
                    }
                    num++;
                    ans=func(S);
                    if(D>=ans){
                         cout<<num<<endl;
                         goto r;
                    }
                    p=p+1;
                    if(p<=S.length()-1){
                    if(S[p]=='S')
                    {
                        y=1;
                        goto z;
                    }
                    }
                 }

                }
        }

    }
    cout<<"IMPOSSIBLE"<<endl;
    r:;
    }
    return 0;
}
