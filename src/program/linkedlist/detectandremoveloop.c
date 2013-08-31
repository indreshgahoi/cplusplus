/* just to find the starting node of the linked list
1) Detect Loop using Floyd’s Cycle detection algo and get the pointer to a loop node.
2) Count the number of nodes in loop. Let the count be k.
3) Fix one pointer to the head and another to kth node from head.
4) Move both pointers at the same pace, they will meet at loop starting node1
*/
 struct node *searchLoopStart(struct node *L)
{
int c;
struct node *slow=L;
struct node *fast;
struct node *vfast;
struct node *ahead=L;
struct node *home=L;
if(!L)
return NULL;
if(L->next==NULL)
return NULL;
fast=L->next;
vfast=L->next->next
while(slow && fast && vfast)
{
if(slow==fast || slow==vfast)
break;
fast=fast->next;
if(fast==NULL)
return NULL;
slow=slow->next;
fast=fast->next->next;
if(fast==NULL)
return NULL;
}

// now the slow pointer is pointing to one of the node in the loop ok if it is exist
// now to know how many nodes are there in the loop
fast=slow;
c=1;
while(fast->next!=slow)
{
c++;
fast=fast->next;
}
//now take a pointer ahead which will traverse c nodes
while(c--)
ahead=ahead->next;

while(ahead!=home)
{

ahead=ahead->next;
home=home->next;
}

return ahead;

}
