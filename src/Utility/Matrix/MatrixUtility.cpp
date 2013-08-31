/*
 * MatrixUtility.cpp
 *
 *  Created on: Dec 8, 2012
 *      Author: indresh
 */

#include<sstream>
#include<iostream>

typedef int Integer;

template <typename T>
class Matrix{
public:

 Matrix(int row,int col){
	 this->dx=row;
	 this->dy=col;
	 allocArrays();

 }
 Matrix(int row,int col,T val){
 	 this->dx=row;
 	 this->dy=col;
 	 allocArrays();
     set(val);
  }
 ~Matrix(){
	 for(int i=0;i<dx;i++)
		 delete[] data[i];
	 delete[] data;
 }
 void set(T val){
	 for(int i=0;i<dx;i++)
	 		   for(int j=0;j<dy;++j)
	 			   data[i][j]=val;
 }

 T& operator()(Integer x,Integer y){
	 return data[x][y];
 }

 Integer row(){
	 return this->dx;
 }
 Integer col(){
	 return this->dy;
 }
 friend std::ostream& operator<<(std::ostream& out,const Matrix & M){

	   for(int i=0;i<M.dx;i++){
		   for(int j=0;j<M.dy;++j)
			   out<<M.data[i][j]<<" ";
		   out<<std::endl;
	   }
	   out<<std::endl;
	  return out;
 }

private:
 T **data;
	Integer dx,dy;

 void allocArrays(){
	 data =new T*[dx];
	 for(int i=0;i<dx;i++)
		 data[i]=new T[dy];
 }
};



void spiralTraversal(){
	Matrix<int> M(5,7);

	int row=M.row(),col=M.col(),r=0,c=0;
	int val=0;

	int s,e;
	int curr_row,curr_col;

	while(r<=((row+1)/2)){

	curr_row=r;
	s=c;e=(col-c);
	while(s<e && curr_row<(row-r)){
		M(curr_row,s)=++val;
	  s++;
	 // std::cout<<"1 s="<<s<<" e="<<e<<" curr_row="<<curr_row<<" r="<<r<<" c="<<c<<std::endl;
	}
	//std::cout<<M;
	curr_col=col-c-1;
	s=r+1;e=(row-r);
	while(s<e && curr_col>=c){
		M(s,curr_col)=++val;
		s++;
		//std::cout<<"2 s="<<s<<" e="<<e<<" curr_row="<<curr_row<<" r="<<r<<" c="<<c<<std::endl;

	}
	//std::cout<<M;
	curr_row=(row-r-1);
	s=c;e=col-c-2;
	while(s<=e && curr_row>r){
	    M(curr_row,e)=++val;
		e--;
		//std::cout<<"3 s="<<s<<" e="<<e<<" curr_row="<<curr_row<<" r="<<r<<" c="<<c<<std::endl;
	}
	//std::cout<<M;
	curr_col=c;
	s=r+1;e=row-r-2;
	while(s<=e && curr_col<(col-c-1)){
		M(e,curr_col)=++val;
		e--;
		//std::cout<<"4 s="<<s<<" e="<<e<<" curr_row="<<curr_row<<" r="<<r<<" c="<<c<<std::endl;
	}
	r++;
    c++;
    std::cout<<M;
}


}

int main(){
	spiralTraversal();
	return 0;
}

