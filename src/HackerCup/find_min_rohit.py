from time import clock, time
start = clock()

def Find_Min():
    fi = open("FindTheMinimum.txt","r")
    fo = open("FindTheMinimum.out","w")
    test = int(fi.readline())
    for case in range (test):
        n,k = (fi.readline()).split()
        a,b,c,r = (fi.readline()).split()
        m = []
        n = int (n)
        k = int (k)
        a = int (a)
        b = int (b)
        c = int (c)
        r = int (r)
        global d
        d = {}
        prev = 0
        cur = 0
        m.append(a)
        d[a] = 1
        for i in range(1,k):
            x = ((b* m[i-1]+c)%r)
            m.append(x)
            if x in d:
                d[x]+=1
            else:
                d[x] = 1
        rng = n%k
        if n < 2*k:
           rng+=1
        for i in range (1,rng):
            while (prev in d):
                prev+=1
            cur = prev
            #print(cur)
            p = m.pop(0)
            if d[p]>1:
                d[p]-=1
            else:
                del d[p]
            if (p<prev):
                prev = p
            m.append(cur)
            d[cur] = 1

        fo.write("Case #" + str(case+1) + ": " + str(cur)+ "\n")
        #print(cur)
        #print (m)
        #print (d)
    fi.close()
    fo.close()
Find_Min()
print ((clock() - start))
