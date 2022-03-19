#include<bits/stdc++.h>
using namespace std;

const int N=1e3+7;
vector<vector<int>> dp(N,vector<int> (N,-1));
int coin_change(vector<int> a,int n,int c){
    if(c==0)
    return 1;
    if(c<0)
    return 0;
    if(n<=0)
    return 0;
    if(dp[n][c]!=-1)
    return dp[n][c];

    dp[n][c]=coin_change(a,n-1,c)+coin_change(a,n,c-a[n-1]);
    return dp[n][c];
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c;
    cin>>c;
    cout<<coin_change(a,n,c);
}