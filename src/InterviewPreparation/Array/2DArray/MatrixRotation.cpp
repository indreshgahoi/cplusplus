/*
 * MatrixRotation.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/MatrixRotation.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 13, 2013
 *      Author: Indresh Gahoi
 */



#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#define HASH_SIZE 128
using namespace std ;

/*  Square matrix (In Place)Rotation clock wise
 *  layer by Approach
 *
 */
template<class T>
ostream& operator<<(ostream &out,const vector<T>& V){
	out<<"[";
	for(typename vector<T>::const_iterator it=V.begin();it!=V.end();it++){
	 out<<" "<<*it;
	}
	out<<"]"<<endl;
	return out;
}
/*
 *  Squre Matrin Layer vise rotation
 *
 *
 */
void rotate(vector<vector<int> > &Mat)
{
	int size = Mat.size();

	for(int layer = 0 ; layer < size/2 ; ++layer)
	{
		int first = layer ;
		int last = size-1-first;
		/* first point first row first column
		 * last point last row last column
		 */
		for(int i = first ; i < last ; ++i) /* traverse first to last column*/
		{
			int offset = i - first ;
			int top = Mat[first][i] ;
			//left top
			Mat[first][i] = Mat[last-offset][first];
			// left Bottom
			Mat[last-offset][first] = Mat[last][last-offset];
			// right Bottom
			Mat[last-offset][last] = Mat[i][last];
			// right Top
			Mat[i][last] = top ;

		}
	}
}



/*
 *  To Turn Matrix 90 degree 90 degree (m *n )
 *   then First transpose the Matrix
 *   then reverse the column
 *
 */


// Non-square matrix transpose of matrix of size r x c and base address A
void MatrixInplaceTranspose(vector<vector<int> > &Mat)
{
	int row = Mat.size(),col = Mat[0].size(); ;
	int size = row * col-1 ;
	bitset<HASH_SIZE> bit;

	bit.reset();
	bit[0] = bit[size] = 1;
	int i = 1;
	int t = Mat[i/col][i % col] ;
	int start;
	int next ;
	while( i < size)
	{
		start = i ;
		t = Mat[i/col][i % col] ;
		do
		{

			next = (i*row)%size;
			swap(Mat[next%col][next/col],t);
			bit[i] = 1 ;
			i = next;

		}while(start != i);

		for(i = 1 ; i < size && bit[i];++i);
	}

}
/*
 *  Turn Matrix 90 clock using extra buffer
 *
 */
vector<vector<int> >& rotate1(vector< vector<int> > &mat)
{
	vector< vector<int> > *dest = new vector<vector<int> >(mat[0].size(),vector<int>(mat.size()));

	int m = mat.size();
	int n = mat[0].size();

	for(int i = 0 ; i < m ; ++i)
		for(int j = 0 ; j < n ; ++j){
			(*dest)[j][m-1-i] =mat[i][j] ;
		}
  return *dest;
}


int max(int x , int y) {return (x>y)? x: y ;}
void driver()
{
	int m, n ;
	vector<vector<int> > *mat ;
	cin>>m>>n ;
	int dim ;
	dim = max(m,n);
    mat = new vector<vector<int> >(dim,vector<int>(dim,0));
	for( int i = 0 ; i < m ; ++i)
	{
		vector<int> col ;
		for(int j = 0 ; j < n ; ++j)
		{
			int x ;
			cin>> x ;
			(*mat)[i][j] = x ;
		}
	}
	cout<<*mat<<"\n";
	MatrixInplaceTranspose(*mat);


	cout<<"\n\n";
	cout<<*mat<<"\n";
}



// Driver program to test above function
int main(void)
{

	driver();
//	int r = 5, c = 6;
//	int size = r*c;
//	int *A = new int[size];
//
//	for(int i = 0; i < size; i++)
//		A[i] = i+1;
//
//
//
//	delete[] A;

	return 0;
}

