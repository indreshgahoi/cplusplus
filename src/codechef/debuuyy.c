#include <stdio.h>
#include <malloc.h>

typedef struct elt {
	int data;
	struct elt* next;
} elt;

int main(int argc, char* argv[]) {
	int i;
	elt* list = NULL;
	elt* p = NULL;
	for (i = 1; i < argc ; i++) {
		p = (elt *) malloc(sizeof(elt));
		p->data = (int) argv[i][1]; /* Fails with empty argument */
		p->next = list;
		list = p;
	}
	while(list != NULL) {
		p = list;
		list = list->next;
		free(p->next); /* Oops... should be p */
	}
	exit(0);
}
