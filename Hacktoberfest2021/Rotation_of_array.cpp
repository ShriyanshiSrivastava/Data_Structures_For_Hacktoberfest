//Rotate the array to the left (counter-clockwise direction) by D steps, where D is a positive integer.#include <iostream>
#include <iostream>
#include <algorithm>
using namespace std;

void rotateArr(int a[], int d, int n){

        //First reversing d elements from starting index.
        reverse(a, a+d);
        //Then reversing the last n-d elements.
        reverse(a+d, a+n);
        //Finally, reversing the whole array.
        reverse(a, a+n);

    }
int main(){
    int n,d;
    cout<<"Enter size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the number by which you want to rotate the array in counter-clockwise direction: ";
    cin>>d;
    rotateArr(a,d,n);
    cout<<"\nRotated Array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
