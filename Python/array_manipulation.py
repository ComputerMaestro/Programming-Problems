#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the arrayManipulation function below.
def add(A, a, b, k):
    m = 0
    for idx in range(a-1, b):
        t = int(A[idx])+k
        if t > m: m = t
        A[idx] = str(t)
    return m

def arrayManipulation(n, queries):
    a = ['0']*n
    m = 0
    for q in queries:
        t = add(a, q[0], q[1], q[2])
        print(a)
        if t > m:
            m = t
    return m
    

nm = input().split()

n = int(nm[0]) 

m = int(nm[1])

queries = []

for _ in range(m):
    queries.append(list(map(int, input().rstrip().split())))

result = arrayManipulation(n, queries)
print(result)

