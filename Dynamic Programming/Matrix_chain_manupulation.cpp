#include<bits/stdc++.h>
using namespace std;

const int N=1e3+2,mod=1e7+2;
vector<vector<int>> dp(N,vector<int> (N,-1));
int matrix_manupulation(vector<int> v,int i,int j){
    if(i==j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    dp[i][j]=mod;
    for(int k=i;k<j;k++){
        dp[i][j]=min(dp[i][j],matrix_manupulation(v,i,k)+matrix_manupulation(v,k+1,j)+v[i-1]*v[k]*v[j]);
    }
    return dp[i][j];
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<matrix_manupulation(v,1,n-1);
}