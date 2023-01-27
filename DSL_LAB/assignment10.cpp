#include<iostream>
using namespace std;
int linearSearch(int arr[], int n, int tar)
{
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] == tar)
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[], int n, int tar)
{
    int l = 0, r = n - 1;
    while(l < r)
    {
        int m = (l + r) / 2;
        if(arr[m] < tar)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    if(arr[l] == tar)
    {
        return l;
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter number elements in array : ";
    cin >> n;
    cout << "Enter the elements of the array : ";
    int arr[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << "Enter target element : ";
    int tar;
    cin >> tar;
    cout << "Linear Search : " << linearSearch(arr, n, tar) << endl;
    cout << "Binary Search : " << binarySearch(arr, n, tar) << endl;
}