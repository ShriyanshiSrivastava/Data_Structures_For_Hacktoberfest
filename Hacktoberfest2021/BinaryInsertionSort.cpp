#include <iostream>
using namespace std;
int binarySearch(int arr[], int item, int low, int high)
{
	if (high <= low)
		return (item > arr[low]) ? (low + 1) : low;
	int mid = (low + high) / 2;
	if (item == arr[mid])
		return mid + 1;
	if (item > arr[mid])
		return binarySearch(arr, item, mid + 1, high);
	return binarySearch(arr, item, low, mid - 1);
}
void insertionSort(int arr[], int n)
{
	int i, loc, j, k, s;
	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		s= arr[i];
		loc = binarySearch(arr, s, 0, j);
		while (j >= loc)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = s;
	}
}
int main()
{
	int arr[] = { 75, 210, -1, 20, 19, 10, 70, 99, 23 };
	int n = sizeof(arr) / sizeof(arr[0]), i;
	insertionSort(arr, n);
	cout <<"Sorted array: \n";
	for (i = 0; i < n; i++)
		cout <<" "<< arr[i];
    cout<<endl;
	return 0;
}
