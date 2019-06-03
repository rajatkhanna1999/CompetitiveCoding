#include<bits/stdc++.h>
using namespace std;

#define FOR0(i,n) for(int i=0;i<n;i++)
#define FORl(i,l,n) for(int i=l;i<n;i++)


#define pi pair<int,int>
#define pb push_back
#define ll long long
#define ld long double
#define vi vector<int>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define mod 1000000007
//Rajat khanna
int main(){
    freopen("let_it_flow.txt", "r", stdin);
    freopen("let_it_flow_output.txt", "w", stdout);
    int T,k;
    cin >> T;
    k=T;
    while(T--){
        int n;
        cin>> n;
        char arr[n][3];
        ll a=1;
        FOR0(i,3){
            FOR0(j,n){
                cin >> arr[j][i];
            }
        }
        cout << "Case #" << k-T << ": ";
        if(n%2==1){
            cout << 0;
            goto label;
        }
        else if(arr[0][0]=='#'){
            cout << 0;
            goto label;
        }
        else if(arr[n-1][2]=='#'){
            cout << 0;
            goto label;
        }
        else{
            FOR0(i,n){
                if(arr[i][1]=='#'){
                    cout << 0;
                    goto label;
                }
            }
            for(int i=1;i<(n-1);i=i+2){
                if(arr[i][0]=='#'&&arr[i+1][2]=='#'){
                    cout << 0;
                    goto label;
                }
                if(arr[i][2]=='#'&&arr[i+1][0]=='#'){
                    cout << 0;
                    goto label;
                }
            }
            for(int i=1;i<(n-1);i++){
                if(arr[i][0]=='#'&&arr[i][2]=='#'){
                    cout << 0;
                    goto label;
                }
            }
        }
        for(int i=1;i<(n-2);i=i+2){
            if(arr[i][0]=='.'&& arr[i][2]=='.' && arr[(i+1)][0]=='.' && arr[(i+1)][2]=='.'){
                a*=2;
                a%=mod;
            }
        }
        cout << a;
        label:;
        cout << endl;
    }
    return 0;
}
