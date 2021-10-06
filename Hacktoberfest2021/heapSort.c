// Heap Sort in C

#include<stdio.h>
void swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1; // l - left
    int r = 2*i + 2; // r - right
    // left node is greater than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    // right node is greater than largest
    if (r < n && arr[r] > arr[largest])
        largest = r;
    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}
// main function for heap sort
void heapSort(int arr[], int n)
{
    // Building the  heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

// to print array of size n

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        printf("%d\t",arr[i]);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted Array\n");
    printArray(arr, n);
}
