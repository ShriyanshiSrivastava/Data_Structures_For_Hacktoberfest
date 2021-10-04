//In this code we are finding out the maximum sum fo rall subarray's of size K
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //INPUT:-
    int arr[] = {100, 200, 300, 400};
    int n =sizeof(arr)/sizeof(arr[0]);
    int k=2;
    //OUTPUT:-
    //700={300,400};    **We can see here that the maximum sum possible outof all subarrays present in the array of size k is 700

     if (n < k)  //we are checking for invalid condition
    {
       cout << "Invalid";
    
    }

   
    int i = 0, j = 0;
    int sum = 0, mx = INT_MIN;
       
    while(j<n){             //Here we have made two points i and j and we are traversing them in our array
                            // by doing this we are making a window of size K
         sum += arr[j];     //we are storing the sum of all elements from where are j point is passing
           
           if(j-i+1 < k){   // here if our window size is less than k then we will move our j point forward
               j++;
           }
           
           else if(j-i+1 == k){  // and hence as soon we will get our window size equal to our k size our window is created now and we just need to proceed it forward.
               mx = max(mx, sum);
               sum -= arr[i];   // we are deleting the element from our sum as soon we move forward or slide our window.
               i++;           // by doing i++ and j++ we are sliding our window;
               j++;
           }
       }

    cout<<mx<<" ";    //    printing of output.

}
