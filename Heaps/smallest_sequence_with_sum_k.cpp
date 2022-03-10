#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[]={1,1,3,2,8};
    int n=5;
    int x=12;
    priority_queue<int,vector<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(a[i]);
    }
    int sum=0;
    int c=0;
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
        c++;
        if(sum>=x){
            break;
        }
    }
    cout<<c;
}