def print1(n):
    for i in range(1, n + 1):
        s = " " * (n - i)
        s += ("* " * i).strip()
        print(s)

def print2(n):
    for i in range(n, 0, -1):
        s = " " * (n - i)
        s += ("* " * i).strip()
        print(s)
        
def print3(n):
    print1(n)
    for i in range(n - 1, 0, -1):
        s = " " * (n - i)
        s += ("* " * i).strip()
        print(s)

def print4(n):
    m = 2 * n - 1
    arr = ['*'] * (2 * n - 1)
    cur1 = n - 1
    cur2 = n - 1
    for i in range(0, n):
        arr[cur1] = ' '
        arr[cur2] = ' '
        s = ' '.join(arr)
        print(s)
        cur1 = cur1 + 1
        cur2 = cur2 - 1
    cur1 = cur1 - 1
    cur2 = cur2 + 1
    for i in range(0, n - 1):
        arr[cur1] = '*'
        arr[cur2] = '*'
        s = ' '.join(arr)
        print(s)
        cur1 = cur1 - 1
        cur2 = cur2 + 1
        
        
        
def print5(n):
    for i in range(1, n + 1):
        s = "* " * i
        s.strip()
        print(s)
        
def print6(n):
    for i in range(n, 0, -1):
        s = "* " * i
        s.strip()
        print(s)
        
def print7(n):
    for i in range(1, n + 1):
        s = "  " * (n - i)
        s += ("* ") * i
        print(s)
        
def print8(n):
    for i in range(n, 0, -1):
        s = "  " * (n - i)
        s += ("* ") * i
        print(s)
        
def print9(n):
    m = 2 * n - 1
    arr = [' '] * (2 * n - 1)
    cur1 = n - 1
    cur2 = n - 1
    for i in range(0, n):
        arr[cur1] = '*'
        arr[cur2] = '*'
        s = ' '.join(arr)
        print(s)
        arr[cur1] = ' '
        arr[cur2] = ' '
        cur1 = cur1 + 1
        cur2 = cur2 - 1
    cur1 = cur1 - 2
    cur2 = cur2 + 2
    for i in range(0, n - 1):
        arr[cur1] = '*'
        arr[cur2] = '*'
        s = ' '.join(arr)
        print(s)
        arr[cur1] = ' '
        arr[cur2] = ' '
        cur1 = cur1 - 1
        cur2 = cur2 + 1
        
def printPat(n, b):
    if b == 1:
        print1(n)
    elif b == 2:
        print2(n)
    elif b == 3:
        print3(n)
    elif b == 4:
        print4(n)
    elif b == 5:
        print5(n)
    elif b == 6:
        print6(n)
    elif b == 7:
        print7(n)
    elif b == 8:
        print8(n)
    elif b == 9:
        print9(n)
        
n = 10
for i in range(1, 10):
    print(i)
    printPat(n, i)
    print("--------------------------------------------------------------")
