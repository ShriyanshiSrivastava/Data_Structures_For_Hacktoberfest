#include <bits/stdc++.h>
using namespace std;

int parent(int i)
{
    return (i - 1) / 2;
}
void insertKey(vector<int> &heapArr, int capacity, int key, int &heapSize)
{

    if (heapSize == capacity)
    {
        cout << "Could not insert key" << endl;
        return;
    }

    heapArr[heapSize] = key;
    heapSize++;

    int i = heapSize - 1;
    while (i != 0 && heapArr[parent(i)] > heapArr[i])
    {
        swap(heapArr[parent(i)], heapArr[i]);
        i = parent(i);
    }
}
void heapify(vector<int> &heapArr, int i, int heapSize)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    int smallest = i;
    if (l < heapSize && heapArr[smallest] > heapArr[l])
        smallest = l;
    if (r < heapSize && heapArr[r] < heapArr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(heapArr[smallest], heapArr[i]);
        heapify(heapArr, smallest, heapSize);
    }
}
int extractMin(vector<int> &heapArr, int &heapSize)
{

    if (heapSize <= 0)
        return INT_MAX;
    int ans = heapArr[0];
    heapArr[0] = heapArr[heapSize - 1];
    heapSize--;
    heapify(heapArr, 0, heapSize);
    return ans;
}
void decreaseKey(vector<int> &heapArr, int keyIndex, int newVal)
{
    heapArr[keyIndex] = newVal;
    int i = keyIndex;
    while (i != 0 && heapArr[parent(i)] > heapArr[i])
    {
        swap(heapArr[parent(i)], heapArr[i]);
        i = parent(i);
    }
}
void deleteKey(vector<int> &heapArr, int &heapSize, int keyIndex)
{
    decreaseKey(heapArr, keyIndex, INT_MIN);
    extractMin(heapArr, heapSize);
}
int main()
{
    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;
    cout << "Enter array elements" << endl;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];

    vector<int> heapArr(n, 0);
    int heapSize = 0;
    for (int i = 0; i < n; i++)
        insertKey(heapArr, n, input[i], heapSize);

    for (int i = 0; i < n; i++)
        cout << heapArr[i] << " ";
    cout << "\nmin element " << extractMin(heapArr, heapSize) << endl;
    cout << "Enter key to delete" << endl;
    int keyIndex;
    cin >> keyIndex;
    deleteKey(heapArr, heapSize, keyIndex);
    cout << "heap array after deleting key" << endl;
    for (int i = 0; i < heapSize; i++)
        cout << heapArr[i] << " ";
}

/* 
TC:insert, delete,extract min : O(log n) 
*/