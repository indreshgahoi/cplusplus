int Powerof2(int num)
{
num=num&(num-1);
if(num==0)
return 1;
else
return 0;



}