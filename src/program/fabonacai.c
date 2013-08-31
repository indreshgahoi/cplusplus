#include<stdio.h>
void nthpower(int a[][2],int k){
    int i,j,l,temp[2][2],m[2][2]={ {1,1},
                      {1,0}};
    if(k==1){
        return;
    }

        nthpower(a,k/2);
        for(i=0;i<2;i++){
         for(j=0;j<2;j++){
           temp[i][j]=0;
           for(l=0;l<2;l++){
              temp[i][j]=temp[i][j]+a[i][l]*a[l][j];
           }
         }}
         for(i=0;i<2;i++){
         for(j=0;j<2;j++){
           a[i][j]=temp[i][j];}}
    if(k%2==1){
        for(i=0;i<2;i++){
         for(j=0;j<2;j++){
           temp[i][j]=0;
           for(l=0;l<2;l++){
              temp[i][j]=temp[i][j]+a[i][l]*m[l][j];
           }
         }}
         for(i=0;i<2;i++){
         for(j=0;j<2;j++){
           a[i][j]=temp[i][j];}}

    }
}

int ithterm(int i){
    int an=1,an1=1,aux=an1,k;
    int a[2][2]={ {1,1},
                      {1,0}};
    int c[2][1]={an1,an};

    if(i<=2){
      if(i==1)
      return an;
      if(i==2)
      return an1;
    }
    else{
        k=i-2;
        nthpower(a,k);
        c[0][0]=  a[0][0]*c[0][0] + a[0][1]*c[1][0];
        c[1][1]= a[1][0]*c[0][0]+ a[1][1]*c[1][0];
      }
      return c[0][0];
}
void fabe_range(int st,int ln){
      int i=0;
      int num,fn,fn1,aux;
      fn=ithterm(st);
      printf("Start:\n");
      printf("      %d  ",fn);
      if(ln>1){
      fn1=ithterm(st+1);
      printf("      %d",fn1);}

       for(i=st+2;i<=st+ln-1;i++){
           aux=fn1;
           fn1=fn+fn1;
           fn=aux;
           printf(" %d",fn1);
       }
}

int main(){
   int st , ln;
   printf("Enter the start point and length:");
   scanf("%d%d",&st,&ln);
   fabe_range(st,ln);
   return 0;
}
