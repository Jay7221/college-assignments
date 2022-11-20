def multiply(A, B):
    if(len(A[0]) != len(B)):
        print('Matrix multiplicaton not possible')
        return False
    n = len(A)
    m = len(B[0])
    s = len(A[0])
    C = []
    for i in range(n):
        C.append([])
        for j in range(m):
            C[i].append(0)
            for k in range(s):
                C[i][j] += A[i][k] * B[k][j]
    return C

def printMatrix(M):
    for row in M:
        print(row)

def inputMatrix():
    M = []
    n = int(input("Enter the number of rows in matrix : "))
    for i in range(n):
        row = list(map(int, input().strip().split()))
        M.append(row)
    return M

A = inputMatrix()
B = inputMatrix()
printMatrix(multiply(A, B))
