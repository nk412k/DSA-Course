#include<bits/stdc++.h>
using namespace std;

const int N=1e3+2;
int main(){
    int a[N];
    for(int i=0;i<N;i++){
        a[i]=i;
    }
    for(int i=2;i<N;i++){
        if(a[i]==i){
            for(int j=2*i;j<N;j+=i){
                a[j]*=(i-1);
                a[j]/=i;
            }
            a[i]=i-1;
        }
    }
    for(int i=2;i<=10;i++){
        cout<<a[i]<<" ";
    }
}