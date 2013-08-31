#define NULL 0
#define HASHSIZE 101
struct nlist
{
struct nlist *next;
char *name;
};

static struct nlist *hashtab[HASHSIZE];
unsigned hash(char *s)
{
unsigned hashval;
for(hashval=0;*s!='\0';s++)
{
hashval=*s+31*hashval;
}
return(hashval%HASHSIZE);
}
struct nlist* lookup(char *s)
{
struct nlist *np;
for(np=hashtab[hash(s)];np!=NULL;np=np->next)
{
if(strcmp(s,np->name)==0)
return(np);
}
return(NULL);
}

struct nlist* install(char *name)
{
struct nlist *np;
unsigned hashval;
if((np==lookup(name))==NULL)
{np=(struct nlist*)malloc(sizeof(*np));
if(np==NULL)
return NULL;
hashval=hash(name);
np->next=hashtab[hashval];
hashtab[hashval]=np;
}
return np;
}
int main()
{
char *s;
int ch;
struct nlist *np;
while(1)
{
printf("\n1.wanna enter\n2.exit\n");
scanf("%d",&ch);
if(ch==2)
exit(0);
scanf("%s",&s);
np=install(s);
if(np==NULL)
printf("%s exiist",s);
}
return 0;
}
