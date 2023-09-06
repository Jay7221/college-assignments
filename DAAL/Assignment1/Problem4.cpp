#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<string> &arr, int l, int r, string tar){
    while(l <= r){
        while((l <= r) && (arr[l] == "")){
            ++l;
        }
        while((l <= r) && (arr[r] == "")){
            --r;
        }
        if(l > r){
            break;
        }
        int mid = l + (r - l) / 2;
        while(arr[mid] == "" && (l <= mid)){
            --mid;
        }

        if(arr[mid] == tar){
            return mid;
        }else if(arr[mid] < tar){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return -1;
}
int main(){
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;
    cout << "Enter the elements of array : " << endl;
    vector<string> arr(n);
    getline(cin, arr[0]);
    fflush(stdin);
    for(int i = 0; i < n; ++i){
        getline(cin, arr[i]);
    }
    string tar;
    cout << "Enter the target element : " << endl;
    getline(cin, tar);
    cout << binarySearch(arr, 0, n - 1, tar) << '\n';
    return 0;
}
