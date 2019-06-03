#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("tourist.txt", "r", stdin);
    freopen("tourist_solution1.txt", "w", stdout);
    int t,j,T,N,K;
    long long int V;

 cin>>T;
 t=T;
 j=1;
 while(t--){
   cin>>N>>K>>V;
   string a[51],ans[51];
   for(int i=1;i<=N;i++)
   {
   	cin>>a[i];
   	ans[i]="  ";
   }
   long long int prod = K*(V-1);
   long long int rem = prod%N;
   long long int remm=rem;
   int count=0;
   while(count!=K)
   {
      ans[remm+1]=a[remm+1];
      count++;
      remm++;
      remm=remm%N;
   }
   cout<<"Case #"<<j<<": "; 
   for(int i=1;i<=N;i++)
   {
        if(ans[i]!="  ")
        {
        	cout<<ans[i]<<" ";
        }
   }

   cout<<endl;
   j++;
 }

}
