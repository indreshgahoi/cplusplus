#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool myfunction (pair<int,int> i,pair<int,int> j)
{
  if(i.first != j.first)
     return i.first > j.first;

   return i.second< j.second;

}


int main()
{
    int n,k,p,t,tmp;
    vector < pair<int,int> > tab;
    scanf("%d%d",&n,&k);
    tmp=n;

    while(n--)
    {
        scanf("%d%d",&p,&t);
        tab.push_back(make_pair(p,t));
    }
    sort(tab.begin(),tab.end(),myfunction);
   //for(int i=0;i<tmp;i++)
  //  printf("%d %d\n",tab[i].first,tab[i].second);

    int j=0;
    int flag=1;
    int key1, key2;
   for(int i=0;i<tmp && flag;)
     {   key1=tab[i].first;
         key2=tab[i].second;
        j=0;
         do
         {



            if(i==(k-1))
                     {
                         flag=0;
                      }

            if(key2 ==tab[i].second)
               j++;
             else
             {
            	 if(i==(k-1))
                 {
            	 flag=1;
                  //i--;
                 }
              break;
             }

             //j++;

            i++;
         }while(tab[i].first==key1);
          //printf("%d\n",j);
         if(flag==0){
              printf("%d",j);
           }
     }

     return 0;
}
