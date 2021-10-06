#include<bits/stdc++.h> //kadane's algorithm is to look for all positive contiguous segments of the array.
                         //this prints largest contiguous array sum
#include <climits>
 using namespace std;
int main()
{
    int n,i;
     cin>>n;
      int arr[n];
      for(i=0;i<n;i++)
      {
          cin>>arr[i];
      }
      int currsum=0;
      int maxsum=INT_MIN;
      for(i=0;i<n;i++)
      {
          currsum+=arr[i];
          if(currsum<0) //if current sum is negative 0 is assigned to currsum
            currsum=0;
            maxsum=max(maxsum,currsum); //compare each time the sum with maxsum
      }
      cout<<maxsum;



      return 0;
}
