#include<bits/stdc++.h>
using namespace std;

const int N=1e4+2,mod=1e5+2;
vector<vector<int>> dp(N,vector<int> (N,-1));
int optimal_game(vector<int> a,int i,int j){
    if(i==j)
    return a[i];
    if(i>j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ch1=a[i]+min(optimal_game(a,i+2,j),optimal_game(a,i+1,j-1));
    int ch2=a[j]+min(optimal_game(a,i+1,j-1),optimal_game(a,i,j-2));
    dp[i][j]= max(ch1,ch2);
    return dp[i][j];
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<optimal_game(a,0,n-1);
}