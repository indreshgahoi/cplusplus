// to implement the two stacks using only one array
// and u should not report the stack full till all the elements are full
// :)
//just easy algo
// take the first top as top1=-1 and top2=n
// just inszert tem as request comes if top1==top2
// just means the stack is full :)
struct stack
{
int Arr[100];
int top1;
int top2;
}s;

int isFull(struct stack s)
{
if(s.top1==s.top2)
return 1;
return 0;
}




