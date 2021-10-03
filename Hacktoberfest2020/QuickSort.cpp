#include<iostream>
using namespace std;

int partition(int input[],int si,int ei){
    int p=si;
    for(int i=si+1;i<=ei;i++){
        if(input[i]<input[si]){
            p++;
        }
    }
    int temp=input[p];
    input[p]=input[si];
    input[si]=temp;
    int i=si,j=ei;
    while(i<p&&j>p){
        if(input[i]<input[p]){
            i++;
        }else if(input[j]>input[p]){
            j--;
        }else if(input[i]>=input[p]&&input[j]<input[p]){
            int temp1=input[i];
            input[i]=input[j];
            input[j]=temp1;
            i++;
            j--;
        }
    }
    return p;
}

void qs(int input[],int si,int ei){
    if(si>=ei){
        return;
    }
    int p=partition(input,si,ei);
    qs(input,si,p-1);
    qs(input,p+1,ei);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    qs(input, 0,n-1);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

}
