/*
 * graphrepresentation.cpp
 *
 *  Created on: May 8, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<ostream>
#include <vector>
#include<cassert>

enum State
{
	Visit,
	Visiting,
	Visited
};
struct Node{
	int id;
	int state;
	//Node(int id):id(id),state(0){}
	friend std::ostream& operator<<(std::ostream& out,Node *n)
	{
		out<<"["<<n->id<<":state="<<n->state<<"]";
		return out;
	}
};

struct Edge{
	Node *s;
	Node *e;
	int cost;
};

struct listNode{
	Node *id;
	listNode* next;
	listNode(Node* a):next(NULL)
	{
		id=a;
	}
	friend std::ostream& operator<<(std::ostream& out,listNode* lNode)
	{
		while(lNode->next)
		{
			out<<lNode->id<<"->";
			lNode=lNode->next;
		}
		out<<lNode->id;
		return out;
	}
};


struct graph{
	int noOfVirtices;
	bool directed;
	listNode **adjList;
	graph(int V,bool directed):noOfVirtices(V),directed(directed){
		adjList=new listNode*[V];
		for(int i=0;i<noOfVirtices;i++)
		{
			adjList[i]=NULL;
		}
	}

  void addEdge(const Edge &edge)
   {
	 listNode *neighbour=new listNode(edge.e);

	  neighbour->next=adjList[edge.s->id];
	  adjList[edge.s->id]=neighbour;

	  if(!directed)
	  {
		 neighbour=new listNode(edge.s);
		 neighbour->next=adjList[edge.e->id];
		 adjList[edge.e->id]=neighbour;
	  }

   }
   listNode* getNeighbours(const Node* node)
   {
	   assert(adjList!=NULL && noOfVirtices<node->id);
	   return adjList[node->id];
   }
   friend std::ostream& operator<<(std::ostream& out,graph *g)
   {
	   out<<"Adjancy List\n\n";
	   for(int i=0;i<g->noOfVirtices;i++)
	   {
		   out<<"["<<i<<"]->";
		   if(g->adjList[i])
		   {
			   out<<g->adjList[i]<<"\n";
		   }
		   else
		   {
			   out<<"[NULL]\n";
		   }
	   }
	   return out;

   }


};


Node *nodes;
graph *g;
void init_graph(int V)
{
	g=new graph(V,false);
	nodes=new Node[V];
	for(int i=0;i<V;i++)
	{
		nodes[i].id=i;
	}
}

Edge* createEdge(int i,int j,int cost)
{
	Edge* edge=new Edge();
	edge->s=(nodes+i);
	edge->e=(nodes+j);
	edge->cost=cost;
	return edge;
}

void scanGraph()
{
	int V,E;
	std::cin>>V>>E;
    init_graph(V);
	int s,e,c;
	Edge edge;
	for(int i=0;i<E;i++)
	{
		std::cin>>s>>e>>c;
		edge=*createEdge(s,e,c);
		g->addEdge(edge);
	}

}

void testGraphRepresentation()
{
	std::cout<<"Enter the Number of Vertices and Edges and edges(start end cast)"<<std::endl;
    scanGraph();
    std::cout<<g;
}

int main()
{
 testGraphRepresentation();
 return (0);
}


