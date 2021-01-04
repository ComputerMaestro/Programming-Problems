#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the arrayManipulation function below.
def arrayManipulation(n, queries):
    out = [0]*n
    max_val = 0
    for [a,b,k] in queries:
        out[a-1:b] = [x+k for x in out[a-1:b]]
        max_val = max(max_val, max(out[a-1:b]))  

    return max_val

if __name__ == '__main__':
    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    queries = []

    for _ in range(m):
        queries.append(list(map(int, input().rstrip().split())))

    result = arrayManipulation(n, queries)

    print(result)
