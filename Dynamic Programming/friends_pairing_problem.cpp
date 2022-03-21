#include<bits/stdc++.h>
using namespace std;

const int N=1e4+2;
vector<int> dp(N,-1);
int friends_pairing(int n){
    if(n==0 ||n==1 ||n==2)
    return n;
    if(dp[n]!=-1)
    return dp[n];
    dp[n]=friends_pairing(n-1) + (n-1)*friends_pairing(n-2);
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<friends_pairing(n);
}