#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long int T;
    cin>>T;
 
    while(T>0)
    {
        long long int n,s,y,v[11],d[11],c[11];
         double p[11];
         double t=0,t1;
        cin>>n>>s>>y;
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n;i++)
            cin>>d[i];
        for(int i=0;i<n;i++)
            cin>>p[i];
        for(int i=0;i<n;i++)
            cin>>c[i];
        double avg=(double)(y)/s;
        for(int i=0;i<n;i++)
        {
            t1=0;
            if(d[i]==1 && p[i]>0 &&(p[i]-c[i])>=0){
                t+=avg;
                t1+=avg;
            }
            else if(d[i]==0 && p[i]<0 && (p[i]+c[i])<=0){
                t+=avg;
                t1+=avg;
            }
            else if(d[i]==1 && p[i]>0 &&(p[i]-c[i])<0){
                t+=(double)(c[i]-p[i])/v[i]+avg;
                t1+=(double)(c[i]-p[i])/v[i]+avg;
            }
            else if(d[i]==0 && p[i]<0 &&(p[i]+c[i])>0){
                t+=(double)(c[i]+p[i])/v[i]+avg;
                t1+=(double)(c[i]+p[i])/v[i]+avg;
            }
            else if(d[i]==1 && p[i]<=0)
            {
                double a=(double)(-p[i])/v[i];
                if(a<=avg){
                    t+=(double)(-p[i]+c[i])/v[i]+avg;
                    t1+=(double)(-p[i]+c[i])/v[i]+avg;
                }
                else{
                    t+=avg;
                    t1+=avg;
                }
            }
            else if(d[i]==0 && p[i]>=0)
            {
                double a=(double)(p[i])/v[i];
                if(a<=avg){
                    t+=(double)(p[i]+c[i])/v[i]+avg;
                    t1+=(double)(p[i]+c[i])/v[i]+avg;
                }
                else{
                    t+=avg;
                    t1+=avg;
                }
            }
            for(int k=i+1;k<n;k++)
            {
                double as=(double)(v[k])*t1;
                if(p[k]>=0 && d[k]==1){
                    p[k]=p[k]+as;
                }
                else if(p[k]>=0 && d[k]==0){
                    double as=(double)(v[k])*t1;
                    p[k]=p[k]-as;
                }
                else if(p[k]<0 && d[k]==0){
                    double as=(double)(v[k])*t1;
                    p[k]=p[k]-as;
                }
                else if(p[k]<0 && d[k]==1){
                    double as=(double)(v[k])*t1;
                    p[k]=p[k]+as;
                }
            }
        }
        printf("%lf\n",t);
        T--;
    }
    return 0;
}
 