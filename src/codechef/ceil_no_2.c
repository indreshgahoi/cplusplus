#include<stdio.h>
#include<string.h>

int main()
{
    int t,ct=0;
    char cha;
    int ch[10]={0};
    scanf("%d\n",&t);


    while(t--)
    {

        while((cha=getchar())!='\n')
        {
            if(cha != ' ')
            {
             if(cha <='9' && cha >='0')
               ch[cha-'0']++;
            }
            else
            {
                ch[0]=ch[1]=ch[2]=ch[4]=ch[6]=ch[7]=ch[9]=ch[3]=ch[5]=ch[8]=0;
            }

        }

        if(ch[0]==0 && ch[1]==0 && ch[2]==0 && ch[4]==0 && ch[6]==0 && ch[7]==0 && ch[9]==0)
        {
            if(ch[8]>=ch[5])
             if(ch[5]>=ch[3])
               ct++;
        }
      ch[0]=ch[1]=ch[2]=ch[4]=ch[6]=ch[7]=ch[9]=ch[3]=ch[5]=ch[8]=0;

    }
     printf("%d\n",ct);
    return 0;
}
