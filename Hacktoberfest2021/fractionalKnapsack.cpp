#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2){
    double r1 = (double) p1.first/p1.second;
    double r2 = (double) p2.first/p2.second;
    return r1>r2;
}
int main(){
    int n,w,a,b;
    cin>>n;
    vector<pair<int,int>> v;
    // first - value & second - weight
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),compare);
    int W;
    cin>>W;
    double res = 0.0;
    for(int i=0;i<n;i++){
        if(v[i].second<=W){
            res+=v[i].first;
            W = W-v[i].second;
        }else{
            res += v[i].first * ((double)W/v[i].second);
            cout<<res<<endl;
            break;
        }
    }
}