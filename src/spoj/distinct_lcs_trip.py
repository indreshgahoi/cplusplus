def LCS(X, Y):
    m = len(X)
    n = len(Y)
    # An (m+1) times (n+1) matrix
    C = [[0] * (n+1) for i in range(m+1)]
    R=[ [set([""])] * (n+1) for i in range(m+1)]
    
    for i in range(1, m+1):
        for j in range(1, n+1):
            if X[i-1] == Y[j-1]: 
                C[i][j] = C[i-1][j-1] + 1
                R[i][j]=set([Z + X[i-1] for Z in R[i-1][j-1]])
                #print R[i][j] 
            else:
                C[i][j] = max(C[i][j-1], C[i-1][j])
                if(C[i][j-1]==C[i-1][j]):
                   R[i][j]=R[i-1][j].union(R[i][j-1])
                   #print R[i][j]
                else:
                    if(C[i][j-1]>C[i-1][j]):
                       R[i][j]=R[i][j-1]
                      # print R[i][j]
                    else:
                         R[i][j]=R[i-1][j]
                       #  print R[i][j] 
                           
                         
    return R[m][n]    

	

	
 
t=(int)(raw_input())
for i in range(t):
 X = raw_input()
 Y = raw_input()
 m = len(X)
 n = len(Y)
 D = LCS(X,Y)
 for row in D:
  print row
  

		
		
