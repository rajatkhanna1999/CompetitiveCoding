

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int a,b,c,d;
    while(t>0)
    {
    cin>>a>>b>>c>>d;
    int count =0;
    if(a==b)
    count++;
    if(a==c)
    count++;
    if(a==d)
    count++;
    if(b==c)
    count++;
    if(b==d)
    count++;
    if(c==d)
    count++;
    if(count==0)
    cout<<"NO"<<endl;
    else if(count%2==0)
    cout<<"YES"<<endl;
    else if(count%2!=0)
    cout<<"NO"<<endl;
    t--;
}
    return 0;
}

