import sys
import operator
from blist import sortedlist
from blist import sortedset
from Queue import Queue
from collections import Counter
 
def algo(caseno, n, k, a, b, c, r):
    m = [a]
    firstelem = a
 
    #generate m
    counts = Counter()
    for i in range(1, k):
        mi = ((((b%r) * (m[i-1]%r))%r) + (c%r))%r
        if(mi <= k):
            counts[mi] += 1
        m.append(mi)
 
    #generate a tree of num 0 - k, which is NOT present in m
    #the they are in sorted order, so the first element would the min elment not in the k window
    tree = sortedset([])
    for i in range(k+1):
        if i not in counts:
            tree.add(i)
 
    #find the k+1 length array which contains value from 0 - k+1 and thus would obviously repeate itself
    replist = []
    for i in range(k):
         
        #add first element from the tree
        replist.append(tree.pop(0))
         
        #remove the front element and bring it to the not-available tree
        if (m[i] <= k):
            if (counts[m[i]] == 1):
                tree.add(m[i])
            else: counts[m[i]]-=1
     
     
    result = replist[(n-1 -k) % (k+1)]
    print ("Case #%d: %d"%(caseno, result))
 
############main#############
m = int(sys.stdin.readline())
for i in range(m):
    kn = list(map(int, sys.stdin.readline().split()))
    abc = list(map(int, sys.stdin.readline().split()))
    algo(i+1, kn[0], kn[1], abc[0], abc[1], abc[2], abc[3])