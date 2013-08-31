typedef char graphElementT;
typedef struct graphCDT	*graph;

typedef struct vertexTag 
        {
	    graphElementT element;
	    int visited;
	    struct edgeTag *edges;
	    struct vertexTag *next;
	  } vertexT;
typedef struct edgeTag 
          {
	    struct vertexTag *connectsTo;
	    struct edgeTag *next;
	} edgeT;
typedef struct graphCDT
          {
	     vertexT *vertices;
	 } graphCDT;



