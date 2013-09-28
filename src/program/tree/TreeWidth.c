// a use of Breadth first serach to find the width of a tree.



int TreeWidth(struct Node *r)
{
	struct Node *temp;
	int max=0,c=0;
	if(!r)
		return 0;
	enquee1(r);
	while(front1!=NULL || front2!=NULL)
	{
		c=0;
		while(front1!=NULL)
		{
			temp=dequee1();
			c++;
			if(temp->left)
			{

				enquee2(temp->left);
			}
			if(temp->right)
			{
				enquee2(temp->right);
			}
		}
		if(c>max)
			max=c;
		c=0;
		while(front!=NULL)
		{
			temp=dequee2();
			c++;
			if(temp->left)
			{
				c++;
				enquee1(temp->left);
			}
			if(temp->right)
			{
				enquee(temp->right);
			}
		}
		if(c>max)
			max=c;
	}

	return(max);

}
