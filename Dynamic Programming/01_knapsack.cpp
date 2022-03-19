#include<bits/stdc++.h>
using namespace std;

const int N=1e4+2,mod=1e4+2;
vector<vector<int>> dp(N,vector<int> (N,-1));
int knapshack(vector<int> w,vector<int> v,int n,int W){
    if(W==0)
    return 0;
    if(n==0)
    return 0;
    if(dp[n][W]!=-1)
    return dp[n][W];
    if(w[n-1]>W)
    dp[n][W]=knapshack(w,v,n-1,W);
    else
    dp[n][W]=max(knapshack(w,v,n-1,W),knapshack(w,v,n-1,W-w[n-1])+v[n-1]);
    return dp[n][W];
}
int main(){
    int n;
    cin>>n;
    vector<int> w(n);
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int W;
    cin>>W;
    cout<<knapshack(w,v,n,W);
}