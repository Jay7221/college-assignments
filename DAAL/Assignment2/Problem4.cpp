#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void counting_sort(vector<int> &a, vector<int> &val){
    int n = a.size();
    vector<int> count(n);
    for(int i = 0; i < n; ++i){
        ++count[val[i]];
    }
    for(int i = 1; i <= n; ++i){
        count[i] += count[i - 1];
    }
    vector<int> prev = a;
    for(int i = n - 1; i >= 0; --i){
        int ind = count[val[i]];
        --count[val[i]];
        --ind;
        a[ind] = prev[i];
    }
}
void special_sort(vector<int> &a){
    int n = a.size();

    vector<int> y(n);
    for(int i = 0; i < n; ++i){
        y[i] = a[i] % n;
    }
    counting_sort(a, y);

    cerr << "Array A after sorting using y : " << a << '\n';

    vector<int> x(n);
    for(int i = 0; i < n; ++i){
        x[i] = a[i] / n;
    }
    counting_sort(a, x);

    cerr << "Array A after sorting using x : " << a << '\n';
}
int main(){
    int n;

    cerr << "Enter the size of array A : "  << '\n';
    cin >> n;
    vector<int> a(n);
    cerr << "Enter the elements of the array : " << '\n';
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    special_sort(a);
    cerr << "The elements of sorted array A are : "  << '\n';
    for(int elem : a){
        cout << elem << ' ';
    }
    cout << '\n';

    return 0;
}
