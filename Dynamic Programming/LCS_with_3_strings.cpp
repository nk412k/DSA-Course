#include<bits/stdc++.h>
using namespace std;

int dp[200][200][200];
int LCS(string s1,string s2,string s3,int i,int j,int k){
    if(i==0 || j==0 || k==0)
    return 0;
    if(dp[i][j][k]!=-1)
    return dp[i][j][k];
    if((s1[i-1]==s2[j-1]) && (s2[j-1]==s3[k-1]))
    return dp[i][j][k]= 1 + LCS(s1,s2,s3,i-1,j-1,k-1);
    
    dp[i][j][k]=max({LCS(s1,s2,s3,i-1,j,k),LCS(s1,s2,s3,i,j-1,k),LCS(s1,s2,s3,i,j,k-1)});
    return dp[i][j][k];
}

int main(){
    memset(dp,-1,sizeof(dp));
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    cout<<LCS(s1,s2,s3,s1.size(),s2.size(),s3.size());
}