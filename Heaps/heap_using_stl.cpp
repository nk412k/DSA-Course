#include<bits/stdc++.h>
using namespace std;


int main(){
    priority_queue<int,vector<int>> pq;
    pq.push(4);
    pq.push(6);
    pq.push(2);
    cout<<pq.top()<<" ";
    pq.pop();
    cout<<pq.top()<<" ";
    cout<<endl;

    priority_queue<int,vector<int>,greater<int>> mpq;
    mpq.push(4);
    mpq.push(6);
    mpq.push(2);
    cout<<mpq.top()<<" ";
    mpq.pop();
    cout<<mpq.top()<<" ";
}