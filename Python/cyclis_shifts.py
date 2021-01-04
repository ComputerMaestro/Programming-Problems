def rot(A):
    return A[1:]+A[0]

def find_max(A, N):
    B = A
    cur = A
    for i in range(N):
        cur = rot(cur)
        if cur > B: B = cur
    return B

def find_same(A, B, N):
    cur = A
    idxs = []
    for i in range(1, N+1):
        print(i, cur)
        if cur == B: idxs.append(i)
        cur = rot(cur)
    return idxs

T  = int(input())

for t in range(T):
    nk = input().split(' ')
    N = int(nk[0])
    K = int(nk[1])
    A = input()
    print(A)
    ops = 0
    B = find_max(A, N)
    print(A, B)
    same_B = find_same(A, B, N)
    print(same_B)
    if K %len(same_B) == 0: ops = ((K/len(same_B))-)*N + same_B[-1]-1
    else: ops = (K//len(same_B))*N+same_B[(K%len(sam1e_B))-1]
    print(ops)
