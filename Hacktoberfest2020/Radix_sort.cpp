// Radix Sort 

#include <bits/stdc++.h>
using namespace std;

// Function to get the largest element from an array
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}


void radixsort(int array[], int size) 
{
  int max = getMax(array, size);
  for (int place = 1; max / place > 0; place *= 10)
  countingSort(array, size, place);
}


// Print an array
void printArray(int array[], int size) {
  int i;
  cout<<"\nArray is:: ";
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Driver code
int main() {
  int n,x;
  cout<<"\nenter number of elements:: ";
  cin>>n;
  int arr[n];
  cout<<"Enter elements:: \n";
  for(int i=0;i<n;i++)
  {
    cin>>x;
    arr[i]=x;
  }
  radixsort(arr, n);
  printArray(arr, n);
}