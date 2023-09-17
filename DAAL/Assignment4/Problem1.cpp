#include <iostream>
#include<vector>
using namespace std;

int findPeak(vector<int> &arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }

    if ((high == low + 1) && arr[low] >= arr[high]) {
        return arr[low];
    }

    if ((high == low + 1) && arr[low] < arr[high]) {
        return arr[high];
    }

    int mid = (low + high) / 2;

    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
        return arr[mid];
    }

    if (arr[mid] > arr[mid + 1] && arr[mid - 1] > arr[mid]) {
        return findPeak(arr, low, mid - 1);
    } else {
        return findPeak(arr, mid + 1, high);
    }
}

int main() {
    int n;
    cerr << "Enter the size of array: " << '\n';
    cin >> n;
    vector<int> arr(n);
    cerr << "Enter the elements of the array : " << '\n';
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    cerr << "The maximum element in the array is: ";
    cout << findPeak(arr, 0, n - 1) << endl;

    return 0;
}
