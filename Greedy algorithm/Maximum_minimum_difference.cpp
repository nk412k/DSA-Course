#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int mx=0,min=0;
    for(int i=0;i<n/2;i++){
        mx+=a[i+n/2]-a[i];        
    }
    for(int i=0;i<n-1;i+=2){
        min+=a[i+1]-a[i];
    }
    cout<<mx<<" "<<min;
}