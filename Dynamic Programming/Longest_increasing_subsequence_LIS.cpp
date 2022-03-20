#include<bits/stdc++.h>
using namespace std;

const int N=1e3+2;
vector<int> dp(N,-1); 
int Lis(vector<int> a,int n){    
    if(dp[n]!=-1)
    return dp[n];
    dp[n]=1;
    for(int i=0;i<n;i++){
        if(a[i]<a[n])
        dp[n]=max(dp[n],1+Lis(a,i));
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
    cout<<Lis(a,n-1);
}