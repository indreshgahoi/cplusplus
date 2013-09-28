#include "tries.c"
#include "expressionvaldEvl.c"



static char *s[10]={
		"user",
		"reqsize",
		"respsize",
		"urlclass",
		"location",
		"department",
		"reqmethod",
		"respcode",
		"useragent",
		"hostname"
};


typedef struct LogValue
{
	char user[N];
	char reqsize[N];
	char respsize[N];
	char urlclass[N];
	char location[N];
	char department[N];
	char reqmethod[N];
	char respcode[N];
	char useragent[N];
	char hostname[N];
	struct LogValue *next;
}LogValueUser;



int parse(char *expression)
{
	int i=0,j=-1,k=0,flag=1;
	char keystr[N],valuestr[N];
	char newstr[N];
	int key=1,value=-1;
	int expressionlen=strlen(expression);

	keystr[0]=valuestr[0]='\0';
	while(expression[i]!='\0')
	{

		if(expression[i]==' '){
			i++;
			continue;
		}
		switch(expression[i])
		{
		case '=':case '<':case '>':
			if(keystr[0]=='\0'||(value==0&&valuestr[0]=='\0')||(keystr[0]!='\0'&&valuestr[0]!='\0')){
				return 0;
			}
			if(key==1&&value==-1){
				value=0;
				key=0;
				keystr[j]='\0';
				Tries *node;
				node=find(&root,keystr);
				if(strlen(keystr)>10||node==NULL||!node->isEnd){
					printf("\ninside if\n");
					return 0;
				}
				j=-2;
			}
			flag=0;
			break;
		case '&':case '|':case '(':case ')':case '!':
			//if(expression[i]==')');
			if((i-1)>=0&&(expression[i]!=')'||expression[i]==')')&&expression[i-1]==')'){
				if(expression[i]!=')'&&(i+1)==expressionlen) return 0;
				newstr[k++]=expression[i];
				flag=0;
				break;
			}
			//else if((i+1)==expressionlen) return 0;
			else if(expression[i]=='!'&&expression[i+1]!='(')
				return 0;
			else if(expression[i]=='('&&(expression[i+1]==')'))
				return 0;
			if(expression[i]=='('){
				newstr[k++]=expression[i];
			}
			else{
				if(keystr[0]=='\0'||valuestr[0]=='\0')
					return 0;
				if(key==0&&value==0)
				{
					newstr[k++]='1';
				}
				value=-1;
				key=1;
				j=-1;
				keystr[0]='\0';
				valuestr[0]='\0';
				newstr[k++]=expression[i];
			}
			flag=0;
			break;
		default :;
		}
		if(flag){
			// if((expression[i]>='a'&&expression[i]<='z')||(expression[i>='A']&&expression[i]<='Z'))
			{
				if(key==1&&value==-1)
				{
					if(j==-1)
						j=0;
					keystr[j++]=expression[i];
				}
				else if(key==0&&value==0)
				{
					if(j==-2)
						j=0;
					valuestr[j++]=expression[i];
				}
				else
					return 0;
			}
		}
		flag=1;
		i++;
	}

	if(keystr[0]!='\0'&&valuestr[0]=='\0')
		return 0;

	if(key==0&&value==0)
	{
		newstr[k++]='1';
	}

	newstr[k]='\0';

	puts(newstr);
	char postfix[N];
	infix_to_postfix(newstr,postfix);
	if(eval_postfix(postfix))
	{
		puts("expression is valid..");
		return 1;
	}
	else
		return 0;

}


boolean isValideLog(char *expression)
{
	int i=0,j,k=0,key=1;
	j=0;
	char compchar='\0';
	char newstr[N],keystr[N],valuestr[N];
	while(expression[i]!='\0')
	{
		if(expression[i]==' ')
		{
			i++;
			continue;
		}
		else if(expression[i]=='='||expression[i]=='>'||expression[i]=='<')
		{
			// puts("====");
			compchar=expression[i];
			keystr[j]='\0';
			key=0;
			j=0;
		}
		else if(expression[i]=='&'||expression[i]=='|'||expression[i]=='!'||expression[i]=='('||expression[i]==')')
		{

			// printf("\n%s %s",keystr,valuestr);

			valuestr[j]='\0';
			Tries *node;
			node=find(&root,keystr);
			if(node==NULL)
			{
				puts("NULL");
				newstr[k++]='0';

			}
			else if(!strcmp(keystr,s[1]))
			{
				int t=0;
				// puts(valuestr);
				switch(compchar)
				{
				case '=':
					//printf("\n%d  %d \n",atoi(node->value),atoi(valuestr));
					if(atoi(node->value)==atoi(valuestr))
						t=1;
					break;

				case '<':if(atoi(node->value)<atoi(valuestr))
					t=1;
				break;
				case '>':   if(atoi(node->value)>atoi(valuestr))
					t=1;
				}
				if(t==1)
					newstr[k++]='1';
				else
					newstr[k++]='0';
			}


			else  if(!strcmp(keystr,s[2]))
			{
				int t=0;
				switch(compchar)
				{
				case '=':
                        		   if(atoi(node->value)==atoi(valuestr))
                        			   t=1;
                        		   break;

				case '<':if(atoi(node->value)<atoi(valuestr))
					t=1;
				break;
				case '>':   if(atoi(node->value)>atoi(valuestr))
					t=1;
				}
				if(t==1)
					newstr[k++]='1';
				else
					newstr[k++]='0';
			}

			else if(strcmp(node->value,valuestr))
			{
				newstr[k++]='0';
			}
			else
			{
				newstr[k++]='1' ;
			}
			newstr[k++]=expression[i];
			keystr[0]=valuestr[0]='\0';
			key=1;
			j=0;
		}

		else //if((expression[i]>='a'&&expression[i]<='z')||(expression[i]>='A'&&expression[i]<='Z')||(expression[i]>='0'
			//&&expression[i]<='9'))
		{
			if(key==1)
			{
				keystr[j++]=expression[i];
			}
			else
			{
				// puts("jjjjjjjjjjjjjjjjj");
				valuestr[j++]=expression[i];
			}
		}

		i++;
	}
	if(keystr[0]!='\0'&&valuestr[0]!='\0')
	{
		valuestr[j]='\0';
		Tries *node;
		node=find(&root,keystr);
		if(node==NULL)
			newstr[k++]='0';
		else if(!strcmp(keystr,s[1]))
		{
			int t=0;
			if(node){
				switch(compchar)
				{
				case '=':
                        		   if(atoi(node->value)==atoi(valuestr))
                        			   t=1;
                        		   break;

				case '<':if(atoi(node->value)<atoi(valuestr))
					t=1;
				break;
				case '>':   if(atoi(node->value)>atoi(valuestr))
					t=1;
				}
			}
			if(t==1)
				newstr[k++]='1';
			else
				newstr[k++]='0';
		}


		else  if(!strcmp(keystr,s[2]))
		{
			int t=0;
			if(node){
				switch(compchar)
				{
				case '=':
                        		   if(atoi(node->value)==atoi(valuestr))
                        			   t=1;
                        		   break;

				case '<':if(atoi(node->value)<atoi(valuestr))
					t=1;
				break;
				case '>':   if(atoi(node->value)>atoi(valuestr))
					t=1;
				}
			}
			if(t==1)
				newstr[k++]='1';
			else
				newstr[k++]='0';
		}

		else if(strcmp(node->value,valuestr))
		{
			newstr[k++]='0';
		}
		else
		{
			newstr[k++]='1' ;
		}
		newstr[k++]=expression[i];
		keystr[0]=valuestr[0]='\0';
		key=1;
		j=0;
	}
	newstr[k]='\0';
	puts(newstr);
	char postfix[N];
	infix_to_postfix(newstr,postfix);
	if(eval_postfix(postfix))
	{
		//puts("expression is valid..");
		return 1;
	}
	else
		return 0;
}



void fillLogUserStructure(LogValueUser *valideFilters)
{
	int i=0;
	Tries *node;
	for (i=0;i<10;i++)
	{
		node=find(&root,s[i]);
		switch(i)
		{
		case 0:
			if(node)
				strcpy(valideFilters->user,node->value);
			break;
		case 1:
			if(node)
				strcpy(valideFilters->reqsize,node->value);
			break;
		case 2:
			if(node)
				strcpy(valideFilters->respsize,node->value);
			break;
		case 3:
			if(node)
				strcpy(valideFilters->urlclass,node->value);
			break;
		case 4:
			if(node)
				strcpy(valideFilters->location,node->value);
			break;
		case 5:
			if(node)
				strcpy(valideFilters->department,node->value);
			break;
		case 6:
			if(node)
				strcpy(valideFilters->reqmethod,node->value);
			break;
		case 7:
			if(node)
				strcpy(valideFilters->respcode,node->value);
			break;
		case 8:
			if(node)
				strcpy(valideFilters->useragent,node->value);
			break;
		case 9:
			if(node)
				strcpy(valideFilters->hostname,node->value);

		}
	}
}

void copyLogInfo(LogValueUser *valideFilters)
{
	if(valideFilters==NULL)
	{
		valideFilters=(LogValueUser *)malloc(sizeof(LogValueUser));
		fillLogUserStructure(valideFilters);
	}
	else
	{
		LogValueUser *prv=valideFilters;
		while(valideFilters->next)
		{
			prv=valideFilters->next;
		}
		prv->next=(LogValueUser *)malloc(sizeof(LogValueUser));
		fillLogUserStructure(prv->next);
	}
}

int main(int argc,char **argv)
{


	char *expression;
	FILE *fp;
	if(argc<5)
	{
		printf("\nsome problem in the input");
		return 1;
	}
	expression=argv[argc-1];
	puts(expression);

	Triesnodeinit(&root);
	int i=0,j;
	for(i=0;i<10;i++)
	{
		//puts(s[i]);
		addWordHelper(&root,s[i],0,s[i]);
	}

	if(parse(expression))
	{
		char ch;
		char keystr[N];
		char valuestr[N];
		int key,attributes,i,j;

		LogValueUser *valideFilters=NULL;

		fp=fopen("sample.txt","r");
		if(fp==NULL)
		{
			printf("\nError while opening the file.\n");
			exit(EXIT_FAILURE);
		}

		keystr[0]=valuestr[0]='\0';
		key=1;attributes=0;j=0;

		while( ( ch = fgetc(fp) ) != EOF ){
			if(ch==' ')
				continue;
			else if(ch=='=')
			{
				key=0;
				keystr[j]='\0';
				j=0;
			}
			else if(ch==',')
			{
				valuestr[j]='\0';
				// printf("\nkey:%s  value:%s",keystr,valuestr);
				addWordHelper(&root,keystr,0,valuestr);
				keystr[0]=valuestr[0]='\0';
				key=1;
				j=0;
				attributes++;
			}
			else if(ch=='\n')
			{
				attributes=0;
				//puts(",,,");
				if(isValideLog(expression))
				{
					copyLogInfo(valideFilters);
				}
				else
				{
					// puts("not valid");
				}
			}
			else //if(( ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
			{
				if(key==1)
				{
					keystr[j++]=ch;
				}
				else if(key==0)
				{
					if(j==-2)
						j=0;
					valuestr[j++]=ch;
				}
			}
		}

	}
	else
	{
		printf("expression given by the user is wrong one.\n");
		return 1;
	}
	return 0;
}

