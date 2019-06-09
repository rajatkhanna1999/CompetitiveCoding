#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0){
    int n;
    cin>>n;
    vector<int>v;
    vector<int>vo;
    int a;
    for(int i=0;i<n;i++)
    {
       cin>>a;
       v.push_back(a);
       if(v[i]%2!=0){
        vo.push_back(v[i]);
       }
    }
    if(vo.size()%2==0)
        cout<<"1"<<endl;
    else
    {
        cout<<"2"<<endl;
    }
    t--;
    }
    return 0;
}
