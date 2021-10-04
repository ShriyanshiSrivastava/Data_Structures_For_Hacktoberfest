//Rotate the array to the left (counter-clockwise direction) by D steps, where D is a positive integer.#include <iostream>
#include <iostream>
using namespace std;

int equilibriumPoint(long long a[], int n) {
        int sum = 0;
        int leftsum = 0;
        for (int i = 0; i < n; ++i)
            sum += a[i];

        for (int i = 0; i < n; ++i)
        {
            sum -= a[i];

            if (leftsum == sum)
                return i+1;

            leftsum += a[i];
        }
        return -1;
    }

int main(){
    long long int n,d;
    cout<<"Enter size of array: ";
    cin>>n;
    long long int a[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"\nIndex of Equilibrium Point: "<<equilibriumPoint(a,n);


    return 0;
}
