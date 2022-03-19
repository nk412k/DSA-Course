#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7,mod=1e5+1;
vector<int> dp(N,mod);
int min_num_of_square(int n){
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    if(dp[n]!=mod)
    return dp[n];
    for(int i=1;i*i<=n;i++){
        dp[n]=min(dp[n],1+min_num_of_square(n-i*i));
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<min_num_of_square(n);
}