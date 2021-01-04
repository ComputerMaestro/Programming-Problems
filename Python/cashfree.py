def recur(mem, a, b, y, x):
    if a == x and b == y:
        return "Yes"
    elif (a, b) in mem.keys():
        return mem[(a, b)]
    if a < x:
        if recur(mem, a+b, b, y, x) == "Yes": return "Yes"
        mem[(a+b, b)] = "No"
    if b < y:
        if recur(mem, a, a+b, y, x) == "Yes": return "Yes"
        mem[(a, a+b)] = "No"
    return "No"

def solve (y, x):
    out = "No"
    if(y == 1 and x == 1):
        return "Yes"
    mem = {}
    return recur(mem, 1, 1, y, x)

T = int(input())
for _ in range(T):
    x, y = map(int,input().split(" "))

    out_ = solve(y, x)
    print (out_)
