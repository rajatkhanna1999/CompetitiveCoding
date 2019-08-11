#include <bits/stdc++.h>
using namespace std;

void MagicGrid(int** input,int n,int m)
{
		int** dp=new int*[n];
		for(int i=0;i<n;i++)
		{
			dp[i]=new int [m];
		}
    dp[n-1][m-1]=1;
    for(int i=n-2;i>=0;i--){
    	dp[i][m-1]=dp[i+1][m-1]-input[i+1][m-1]; //dp[i][j] ka matlab hai ke (i,j) se aage kitne health chaheye
    	if(dp[i][m-1]<=0)                        //(i+i,j) & (i,j+1) pe call karega vo call plus corrosponding
    		dp[i][m-1]=1;                        //(i+1,j) & (i,j+1) pe jitne input pade hai unke sum ka minimum;
    }                                            // if yeh min<=0 the dp[i][j]=1 ; kyoke min health 1 required hai;
    for(int j=m-2;j>=0;j--){
    	dp[n-1][j]=dp[n-1][j+1]-input[n-1][j+1];
    	if(dp[n-1][j]<=0)
    		dp[n-1][j]=1;
    }
    for(int i=n-2;i>=0;i--)
    {
    	for(int j=m-2;j>=0;j--)
    	{
    		dp[i][j]=min((dp[i][j+1]-input[i][j+1]),(dp[i+1][j]-input[i+1][j]));
    		if(dp[i][j]<=0)
    			dp[i][j]=1;
    	}
    }
    cout<<dp[0][0]<<endl;
   /* for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cout<<dp[i][j]<<" ";
    	}
    	cout<<endl;
    }*/
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		int** input=new int*[r];
		for(int i=0;i<r;i++)
		{
			input[i]=new int [c];
		}
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>input[i][j];
			}
		}
		MagicGrid(input,r,c);
	}
	return 0;
}