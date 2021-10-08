#include<bits/stdc++.h>
using namespace std;
int minSteps1(int n){
    if(n<=1){
        return 0;
    }
    int x = minSteps1(n-1);
    int y = INT_MAX;
    int z = INT_MAX;
    if(n%2==0){
        y = minSteps1(n/2);
    }
    if(n%3==0){
        z = minSteps1(n/3);
    }
    return min(x,min(y,z))+1;
}
int minSteps2help(int n,int *dp){
    if(n<=1){
        return dp[n] = n;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int x = INT_MAX;
    int y = INT_MAX;
    int z = INT_MAX;
    if(n%3==0){
        z = minSteps2help(n/3,dp);
    }
    if(n%2==0){
        y = minSteps2help(n/2,dp);
    }
    int x = minSteps2help(n-1,dp);
    return dp[n] = min(x,min(y,z))+1;
}
int minSteps2(int n){
    int * dp = new int[n+1]{0};
    return minSteps2help(n,dp);
}
int minSteps3(int n){
    int * ans = new int[n+1];
    ans[0] =0;
    ans[1] =0;
    for(int i=2;i<=n;i++){
        int x,y=INT_MAX,z=INT_MAX;
        x = ans[i-1];
        if(i%2==0){
            y = ans[i/2];
        }
        if(i%3==0){
            z = ans[i/3];
        }
        ans[i] = min(x,min(y,z))+1;
    }
    return ans[n];
}
int main(){
    int n;
    cin>>n;
    cout<<minSteps1(n)<<endl;
    cout<<minSteps3(n);
}