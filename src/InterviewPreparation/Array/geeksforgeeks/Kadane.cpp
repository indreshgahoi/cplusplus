/*
 * ContigousMaxSubArray.cpp

 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/ContigousMaxSubArray.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 5, 2013
 *      Author: Indresh Gahoi
 */

/*
 *  Circular Sub Array
 *
 *
Maximum circular subarray sum

Given n numbers (both +ve and -ve), arranged in a circle, fnd the maximum sum of consecutive number.

Examples:

Input: a[] = {8, -8, 9, -9, 10, -11, 12}
Output: 22 (12 + 8 - 8 + 9 - 9 + 10)

Input: a[] = {10, -3, -4, 7, 6, 5, -4, -1}
Output:  23 (7 + 6 + 5 - 4 -1 + 10)

Input: a[] = {-1, 40, -14, 7, 6, 5, -4, -1}
Output: 52 (7 + 6 + 5 - 4 - 1 - 1 + 40)

There can be two cases for the maximum sum:

Case 1: The elements that contribute to the maximum sum are arranged such that no wrapping is there.
Examples: {-10, 2, -1, 5}, {-2, 4, -1, 4, -1}. In this case, Kadane’s algorithm will produce the result.

Case 2: The elements which contribute to the maximum sum are arranged such that wrapping is there.
 Examples: {10, -12, 11}, {12, -5, 4, -8, 11}

 In this case, we change wrapping to non-wrapping. Let us see how
 Wrapping of contributing elements implies non wrapping of non contributing elements,
  so find out the sum of non contributing elements and subtract this sum from the total sum.
   To find out the sum of non contributing, invert sign of each element and then run Kadane’s algorithm.
Our array is like a ring and we have to eliminate the maximum continuous negative that implies maximum continuous positive in the inverted arrays.
 *
 *
 *
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


	int maxCircularSum (int a[], int n)
	{
	   // Case 1: get the maximum sum using standard kadane's algorithm
	   int max_kadane = maxSubArray(a, n);

	   // Case 2: Now find the maximum sum that includes corner elements.
	   int max_wrap  =  0, i;
	   for(i=0; i<n; i++)
	   {
	        max_wrap += a[i]; // Calculate array-sum
	        a[i] = -a[i];  // invert the array (change sign)
	   }

	   // max sum with corner elements will be:
	   // array-sum - (-max subarray sum of inverted array)
	   max_wrap = max_wrap + maxSubArray(a, n);

	   // The maximum circular sum will be maximum of two sums
	   return (max_wrap > max_kadane)? max_wrap: max_kadane;
	}



// Utility functions to get minimum of two integers
int min (int x, int y) {return x < y? x : y; }




/* Returns the product of max product subarray.  Assumes that the
   given array always has a subarray with product more than 1 */
int maxSubarrayProduct(int arr[], int n)
{
    // max positive product ending at the current position
    int max_ending_here = 1;

    // min negative product ending at the current position
    int min_ending_here = 1;

    // Initialize overall max product
    int max_so_far = 1;

    /* Traverse throught the array. Following values are maintained after the ith iteration:
       max_ending_here is always 1 or some positive product ending with arr[i]
       min_ending_here is always 1 or some negative product ending with arr[i] */
    for (int i = 0; i < n; i++)
    {
        /* If this element is positive, update max_ending_here. Update
           min_ending_here only if min_ending_here is negative */
        if (arr[i] > 0)
        {
            max_ending_here = max_ending_here*arr[i];
            min_ending_here = min (min_ending_here * arr[i], 1);
        }

        /* If this element is 0, then the maximum product cannot
           end here, make both max_ending_here and min_ending_here 0
           Assumption: Output is alway greater than or equal to 1. */
        else if (arr[i] == 0)
        {
            max_ending_here = 1;
            min_ending_here = 1;
        }

        /* If element is negative. This is tricky
           max_ending_here can either be 1 or positive. min_ending_here can either be 1
           or negative.
           next min_ending_here will always be prev. max_ending_here * arr[i]
           next max_ending_here will be 1 if prev min_ending_here is 1, otherwise
           next max_ending_here will be prev min_ending_here * arr[i]

           */
        else
        {
            int temp = max_ending_here;
            max_ending_here = max (min_ending_here * arr[i], 1);
            min_ending_here = temp * arr[i];
        }

        // update max_so_far, if needed
        if (max_so_far <  max_ending_here)
          max_so_far  =  max_ending_here;
    }

    return max_so_far;
}


};




class CircullarSubArray
{

public :
	int Kadane(int A[] , int size)
	{
		int maxSum = A[0] ;
		int start = 0 ;
		int end = 0 ;
		int localStart = 0 ;
		int localSum = A[0] ;
		for(int i = 1; i < size ;++i)
		{
			if(localSum < 0)
			{
				localSum = A[i] ;
				localStart  = i ;
			}
			else
			{
				localSum +=A[i] ;
			}
			if(localSum > maxSum)
			{
				maxSum = localSum ;
				start = localStart ;
				end = i ;
			}
		}
		return maxSum ;
	}

	int maxCircullarSum(int A[] , int n)
	{
		int maxSum = Kadane(A,n) ;

		int totalSum = 0 ;

		for(int i = 0 ; i < n ; ++i)
		{
			totalSum+=A[i] ;
			A[i] = - A[i] ;
		}

		int BoundarySum = totalSum + Kadane(A,n) ;

		return max(BoundarySum,maxSum) ;
	}
};























