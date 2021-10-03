#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<string.h>
#include<strings.h>
#include<vector>


using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void rev(int a[],int n){
    for(int i=0;i<n/2;i++){
        swap(a[i],a[n-1-i]);
    }
}
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    rev(a,n);
    printArray(a,n);
    return 0;
}

