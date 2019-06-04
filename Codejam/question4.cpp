#include <iostream>

using namespace std;

int main()
{
    int T,t;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        int A[1001][1001]={0},i,a,b,j,n,cnt=0;
        cin>>n;
        i=2;
        j=2;
        while(cnt<n)
        {
            while(A[i][j]==0 || A[i-1][j]==0 || A[i+1][j]==0 || A[i][j+1]==0 || A[i-1][j+1]==0 || A[i+1][j+1]==0 || A[i][j-1]==0 || A[i-1][j-1]==0 || A[i+1][j-1]==0 ){
            cout<<i<<" "<<j<<endl;
            cin>>a>>b;
            if(a==0 && b==0)
                break;
            A[a][b]=1;
            }
            cnt=cnt+9;
            j=j+3;
            if(a==0 && b==0)
                break;
        }
    }

    return 0;
}
