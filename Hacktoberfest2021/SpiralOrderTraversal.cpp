#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int ar[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ar[i][j];
        }
    }
    int row_start=0;
    int row_end=n-1;
    int c_start=0;int c_end=m-1;

    while(row_start<=row_end && c_start<=c_end){
     for(int col=c_start;col<=c_end;col++){
         cout<<ar[row_start][col]<<" ";
     }
     row_start++;
     
     for(int row=row_start;row<=row_end;row++){
         cout<<ar[row][c_end]<<" ";}
         c_end--;
     
     for(int col=c_end;col>=c_start;col--){
         cout<<ar[row_end][col]<<" ";}
         row_end--;
   
     for(int  row=row_end;row>=row_start;row--){
         cout<<ar[row][c_start]<<" ";}c_start++;    
    
    }
}