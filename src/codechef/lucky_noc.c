#include<stdio.h>
int main(){
  int t,j,ti;
  int a,b,x,y,z,p,c,q,lo,hi;
   scanf("%d",&t);
   while(t--){
      scanf("%d",&a);
      scanf("%d",&b);
      scanf("%d",&x);
      scanf("%d",&y);
      scanf("%d",&z);
      scanf("%d",&p);
      scanf("%d",&c);
      scanf("%d",&q);
      int low[q],high[q];
      j=0;
      int max=-1;
      ti=q;
                  while(q--){
	            scanf("%d",&lo);
	            low[j]=lo;
	            scanf("%d",&hi);
	            high[j]=hi;
	            if(hi>max)
	             max=hi;
		    j++;
	         }
	
	                              int s[max],ans[max];
                                       s[0]=a;
                                       s[1]=b;
	                               int i;
				       ans[0]=0;
				       if(s[0]==c)
					 ans[0]=1;
				       
	                                    for(i=1;i<max;i++){
	                                                 // printf("hello");
                                                             if(i>=2)
                                                              s[i]=(((x*s[i-1]) + (y*s[i-2]) + z)% p);
    
                                                         //printf("s[%d]=%d\n",i,s[i]);
                                                               if(s[i]==c){
                                                                   // printf("hello");
                                                                    ans[i]=ans[i-1]+1;
                                                                }
                                                                 else{
	                                                              ans[i]=ans[i-1];
                                                                 }
	                                    }int k=0;
	                                     for(k=0;k<ti;k++){
					       if(low[k]!=1)
	                                      printf("%d\n",ans[high[k]-1]-ans[low[k]-2]);
					      else
						printf("%d\n",ans[high[k]-1]);
	                                     }
    }
       
	return 0;    
}


