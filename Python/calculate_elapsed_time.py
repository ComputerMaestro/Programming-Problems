import time
a = [0]*5
t0 = time.perf_counter()
c = [2+x for x in a]
t1 = time.perf_counter()
b = list(map(lambda x: x+2, a))
t2 = time.perf_counter()
print('1', t1-t0)
print('2', t2-t1)
