class PrefixArray:
    def __init__(self, arr):
        self.arr = arr
        self.pre = arr
        self.n = len(arr)
        for i in range(1, self.n):
            self.pre[i] += self.pre[i - 1]

    def query(self, l, r):
        ans = self.pre[r]
        if l > 0:
            ans = ans - self.pre[l - 1]
        return ans

    def update(self, ind, val):
        diff = val - self.arr[ind]
        for i in range(ind, self.n):
            self.pre[i] = self.pre[i] + diff

class BinaryIndexTree:
    def __init__(self, arr):
        self.arr = arr
        self.n = len(arr)
        self.tree = [0] * (self.n + 1)
        for i in range(self.n):
            k = i + 1
            while k <= self.n:
                self.tree[k] += self.arr[i]
                k = k + (k & -k)
    def add(self, k):
        s = 0
        while k >= 1:
            s += self.tree[k]
            k = k - (k & -k)
        return s
    def query(self, l, r):
        return self.add(r + 1) - self.add(l)
    def update(self, k, x):
        x = x - self.arr[k - 1]
        while k <= self.n:
            self.tree[k] = self.tree[k] + x
            k = k + (k & -k)

class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.arr = arr
        n = self.n
        self.tree = [0] * (4 * n + 1)
        for i in range(n, 2 * n):
            self.tree[i] = self.arr[i - n]
        for i in range(n - 1, 0, -1):
            self.tree[i] = self.tree[2 * i] + self.tree[2 * i + 1]
    def update(self, ind, val):
        ind = ind + self.n
        self.tree[ind] = val
        ind = ind // 2
        while ind  > 0:
            self.tree[ind] = self.tree[2 * ind] + self.tree[2 * ind + 1]
            ind = ind // 2

    def query(self, l, r):
        l = l + self.n
        r = r + self.n
        ans = 0
        while l <= r:
            if l % 2 == 1:
                ans += self.tree[l]
                l = l + 1
            if r % 2 == 0:
                ans += self.tree[r]
                r = r - 1
            l = l // 2
            r = r // 2
        return ans


cl = SegmentTree([1, 2, 3, 4, 6])
print(cl.query(0, 3))
