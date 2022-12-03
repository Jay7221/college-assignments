class BinarySearch:
    def __init__(self, arr):
        self.arr = arr
        self.n = len(self.arr)

    def search(self, tar):
        L = 0
        R = self.n - 1
        while L < R:
            M = (L + R) // 2
            if self.arr[M] >= tar:
                R = M
            else:
                L = M + 1
        return L

n = int(input('Enter size of array : '))
arr = []
for i in range(n):
    a = int(input())
    arr.append(a)
k = int(input('Enter element to be searched : '));
search = BinarySearch(arr) 
print('Index is : ', search.search(k))
