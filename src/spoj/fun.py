t=(int)(raw_input())
for i in range(t):
   a,b,n,m =map(int,raw_input().split())
   s = a+b
   for j in range(2,n):
     t=a
     a=b
     b=t+a
     s=s+b
   res=s%m
   print (res)
