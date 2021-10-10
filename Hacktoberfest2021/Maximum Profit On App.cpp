/* You have made a smartphone app and want to set its subscription price such that the profit earned is maximised. There are certain users who will subscribe to your app only if their budget is greater than or equal to your price.
You will be provided with a list of size N having budgets of subscribers and you need to return the maximum profit that you can earn.
Lets say you decide that price of your app is Rs. x and there are N number of subscribers. So maximum profit you can earn is :
 m * x
where m is total number of subscribers whose budget is greater than or equal to x.
Input format :
Line 1 : N (No. of subscribers)
Line 2 : Budget of subscribers (separated by space)
Output Format :
 Maximum profit
Constraints :
1 <= N <= 10^6
1 <=budget[i]<=9999
Sample Input 1 :
4
30 20 53 14
Sample Output 1 :
60
Sample Output 1 Explanation :
Price of your app should be Rs. 20 or Rs. 30. For both prices, you can get the profit Rs. 60.
Sample Input 2 :
5
34 78 90 15 67
Sample Output 2 :
201
Sample Output 2 Explanation :
Price of your app should be Rs. 67. You can get the profit Rs. 201 (i.e. 3 * 67).
*/
//Code

#include<bits/stdc++.h>
int maximumProfit(int budget[], int n) {
    // Write your code here
    //First sort the array using stl function
     sort(budget , budget+n);

    int temp[n];

    for(int i=0;i<n;i++)
    {
        temp[i]=budget[i]*(n-i);   //adding profit in temporary array
    }
     sort(temp,temp +n);      //Sorting Temporary array

    return temp[n-1];      // Returning maximum Profit

}
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];      // input elements

    cout << maximumProfit(input, n) << endl;  // Calling maximumProfit function and printing maximu profit

}
