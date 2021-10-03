#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<string.h>
#include<strings.h>
#include<vector>
using namespace std;
int binarySearch(int a[],int l,int r,int x){
    if(r>=l){
        int mid=l+(r-l)/2;

        if(a[mid]==x){
            return mid;
        }
        if(a[mid]>x){
            return binarySearch(a,mid+1,r,x);
        }
        return binarySearch(a,l,mid-1,x);
    }
    return -1;
}
int main(){
    int n;//Number of elements in the array
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;//The number you want to find
    cin>>x;
    int result = binarySearch(a,0,n - 1, x);

    (result == -1) ? cout << "Element is not present in array": cout << "Element is present at index " << result;
    return 0;
}

