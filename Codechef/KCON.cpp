#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t>0)
	{
	    int a[100001];
	    int n,k;
	    cin>>n>>k;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    long long maxSum=0,currentSum=0,totalSum=0,use;
	    int count=0;
	    
	    for(int i=1;i<=2;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	        if(i==1)
	        totalSum+=a[j];
	        
	        currentSum+=a[j];
	        if(j==0||maxSum<currentSum)
	        maxSum=currentSum;
	        if(currentSum<0)
	        currentSum=0;
	        }
	        if(i==1)
	        use=maxSum;
	    }
	    
	    if(totalSum>0)
	    {
	        if(k==1)
	        cout<<use<<endl;
	        else
	        cout<<maxSum+(totalSum*(k-2))<<endl;
	    }
	    
	    else
	    {
	        if(k==1)
	        cout<<use<<endl;
	        else
	        cout<<maxSum<<endl;
	    }
	    t=t-1;
	    
	}
	return 0;
}
