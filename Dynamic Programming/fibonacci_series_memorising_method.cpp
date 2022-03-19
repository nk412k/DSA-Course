#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
vector<int> dp(N,-1);
int fibonacci(int n){
    if(n==0)
    return 0;
    if(n==1)
    return 0;
    if(n==2)
    return 1;
    if(dp[n]!=-1)
    return dp[n];
    
    dp[n]=fibonacci(n-1)+fibonacci(n-2);
    return dp[n];

}

int main(){
    int n;
    cin>>n;
    cout<<fibonacci(n);
}