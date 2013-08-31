#include<stdio.h>
char a[1000002];
char p[1000002];
int p1=0,p2=0,counter=0;

int main()
{
    int t,i,j,k;
    char *num;
    scanf("%d",&t);
    while(t--){
         p1=p2=counter=0;
         scanf("%s",a+1);
         num=a+1;
         for(i=0;*(num+i)!='\0';i++){
               p[++counter]= *(num+i);
         }

        if(counter%2==0)
          {
              p1=counter/2;
              p2=p1+1;

          }
        else{
            p1=p2=counter/2+1;
        }

        for(i=p1,j=p2;i>=1;i--,j++){
             a[j]=a[i];
        }
      k=1;
      for(i=p2;*(a+i) != '\0';i++){
          if(a[i]==p[i]){
             continue;
          }
             else if(a[i]>p[i]){
               k=0;
               puts(a+1);
               }
               break;

      }

 while(k){

             if(p1<1){
                a[p2-1]=a[0]='1';
                counter++;
                    puts(a);
                    break;
                }
                 else if(a[p1]<'9'){
                     a[p1]++;
                     a[p2]=a[p1];

                 }
                 else{
                      a[p1]=a[p2]='0';
                      }


                     if(a[p1]>p[p1]){
                               puts(a+1);
                                   break;
                     }
                     p2++;p1--;
         }

    }
    return 0;
}
