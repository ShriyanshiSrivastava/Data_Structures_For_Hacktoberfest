#include <iostream>
using namespace std;

void copy(int input[],int arr[],int si,int ei){
    for(int i=si,j=0;i<ei;i++,j++){
        arr[j]=input[i];
    }
}

void merge(int arr[],int si,int ei,int mid){
    int a1=mid-si+1,a2=ei-mid,a=ei-si+1;
    int arr1[a1],arr2[a2],af[a];
    copy(arr,arr1,si,mid);
    copy(arr,arr2,mid+1,ei);
    int i=0,j=0,k=0;
    while(i<a){
        while(j<a1&&k<a2){
            if(arr1[j]<arr2[k]){
                af[i]=arr1[j];
                i++;j++;
            }else{
                af[i]=arr2[k];i++;k++;
            }
        }
        while(j<a1&&k>=a2){
            af[i]=arr1[j];i++;j++;
        }
        while(k<a2&&j>=a1){
            af[i]=arr2[k];i++;k++;
        }
    }
    for(int i=0,j=si;i<a;j<=ei;i++,j++){
        arr[j]=af[i];
    }
}

void mergeSort(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid=(si+ei)/2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);
    merge(arr,si,ei,mid);
}

int main()
{
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    mergeSort(input, 0,n-1);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

}