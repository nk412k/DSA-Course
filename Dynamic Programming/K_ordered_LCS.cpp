#include<bits/stdc++.h>
using namespace std;

int n1,n2,k;
vector<int> a;
vector<int> b;
int dp[200][200][10];
int LCS(int i,int j,int k){
    int c1=0,c2=0,c3=0;
    if(i==n1 || j==n2)
    return 0;
    if(dp[i][j][k]!=-1)
    return dp[i][j][k];
    if(a[i]==b[j])
    c1=1+LCS(i+1,j+1,k);
    if(k>0)
    c2=1+LCS(i,j,k-1);
    c3=max(LCS(i+1,j,k),LCS(i,j+1,k));
    return dp[i][j][k]=max({c1,c2,c3});
}

int main(){
    memset(dp,-1,sizeof(dp));    
    cin>>n1>>n2>>k;
    a=vector<int> (n1);
    b=vector<int> (n2);
    for(int i=0;i<n1;i++){
        cin>>a[i];
    }
    for(int i=0;i<n2;i++){
        cin>>b[i];
    }    
    cout<<LCS(0,0,k);
}