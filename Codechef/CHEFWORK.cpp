#include <iostream>

using namespace std;

int main()
{
    int N,T[1001];
    long long int arr[1001],min1=100002,min2=100002,min3=100002;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    for(int j=0;j<N;j++)
        cin>>T[j];
    for(int i=0;i<N;i++)
    {
        if(T[i]==1)
        {
            if(arr[i]<min1)
                min1=arr[i];
        }
        if(T[i]==2)
        {
            if(arr[i]<min2)
                min2=arr[i];
        }
        if(T[i]==3)
        {
            if(arr[i]<min3)
                min3=arr[i];
        }
    }
    if(min3>=(min1+min2))
        cout<<min1+min2<<endl;
    else
        cout<<min3<<endl;
    return 0;
}
