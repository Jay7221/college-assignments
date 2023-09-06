#include<iostream>
using namespace std;
const int MAX = 1000;
int fib[MAX];
int getFib(int n)
{
    if(fib[n] != 0)
    {
        return fib[n];
    }
    if(n < 2)
    {
        return fib[n] = 1;
    }
    return fib[n] = (getFib(n - 1) + getFib(n - 2));
}
int getM(int n)
{
    int ans = 1;
    while(getFib(ans) < n)
    {
        ++ans;
    }
    return ans;
}
int fibSearch(int arr[], int n, int tar)
{
    int m = getM(n);
    int offset = -1;
    while(m > 1)
    {
        int i = min(offset + getFib(m - 2), n - 1);
        if(arr[i] == tar)
        {
            return i;
        }
        else if(arr[i] < tar)
        {
            offset = i;
            m = m - 1;
        }
        else
        {
            m = m - 2;
        }
    }
    if(arr[offset + 1] == tar)
    {
        return (offset + 1);
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
    cout << "Fibonacci Search : " << fibSearch(arr, n, tar) << endl;
}