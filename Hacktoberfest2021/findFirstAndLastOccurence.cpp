// C++ program to find first and last occurrence of
// an elements in given sorted array
#include <bits/stdc++.h>
using namespace std;

// if x is present in arr[] then returns the
// index of first occurrence
int first(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        // If arr[mid] is same as x, we
        // update res and move to the left half.
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}
 
// If x is present in arr[] then returns
// the index of last occurrence
int last(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        // If arr[mid] is same as x, we
        // update res and move to the right half.
        else
        {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}
int main()
{
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(int);
    int x = 8;
    cout <<first(arr, x, n)<<" "<< last(arr, x, n);
    return 0;
}