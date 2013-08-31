#include<stdio.h>
#define min(a,b)  (a>b? b:a)
#define max(a,b)  (a>b? a:b)
#define FOR(a,b,i)  for(i=a;i<=b;i++)
#define FOREVER     while(1)
 char ch[1000];
int wd_len(char *s)
 {  int l=0;
     while(((int)(*s))!=32 || (*s)!='\0')
     {
        s++;
       l++;
       puts(s);
       break;

     }
     return l;
 }
int main()
{
    int t,w,h,fn_size,max_line_length,current_line_length,w_ln,no_line;
    char *text=ch,*current,*temp,*wd;
    scanf("%d",&t);
    while(t)
    {  puts("hello");
        scanf("%d%d",&w,&h);
        scanf("%s",text);
        temp=text;
        current=text;
        puts(text);
         //break;
            no_line=1;
            wd=current;
            w_ln=wd_len(wd);
            break;
            current_line_length=max_line_length=w_ln;
            if(w/max_line_length<=min(w,h)){
               fn_size=w/max_line_length;
               puts("hello_if");}
               else
               {
                             puts("hello_else");
                            fn_size=min(w,h);
               }
             while(current!=NULL)
            {         puts("hello");
                      current=text;
                      no_line=1;
                      wd=current;
                      w_ln=wd_len(wd);
                      current_line_length=max_line_length=w_ln;
                      if(fn_size*(max(current_line_length,max_line_length))<=w && ((current_line_length+w_ln+1)*fn_size)<=w)
                      {
                              puts("hello");
                              current=current+w_ln+1;
                              wd=current;
                              w_ln=wd_len(wd);
                              current_line_length=current_line_length+w_ln+1;
                              if(current==NULL){
                                puts("hello");
                                break;
                              }

                      }
                        else
                            {
                               if((fn_size*(no_line+1))<=h && ((w_ln)*fn_size)<=w)
                              {
                                    no_line++;
                                    current_line_length=0;
                                    current=current+w_ln+1;
                                    wd=current;
                                    w_ln=wd_len(wd);
                                    current_line_length=current_line_length+w_ln+1;
                                    if(current==NULL){
                                break;
                              }

                                    if(w_ln>max_line_length)
                                    {
                                      max_line_length=w_ln;
                                    }

                              }
                                  else
                                  {
                                          fn_size-=1;
                                          continue;

                                  }

                         }


             }
             printf("case%d# %d\n",t,fn_size);
             t--;

    }
    return 0;
}
