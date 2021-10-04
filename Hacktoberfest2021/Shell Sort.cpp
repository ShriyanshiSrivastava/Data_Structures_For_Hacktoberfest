#include <iostream>
using namespace std;

void shellSort(int A[], int n) {
  for (int gap = n / 2; gap >= 1; gap /= 2) {
    for (int j = gap; j < n; j++) {
      int temp = A[j];
      int i = j - gap;
      while (i >= 0 && A[i] > temp) {
        A[i + gap] = A[i];
        i = i - gap;
      }
      A[i + gap] = temp;
    }
  }
}


int main()	{
  int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
  int n = sizeof(A) / sizeof(A[0]);
  
  for (auto i :  A)
    cout << i << " ";
  puts("");

  shellSort(A, n);

  for (auto i :  A)
    cout << i << " ";
  puts("");

  return 0;
}
