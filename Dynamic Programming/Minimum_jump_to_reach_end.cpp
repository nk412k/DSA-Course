#include<bits/stdc++.h>
using namespace std;

const int N=1e4+2,mod=1e4+2;
vector<int> dp(N,-1);
int min_jump(vector<int> a,int n){
    if(n==0)
    return 0;
    if(dp[n]!=-1)
    return dp[n];
    dp[n]=mod;
    for(int i=0;i<n;i++){
        if(n<=i+a[i])
        dp[n]=min(dp[n],1+min_jump(a,i));
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> dp(n+1,0);
    int mod=1e4+2;
    for(int i=1;i<n;i++){
        dp[i]=mod;
        for(int j=0;j<i;j++){
            if(i<=j+a[j]){
                dp[i]=min(dp[i],1+dp[j]);
            }
        }
    }
    cout<<dp[n-1];
    // cout<<min_jump(a,n-1);
}