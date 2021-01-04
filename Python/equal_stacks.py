#!/bin/python3

import os
import sys

#
# Complete the equalStacks function below.
#
def equalStacks(h1, h2, h3):
    #
    # Write your code here.
    #
    stacks = [h1, h2, h3]
    H = [sum(h1), sum(h2), sum(h3)]
    while H[0] != H[1] or H[1] != H[2] or H[0] != H[2]:
        max_idx = H.index(max(H))
        stacks[max_idx].pop()
        H = [sum(h1), sum(h2), sum(h3)]
        if H[max_idx] == 0: return 0
    return H[0]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n1N2N3 = input().split()

    n1 = int(n1N2N3[0])

    n2 = int(n1N2N3[1])

    n3 = int(n1N2N3[2])

    h1 = list(map(int, input().rstrip().split()))

    h2 = list(map(int, input().rstrip().split()))

    h3 = list(map(int, input().rstrip().split()))

    result = equalStacks(h1, h2, h3)

    fptr.write(str(result) + '\n')

    fptr.close()
