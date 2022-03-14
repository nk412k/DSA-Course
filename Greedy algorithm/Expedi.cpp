#include<bits/stdc++.h>
using namespace std;

int main(){
    int p,d,n;
    cin>>n;
    vector<pair<int,int>> stops(n);
    for(int i=0;i<n;i++){        
        cin>>stops[i].first>>stops[i].second;
        
    }
    for(int i=0;i<n;i++){
        stops[i].first=d-stops[i].first;
    }
    cin>>d>>p;
    sort(stops.begin(),stops.end());
    priority_queue<int,vector<int>> mxheap;    
    int c=0;
    bool flag=false;
    for(int i=0;i<n;i++){
        if(p>=d)
        break;
        if(p>=stops[i].first){
            mxheap.push(stops[i].second);
        }
        else{
            if(mxheap.empty()){
                flag=true;
                break;
            }
            else{
                c++;
                p+=mxheap.top();
                mxheap.pop();
            }
        }
    }
    if(flag){
        cout<<"cannot reach the destination";
    }
    while(!mxheap.empty() && p<d){        
        c++;
        p+=mxheap.top();
        mxheap.pop();
    }
    if(p>=d)
    cout<<c;
    else
    cout<<"cannot reach the destination";
}