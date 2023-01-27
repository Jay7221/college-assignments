
#include <iostream>
using namespace std;
void merge(int array[], int const left, int const mid,
		int const right)
{
    int sz1 = mid - left + 1;
    int sz2 = right - mid;
    int leftarr[sz1 + 1];
    int rightarr[sz2 + 1];
    for(int i = 0; i < sz1; ++i)
    {
        leftarr[i] = array[i + left];
    }
    for(int i = 0; i < sz2; ++i)
    {
        rightarr[i] = array[i + mid + 1];
    }
    leftarr[sz1] = 1e9 + 7;
    rightarr[sz2] = 1e9 + 7;
    int l = 0, r = 0;
    for(int i = left; i <= right; ++i)
    {
        if(leftarr[l] < rightarr[r])
        {
            array[i] = leftarr[l];
            ++l;
        }
        else
        {
            array[i] = rightarr[r];
            ++r;
        }
    }
}
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursively

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}