#include<bits/stdc++.h>
using namespace std;

#define FOR0(i,n) for(int i=0;i<n;i++)
#define FORl(i,l,n) for(int i=l;i<n;i++)
#define pi pair<int,int>
#define pb push_back
#define ll long long
#define ld long double
#define ff first
#define ss second
#define vi vector<int>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

//Rajat
int main(){
    freopen("ethan_traverses_a_tree.txt", "r", stdin);
    freopen("ethan_traverses_a_tree_output.txt", "w", stdout);
    ll T,m;
    cin >> T;
    m=T;
    while(T--){
        int n,k;
        cin>>n;
        cin>>k;
        int a[n+1];
        int b[n+1];
        FORl(i,1,n+1){
            cin>>a[i];
            cin>>b[i];
        }
        stack <int> st;
        vi preorder;
        st.push(1);
        do{
            int last = st.top();
            st.pop();
            preorder.pb(last);
            if (b[last]) st.push(b[last]);
            if (a[last]) st.push(a[last]);
        }
       while(!st.empty());

        int ipre[n+1];
        FOR0(i,n){
            ipre[preorder[i]] = i;
        }
        stack <int> st1;
        stack <int> st2;
        vi postorder;
        st1.push(1);
        do{
            int last = st1.top();
            st1.pop();
            st2.push(last);
            if (a[last]) st1.push(a[last]);
            if (b[last]) st1.push(b[last]);
        }
        while(!st1.empty());
       //postOrder and preOrder
        while(!st2.empty()){
            int last = st2.top();
            st2.pop();
            postorder.pb(last);
        }
        int ipost[n+1];
        FOR0(i,n){
            ipost[postorder[i]] = i;
        }

        int labels[n+1];
        //setting the array
        memset(labels,0,sizeof(labels));
        int curr =1;
        FOR0(i,n){
            if (labels[preorder[i]]!=0) 
             continue;
            int initial = preorder[i];
            if (labels[preorder[i]]==labels[postorder[i]] && labels[preorder[i]]==0){
                labels[preorder[i]]=curr;
                labels[postorder[i]]=curr;
                int next = ipre[postorder[i]];

                while(postorder[next]!=initial){
                    labels[postorder[next]]=curr;
                    next = ipre[postorder[next]];
                }
                curr++;
            }
        }
       
        cout << "Case #" << m-T << ":";
        if (curr-1<k) 
      cout<<" Impossible"<<endl;
        else{
            FORl(i,1,n+1){
                if (labels[i]>k) 
                 labels[i]=1;
            }
            FORl(i,1,n+1){
                cout<<" "<<labels[i];
            }
            cout<<endl;
        }

    }   
}
