#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int threeClosetSum(vector<int> &num, int S)
{
	int x,y,z;

 int min=999999;
 int size=num.size();
 sort(num.begin(),num.end());
 for(int i=0;i<size;i++)
 {

     int low=i+1;
     int high=size-1;
     while(low<high)
     {
    	 int a=num[low]+num[high]+num[i];
         if(a==S)
         {
         x=i,y=low,z=high;
         return a;
         }
         if(abs(a-S)<min)
         {
          x=i,y=low,z=high,min=abs(a-S);
         }
         if(a<S)
         {
          low++;
         }
         else
           high--;

     }


 }
  return num[x]+num[y]+num[z];
}

int main()
{   int t,s;
    cin>>t;
    cin>>s;
    while(t-->0){
    int n;cin>>n;num.push_back(n);
    }
   cout<<threeClosetSum(num,s);
    cout<<"\n elements are "<<num[x]<<" "<<num[y]<<" "<<num[z];
//  cin>>t;
    return 0;
}
