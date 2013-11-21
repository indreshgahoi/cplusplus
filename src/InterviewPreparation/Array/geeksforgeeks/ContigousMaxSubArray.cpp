/*
 * ContigousMaxSubArray.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/ContigousMaxSubArray.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 5, 2013
 *      Author: Indresh Gahoi
 */
class Solution {
public:
	int max(int a , int b) { return a > b ? a : b ; }

    /* this is Dp Solution */
	int maxSubArrayDp(int A[], int n) {

		int *M = new int[n];
		int res = A[0];
		M[0] = A[0] ;
		for(int i = 1 ; i < n ; i++){

			M[i] = max(M[i-1]+A[i],A[i]);
		}
		for(int i =1 ; i < n ; ++i){
			res = max(res,M[i]);
		}

		return res ;
	}
	// It's dp but take O(1) space Make Memory efficient
	int maxSubArray(int A[], int n) {


		int res , pre  ;
		res=pre=A[0] ;
		for(int i = 1 ; i < n ; ++i){

			pre = max (pre+A[i],A[i]);
			res = max(res,pre);
		}
		return res ;

	}
};
