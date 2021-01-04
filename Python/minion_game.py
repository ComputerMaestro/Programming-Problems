def minion_game(string):
    stuart, kevin = 0, 0
    l = len(string)
    for i in range(l):
        s = string[i]
        if s in 'AEIOU':
            kevin += (l - i)
        elif s in 'BCDFGHJKLMNPQRSTVWXYZ':
            stuart += (l - i)
    if stuart > kevin : print("Stuart %d" %stuart)
    else: print("kevin %d" %kevin)
    
    
if __name__ == '__main__':
    s = input()
    minion_game(s)
