#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int input[100][100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>input[i][j];
        }
    }

    for(int j=0;j<n;j++)
    {
        for(int i=n-1;i>=0;i--)
        {
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }


	return 0;
}
