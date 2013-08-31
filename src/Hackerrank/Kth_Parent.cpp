/*
 * Kth_Parent.cpp
 *
 *  Created on: Aug 10, 2013
 *      Author: Indresh Gahoi
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<ostream>
#include <fstream>
#include <sstream>
#define InputStream (stdin)
#define OutPutStream (stdout)

#define getNextInt()  ({int __t;fscanf(InputStream,"%d",&__t);__t;})

#define getLog(__K) \
		({ \
			int __log=1,__t=1;	\
			 for(;(2*__t)<=((__K));__t*=2,++__log);	\
			 --__log;	\
	        })	\


template<typename T>
std::ostream& operator<<(std::ostream &out,std::vector<T> &V){

	typename std::vector<T>::const_iterator it=V.begin();
	out<<"[";
	for(;it!=V.end();it++){
		if(*it!=NULL)
		out<<" ("<<(*it)<<"),";
	}
	out<<"\b]"<<std::endl;
	return out;
}



/* Main Code Start  */
struct Guy
{
  int parent_id;
  int id;
  std::vector<int> *array;
  friend std::ostream& operator<<(std::ostream &out,Guy *g)
  {
	  out<<"\b[id:"<<(g->id)<<" p:"<<(g->parent_id)<<" "<<(*(g->array))<<"\b]";
	  return out;
  }
};


int height;

void init(Guy **_rootRef,std::vector<Guy*> **_guysRef)
{

  int noOfGuy;
  size_t iter=0;
  int xGuy,yParentGuy;
  Guy *root;

  fscanf(InputStream,"%d",&noOfGuy);

 height=getLog(100001);

  std::vector<Guy*> *guys=new std::vector<Guy*>(100001,(Guy*)NULL);
 * _guysRef=guys;
  for(iter=0;iter<noOfGuy;++iter){
	 fscanf(InputStream,"%d%d",&xGuy,&yParentGuy);
	 if(!yParentGuy){
		 root=new Guy;
		 root->parent_id=0;
		 root->id=xGuy;
		 root->array=new std::vector<int>(height+1,0);
		 root->array->at(0)=(0);

        if(!guys->at(xGuy))
        	guys->at(xGuy)=root;
        *_rootRef=root;
		continue;
	 }
	 Guy *x,*y;
	 if(!guys->at(xGuy)){
		 x=new Guy;
		 x->array=new std::vector<int>(height+1,0);
		 x->id=xGuy;
		 guys->at(xGuy)=x;
	 }

	 if(!guys->at(yParentGuy)){
		 y=new Guy;
		 y->array=new std::vector<int>(height+1,0);
		 guys->at(yParentGuy)=y;
		 y->id=yParentGuy;
	 }
     x=guys->at(xGuy);
     y= guys->at(yParentGuy);
	 x->parent_id=yParentGuy;
	 x->array->at(0)=(yParentGuy);
  }
}


void add_new_leaf(std::vector<Guy*> &guys,int _x,int _y){

	size_t noOfGuys=guys.size();
	if((guys[_y]==NULL))
	{
		printf("0\n");
		return;
	}
			Guy *x=new Guy;
			 x->array=new std::vector<int>(height+1,0);
			 x->array->at(0)=(_y);
			 x->id=_x;
			 x->parent_id=_y;
			 guys[_x]=x;

	for(size_t h=1;h<height;++h){
		//if(!(guys[_y]==NULL)){
				Guy g=*guys[_x];
				if(g.parent_id!=0){
					if(g.array->at(h-1)!=0){
						Guy p=*guys[g.array->at(h-1)];
						g.array->at(h)=p.array->at(h-1);
					}
					else break;
				}
		//}
	}
}

void remove_leaf_node(std::vector<Guy*> &guys,int _x){
    Guy *g=guys[_x];
    if(g==0)
    	printf("0\n");
    else{
	g->array->clear();
	delete g->array;
	delete g;
	guys[_x]=NULL;
    }
}

void pre_process_guys(std::vector<Guy*> &guys)
{

	size_t noOfGuys=guys.size();
	for(size_t h=1;h<height;++h){
            for(size_t t=0;t<noOfGuys;++t){
                if(!(guys[t]==NULL) && guys[t]->parent_id!=0){
                	Guy g=*guys[t];
                	if(g.parent_id!=0){
                		if(g.array->at(h-1)!=0){
                		Guy p=*guys[g.array->at(h-1)];
                		g.array->at(h)=p.array->at(h-1);
                		}
                	}
                }
            }
	}
}


int find_kth_parents(std::vector<Guy*> &guys,int id,int k)
{
	if(guys[id]==NULL) return 0;

	Guy x=*guys[id];
    if(k==0) return x.id;
    int log=getLog(k);
    int diff=k-(1<<log);
    std::vector<int> *arr=(x.array);
   if(arr->at(log)==0) return 0;
    Guy *g=guys[arr->at(log)];
	for(;diff>0 && g!=0;g=guys[g->parent_id],diff--);
    if(g==0) return 0;
  return g->id;
}

void solve()
{
	std::vector<Guy*> *guys;
	Guy *root;
	init(&root,&guys);
	pre_process_guys(*guys);
	int Q=getNextInt();

	for(size_t t=0;t<Q;++t){
		int c=getNextInt();
		int x,y,k;
		switch(c)
		{
		case 0:
			x=getNextInt();
			y=getNextInt();
			add_new_leaf(*guys,y,x);
			break;
		case 1:
			x=getNextInt();
			remove_leaf_node(*guys,x);
			break;
		case 2:x=getNextInt();
		       k=getNextInt();
		      fprintf(OutPutStream,"%d\n",find_kth_parents(*guys,x,k));

		       break;
		}
	}
}

int main(){
    freopen("input.txt","rw",stdin);
    //freopen("output1.txt","rw",stdout);
	int testCase;
	scanf("%d",&testCase);
	while(testCase--)
		solve();

return 0;
}
