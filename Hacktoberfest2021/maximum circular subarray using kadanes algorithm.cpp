
//Case 1: The elements that contribute to the maximum sum are arranged such that no wrapping is there.
//Examples: {-10, 2, -1, 5}, {-2, 4, -1, 4, -1}. In this case, Kadane’s algorithm will produce the result.
// The elements which contribute to the maximum sum are arranged such that wrapping is there. Examples: {10, -12, 11}, {12, -5, 4, -8, 11}.
//In this case, we change wrapping to non-wrapping. Let us see how. Wrapping of contributing elements implies non-wrapping of non-contributing elements
#include<bits/stdc++.h> //maximum circular subarray using kadane's algorithm
#include<climits>         //case:2 =input=(4,-4,6,-6,10,-11,12) output =22(maximum)
using namespace std;      //but continuous we get 11 as maximum and using kadane's we get 12
                            //so here if we remove -11(largest negative) we get maximum sum so contributing elements are wraping

int kadane(int arr[],int n)
{
    int currsum=0;
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        currsum+=arr[i];
        if(currsum<0)
           currsum=0;
        maxsum=max(maxsum,currsum);

    }
    return maxsum;
}
 int main()
 {
   int wrapsum,n;
   int nonwrapsum;
   int totalsum=0;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++) //input in array
   {
       cin>>arr[i];
   }

   nonwrapsum=kadane(arr,n);// in case we get continuous subarray as maximum then the sum is stored in nonwrapsum using kadane
   for(int i=0;i<n;i++)
   {
       totalsum+=arr[i]; //To find out the sum of non-contributions, invert the sign of each element and then run Kadane’s algorithm.
       arr[i]=-arr[i];
    }

//sum of non-contributing elements and subtract this sum from the total sum}
   wrapsum=totalsum+kadane(arr,n);  //Our array is like a ring and we have to eliminate the maximum continuous negative that implies maximum
                                      // continuous positive in the inverted arrays.
   // Finally, we compare the sum obtained in both cases and return the maximum of the two sums.
   cout<<max(wrapsum,nonwrapsum);
 }
