#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int CryptOrDecrypt( int ch )
{
char key = 'a';
return( ch^key );
}
int main( void )
{
int ch;
FILE *fp =fopen("test.txt","r");
while(!feof(fp))
{
ch =fgetc(fp);
ch =CryptOrDecrypt(ch);
fseek(fp,SEEK_CUR,-1 );
fputc(ch,fp);
}
fclose(fp);
return 0;
}
