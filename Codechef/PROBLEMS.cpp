#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.14159265358979323
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long int ll;             
typedef unsigned long long int ull;

//Rajat Khanna
//handle : cyber_rajat

/*class Student
{                              //getting some error  working with student
public:                        //will resolve used pair class
  int a,b;
};
bool sortraj(Student q, Student w) //function made to sort previously
{
  if(q.a==w.a)
   	return q.b<w.b;
  		
  	return q.a<w.a;
}*/
bool sortp(pair<int,int>a, pair<int,int>b)  //function to sort
{
  if(a.first==b.first)
   	return a.second<b.second;//if equal on basis of i

  			return a.first<b.first;//on basis of n
}


int main()
{
	int prob,sub;
	cin>>prob>>sub;                              //Inputting
	pair<int,int> arr[33] , arr1[100003];

	for(int i=0;i<prob;i++)
	{
		int count=0;              //maintaining count
		for(int j=0;j<sub;j++)                  //Inputting
           cin>>arr[j].first;
		for(int j=0;j<sub;j++)
			cin>>arr[j].second;
		sort(arr,arr+sub);                  //sorting it
		for(int j=0;j<sub-1;j++)
          if(arr[j].second>arr[j+1].second)count++; //incresing count 
        arr1[i].first=count;
        arr1[i].second=i;
	}

    sort(arr1,arr1+prob,sortp);    //sorting using function
    
    for(int i=0;i<prob;i++)
    	cout<<arr1[i].second+1<<endl;//outputing
	
			return 0;
}
