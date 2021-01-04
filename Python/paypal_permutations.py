#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'n_strings += countPerms' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER n as parameter.
#

def u_switch(diff, l, string):
    u_switcher = {
        diff > 2: 'uae',
        diff == 2 : 'ua',
        diff == 1 : 'u'
    }
    true = u_switcher[True]
    return {'l': l+len(true), 'string': string+true}

def a_switch(diff, l, string):
    a_switcher = {
        diff > 1: 'ae',
        diff == 1:'a'
    }
    true = a_switcher[True]
    return {'l': l+len(true), 'string': string+true}

def countPerms(n, l = 0, string = ""):
    # Write your code here
    diff = n-l
    if string == "": return countPerms(n, **a_switch(n, l, string)) + countPerms(n, l+1, "e") + countPerms(n, l+1, "i") + countPerms(n, l+1, "o") + countPerms(n, **u_switch(n, l, string))
    elif diff == 0: return 1
    elif string[-1] == 'a': return countPerms(n, l+1, string+'e')
    elif string[-1] == 'e': return (countPerms(n, **a_switch(diff, l, string)) + countPerms(n, l+1, string+'i'))
    elif string[-1] == 'i': return (countPerms(n, **a_switch(diff, l, string)) + countPerms(n, l+1, string+'e') + countPerms(n, l+1, string+'o') + countPerms(n, **u_switch(diff, l, string)))
    elif string[-1] == 'o': return (countPerms(n, l+1, string+'i') + countPerms(n, **u_switch(diff, l, string)))
    else: return countPerms(n, **a_switch(diff, l, string))


if __name__ == '__main__':

    n = int(input())

    result = countPerms(n) % (10**9+7)

    print(result)
