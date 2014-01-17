/*
 * ChefFeedBack.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/codechef/JAN2014/ChefFeedBack.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 12, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<climits>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>

using namespace std;


#define maxx  100005

int main()
{
	char  str[maxx] ;
	int t ,len , iter;

	freopen("input.txt","r",stdin);
	scanf("%d",&t) ;
	while(t--)
	{
		fscanf(stdin,"%s",str) ;
		len = strlen(str) ;
		if(len<3)
		{
			printf("Bad\n");

		}
		else
		{

			for(iter = 2 ; iter < len ; ++iter)
			{
				if((str[iter-2]=='1' && str[iter-1]=='0' && str[iter]=='1') ||
						(str[iter-2]=='0' && str[iter-1]=='1' && str[iter]=='0'))
				{
					printf("Good\n") ;
					break ;
				}
			}
			if(iter==len)
			{
				printf("Bad\n") ;
			}
		}
	}
	return 0 ;
}
