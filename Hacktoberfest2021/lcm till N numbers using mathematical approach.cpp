 // For finding LCM(a,b)
 //we use a function gcd(a,b) which will return HCF of (a,b).
 //Time complexity : O(nlog n)
//input =1,2,3,4,5,6
//output =60
We know that LCM(a,b)= (a*b)/HCF(a,b)
#include <bits/stdc++.h>
using namespace std;


//User function template for C++

class Solution {
 public:   //access modifier public allows
      long long gcd(long long a,long long b)   //member functions()
      {
           if (b == 0)
        return a;
        return gcd(b, a % b); //this calculates the hcf of two numbers
      }

    long long getSmallestDivNum(long long n){
       int ans=1;
       for (long long i = 1; i <= n; i++)
            //lcm=(a*b)/gcd(a,b)
        ans = (ans * i)/(gcd(ans, i)); //here i will increament till n and compute the lcm of 2 numbers together and store it in ans
        return ans;
    }
     };




// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob; //here ob is the object name of class solution
        cout<< ob.getSmallestDivNum(n)<<endl; //accessing member function
    }
    return 0;
}

