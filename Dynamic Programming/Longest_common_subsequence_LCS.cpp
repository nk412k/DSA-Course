#include<bits/stdc++.h>
using namespace std;

const int N=1e3+2;
vector<vector<int>> dp(N,vector<int> (N,-1));
int Lcs(string s1,string s2,int n,int m){
    if(n<0 || m<0)
    return 0;
    if(dp[n][m]!=-1)
    return dp[n][m];
    if(s1[n]==s2[m])
    dp[n][m]=1+Lcs(s1,s2,n-1,m-1);
    else
    dp[n][m]=max(Lcs(s1,s2,n-1,m),Lcs(s1,s2,n,m-1));
    return dp[n][m];
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    cout<<Lcs(s1,s2,n-1,m-1);
}