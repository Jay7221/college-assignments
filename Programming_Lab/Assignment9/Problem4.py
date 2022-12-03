class Subsets:
    def __init__(self, arr):
        self.arr = arr
        self.n = len(self.arr)

    def getAllSubsets(self):
        n = self.n
        ans = []
        for i in range(0, ( 1 << n)):
            cur = []
            for j in range(0, n):
                if (i >> j) & 1 == 1:
                    cur.append(self.arr[j])
            ans.append(cur)
        return ans

sub = Subsets([1, 2, 3, 4])
for s in sub.getAllSubsets():
    print(s)
