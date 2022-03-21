#include<bits/stdc++.h>
using namespace std;

const int N=1e4+2;
vector<vector<int>> dp(N,vector<int> (N,-1));
int knapsack(int w[],int v[],int n,int W){
    if(W==0)
    return 0;
    if(n==0)
    return 0;
    if(dp[n][W]!=-1)
    return dp[n][W];
    if(w[n]>W)
    dp[n][W]=knapsack(w,v,n-1,W);
    else
    dp[n][W]=max(knapsack(w,v,n-1,W),knapsack(w,v,n,W-w[n])+v[n]);
    return dp[n][W];
}
int main(){
    int n=5,W=11;
    int w[]={3,2,4,5,1};
    int val[]={4,3,5,6,1};
    vector<int> dp(W+1,0);
    for(int i=0;i<=W;i++){
        for(int j=0;j<n;j++){
            if(i-w[j]>=0){
                dp[i]=max(val[j]+dp[i-w[j]],dp[i]);
            }
        }
    }
    cout<<dp[W];
    //cout<<knapsack(w,val,n-1,W);
}