def solve(S):
    top_str = S[1:]
    for i in range(1, len(S)):
        s = S[:i]+S[i+1:]
        if s < top_str:
            top_str = s
    return top_str

S = input()
print(solve(S))
