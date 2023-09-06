#include <iostream>
using namespace std;

class TwoStack{
    private:
        int MAX, cur1, cur2;
        int *arr;
    public:
        TwoStack(int size){
            MAX = size;
            arr = new int(MAX);
            cur1 = 0;
            cur2 = MAX - 1;
        }
        void push1(int x){
            if(cur1 > cur2){
                cout << "STACK OVERFLOW" << endl;
                return ;
            }
            arr[cur1] = x;
            cur1 = cur1 + 1;
        }
        void push2(int x){
            if(cur1 > cur2){
                cout << "STACK OVERFLOW" << endl;
                return ;
            }
            arr[cur2] = x;
            cur2 = cur2 - 1;
        }
        int pop1(){
            if(cur1 == 0){
                cout << "EMPTY STACK" << endl;
                return -1;
            }
            cur1 = cur1 - 1;
            return arr[cur1];
        }
        int pop2(){
            if(cur2 == MAX - 1){
                cout << "EMPTY STACK" << endl;
                return -1;
            }
            cur2 = cur2 + 1;
            return arr[cur2];
        }
};
void display(){
    cout << "================================================="<< endl;
    cout << "1. PUSH ELEMENT" << endl;
    cout << "2. POP last odd element"<< endl;
    cout << "3. POP last even element"<< endl;
    cout << "4. EXIT"<< endl;
}
bool input(TwoStack &st){
    int k;
    cin >> k;
    bool flag = true;
    if(k == 1){
        cout << "Enter an element : ";
        int x;
        cin >> x;
        if(x % 2){
            st.push2(x);
        }else{
            st.push1(x);
        }
    }else if(k == 2){
        int x = st.pop2();
        if(x != -1){
            cout << "The last odd element is : "<< x << endl;
        }
    }else if(k == 3){
        int x = st.pop1();
        if(x != -1){
            cout << "The last even element is : "<< x << endl;
        }
    }else{
        flag = false;
    }
    return flag;
}
int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    bool flag = true;
    TwoStack st(n);
    while(flag){
        display();
        flag = input(st);
    }
    return 0;
}
