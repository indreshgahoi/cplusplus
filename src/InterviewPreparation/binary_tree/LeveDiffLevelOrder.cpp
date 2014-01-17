#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

// A binary tree node
struct node
{
	int data;
	struct node *left, *right;
};

// Queue related functions
struct node** createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);

// An iterative method to find difference between
int getLevelDiff(struct node *root)
{
	if (root == NULL)
		return 0;
	int rear, front;
	struct node **queue = createQueue(&front, &rear);
	struct node *temp = root;

	int level = 1, oddLevel_sum, evenLevel_sum;
	oddLevel_sum = evenLevel_sum = 0;

	// A null value is used as a separator between two levels
	enQueue(queue, &rear, root);
	enQueue(queue, &rear, NULL);

	// Do a level order traversal
	while (rear != front)
	{
		temp = deQueue(queue, &front);

		// If this node is NULL, a new level is going to start
		if (temp == NULL)
		{
			// increment level number
			level++;

			// insert a seperator if queue is not empty
			if (rear != front)
				enQueue(queue, &rear, NULL);
		}
		else // If this is from same level as previous node
		{
			if (level & 1)
				oddLevel_sum += temp->data;
			else
				evenLevel_sum += temp->data;
			if (temp->left)
				enQueue(queue, &rear, temp->left);
			if (temp->right)
				enQueue(queue, &rear, temp->right);
		}
	}
	return (oddLevel_sum - evenLevel_sum);
}

struct node** createQueue(int *front, int *rear)
{
	struct node **queue =
			(struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);

	*front = *rear = 0;
	return queue;
}

void enQueue(struct node **queue, int *rear, struct node *new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}

struct node *deQueue(struct node **queue, int *front)
{
	(*front)++;
	return queue[*front - 1];
}

// A utility function to allocate a new tree node with given data
struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

int main()
{
	struct node *root = newNode(5);
	root->left = newNode(2);
	root->right = newNode(6);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	root->left->right->left = newNode(3);
	root->right->right = newNode(8);
	root->right->right->right = newNode(9);
	root->right->right->left = newNode(7);
	printf("%d is the required difference\n",getLevelDiff(root));
	getchar();
	return 0;
}
