#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int search(int arr[], int n, int target){
    int l = 0, r = n - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[l] <= arr[r]){
            // no roatation, arr[l ... r] is sorted
            if(arr[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        else{
            if(arr[l] <= target){
                // target lies in the first ascending array
                if(arr[mid] < target){
                    if(arr[mid] >= arr[l]){
                        l = mid + 1;
                    }
                    else{
                        r = mid - 1;
                    }
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                // target lies in the second ascending array
                if(arr[mid] > target){
                    if(arr[mid] < arr[l]){
                        r = mid - 1;
                    }
                    else{
                        l = mid + 1;
                    }
                }
                else{
                    l = mid + 1;
                }
            }
        }
    }
    // Target element not found
    return -1;
}
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the element of the array: ";
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    int target;
    cout << "Enter the target element to search: ";
    cin >> target;
    cout << "Computing the index of the target element..." << endl;
    int index = search(arr, n, target);
    cout << "The index of the target element is : " << index << endl;
    return 0;
}
