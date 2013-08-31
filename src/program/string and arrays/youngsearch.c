void searchTabulueYoung(int young[4][4],int key)
{
int i,j;
i=0;
j=3;
while(i<4 && j>0)
{
if(key==young[i][j])
break;
if(key<young[i][j])
j--;
else
i++;
}
if(young[i][j]==key)
printf("the key exist at position number (%d,%d)",i,j);
else
printf("NOT EXIST");
}
int main()
{
  int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  searchTabulueYoung(mat,39);
return 0;
}
