for the balance search tree from the sorted array it is right t just add the median of arrays and insert into the binary search tree :)


struct node *SortedArraytoBST(int arr[],int start,int end)
{
struct node *root;
int mid;
if(start>end)
return NULL;
mid=start+end/2;
root=insert(a[mid])
root->left=SortedArraytoBst(arr,start,mid-1);
root->right=SortedArraytoBst(arr,mid+1,end);
return root;
}