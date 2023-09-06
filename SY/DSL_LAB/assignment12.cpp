#include<iostream>
using namespace std;
class Hash
{
    public:
        int n;
        int *tableKey, *tableVal;
        Hash(int n)
        {
            this -> n = n;
            tableKey = new int[n];
            tableVal = new int[n];
            for(int i = 0; i < n; ++i)
            {
                tableKey[i] = -1;
            }
        }
        void insert(int key, int val)
        {
            int new_key = key % n;
            int cnt = n;
            while ((tableKey[new_key] != -1) && cnt)
            {
                --cnt;
                ++new_key;
                new_key %= n;
            }
            if(tableKey[new_key] != -1)
            {
                cout << "Hash Map is Full" << endl;
                return;
            }
            tableKey[new_key] = key;
            tableVal[new_key] = val;
        }
        int get(int key)
        {
            int new_key = key % n;
            int cnt = n;
            while ((tableKey[new_key] != key) && cnt)
            {
                --cnt;
                ++new_key;
                new_key %= n;
            }
            if(tableKey[new_key] == key)
            {
                return tableVal[new_key];
            }
            return -1;
        }
};
int main()
{
    Hash h(10);
    for(int i = 1; i < 14; ++i)
    {
        cout << i << " : ";
        h.insert(i, i * i);
        cout << endl;
    }
    for(int i = 1; i < 14; ++i)
    {
        cout << i << " : " << h.get(i) << endl;
    }
    return 0;
}