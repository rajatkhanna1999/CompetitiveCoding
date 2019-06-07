#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;

int main()
{
    long t;
    cin>>t;
    while(t>0){
    string S;
    cin>>S;
    long sum=0;
    long len=S.length();
    for(long i=0;i<=len-4;i++)
    {
        string A=S.substr(i,4);
        string B[24]={"chef","chfe","cehf","cefh","cfhe","cfeh","hcef","hcfe","hfce","hfec","hefc","hecf","efhc","efch","echf","ecfh","ehcf","ehfc","fech","fehc","fche","fceh","fhce","fhec"};

      //  if(strcmp(A,("chef"||"chfe"||"cehf"||"cefh"||"cfhe"||"cfeh"||"hcef"||"hcfe"||"hfce"||"hfec"||"hefc"||"hecf"||"efhc"||"efch"||"echf"||"ecfh"||"ehcf"||"ehfc"||"fech"||"fehc"||"fche"||"fceh"||"fhce"||"fhec")))
       //   sum=sum+1;
       for(int k=0;k<24;k++){
      if(A.compare(B[k])==0){
        sum=sum+1;
       }
       }
    }
    if(sum==0)
        cout<<"normal"<<endl;
    else
        cout<<"lovely"<<" "<<sum<<endl;
     t--;
    }
    return 0;
}
