#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,cnt=0;
    cin>>n;
    string a[50001];
    int sum=0;
   // string b[6]={"ch","he","ef","che","hef","chef"};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        int b1=a[i].find("ch");
        int b2=a[i].find("he");
        int b3=a[i].find("ef");
        int b4=a[i].find("che");
        int b5=a[i].find("hef");
        int b6=a[i].find("chef");
        sum=b1+b2+b3+b4+b5+b6;
        if(sum!=-6){
        cnt++;
        }
      //  break;
       // }

    }
    cout<<cnt<<endl;
    return 0;
}
