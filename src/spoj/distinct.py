def LCS(X, Y):
    m = len(X)
    n = len(Y)
    # An (m+1) times (n+1) matrix
    C = [[0] * (n+1) for i in range(m+1)]
    for i in range(1, m+1):
        for j in range(1, n+1):
            if X[i-1] == Y[j-1]: 
                C[i][j] = C[i-1][j-1] + 1
            else:
                C[i][j] = max(C[i][j-1], C[i-1][j])
  
    return C

def backTrackAll(C, X, Y, i, j):
    if i == 0 or j == 0:
        return set([""])
    elif X[i-1] == Y[j-1]:
        print i,j,X[i-1]
        #print backTrackAll(C, X, Y, i-1, j-1)
        return set([Z + X[i-1] for Z in backTrackAll(C, X, Y, i-1, j-1)])
    else:
        R = set()
        if C[i][j-1] >= C[i-1][j]:
            #print backTrackAll(C, X, Y, i, j-1) 
            R.update(backTrackAll(C, X, Y, i, j-1))
            print i,j,R
        if C[i-1][j] >= C[i][j-1]:
            #print backTrackAll(C, X, Y, i-1, j)
            R.update(backTrackAll(C, X, Y, i-1, j))
            print i,j,R
        return R	
	
 
t=(int)(raw_input())
for i in range(t):
 X = (raw_input())
 Y = raw_input()
 m = len(X)
 n = len(Y)
 C = LCS(X,Y)
 for row in C:
  print row
  
 S = set()
 S = backTrackAll(C, X, Y, m, n)
 for x in S:
  print x


		
		
