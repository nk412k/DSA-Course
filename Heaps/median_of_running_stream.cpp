#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>> h1;
priority_queue<int,vector<int>,greater<int>> h2;

void insertion(int num){
    if(h1.size()==h2.size()){
        if(h1.size()==0 || num<h1.top()){
            h1.push(num);
        }
        else
        h2.push(num);
    }
    else if(h1.size()>h2.size()){
        if(num>=h1.top()){
            h2.push(num);
        }
        else{            
            int temp=h1.top();
            h1.pop();
            h2.push(temp);
            h1.push(num);
        }
    }
    else{
        if(num<=h2.top()){
            h1.push(num);
        }
        else{
            int temp=h2.top();
            h2.pop();
            h1.push(temp);
            h2.push(num);
        }
    }
}

double find_median(){
    
    if(h1.size()==h2.size()){
        return (h1.top()+h2.top())/2.0;
    }
    else if(h1.size()>h2.size()){
        return h1.top();
    }
    else
    return h2.top();
}

int main(){
    int a[]={10,15,21,30,18,19};
    
    for(int i=0;i<6;i++){
        insertion(a[i]);
        cout<<find_median()<<" ";
    }
}