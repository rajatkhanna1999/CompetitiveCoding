#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.14159265358979323
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long int ll;             
typedef unsigned long long int ull;

//Rajat Khanna
//handle : cyber_rajat

int main()
{
	ll T;                                //Inputting test cases;
	cin>>T;
	while(T--)
	{
		string a;
		string b;
		cin>>a>>b;                       //Inputting Strings
		if(b[0]=='b')
		{
         	if((a[1]=='o'||b[1]=='o')&&(a[2]=='b'||b[2]=='b')){                  //goto for breaking the statement
            	cout<<"yes";
                goto label;                                                        
            	}
            else if((a[1]=='b'||b[1]=='b')&&(a[2]=='o'||b[2]=='o')){      //Handling cases
         		cout<<"yes";                                              //bob
         		goto label;                                               //bbo
            	}
		}
		else if(b[0]=='o')
		{
         	if((a[1]=='b'||b[1]=='b')&&(a[2]=='b'||b[2]=='b')){           //obb
            	cout<<"yes";
                goto label;
            }
	    }
	    if(a[0]=='o')
		{
		    if((a[1]=='b'||b[1]=='b')&&(a[2]=='b'||b[2]=='b')){           //obb
            	cout<<"yes";
            	goto label;
		   	   }
		}
		else if(a[0]=='b')
		{
         if((a[1]=='b'||b[1]=='b')&&(a[2]=='o'||b[2]=='o')){              //bbo
         	cout<<"yes";
         	goto label;
         	}
         else if((a[1]=='o'||b[1]=='o')&&(a[2]=='b'||b[2]=='b')){         //bob
            cout<<"yes";
            goto label;
        	}
		}

			cout<<"no";                 //If no condition is satisfied then it is not possible to spell bob
			label:;                     //label
			cout<<endl;
	}
	return 0;
}