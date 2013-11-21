/*
 * MergeTwoBStWithLimitedExtarSpace.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/MergeTwoBStWithLimitedExtarSpace.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 8, 2013
 *      Author: Indresh Gahoi
 */


/*
 *  Question :-
 *  Given two Binary Search Trees(BST), print the elements of both BSTs in sorted form. The expected time complexity is O(m+n) where m is the number of nodes in first tree and n is the number of nodes in second tree. Maximum allowed auxiliary space is O(height of the first tree + height of the second tree).

Examples:

First BST
       3
    /     \
   1       5
Second BST
    4
  /   \
2       6
Output: 1 2 3 4 5 6


First BST
          8
         / \
        2   10
       /
      1
Second BST
          5
         /
        3
       /
      0
Output: 0 1 2 3 5 8 10

Source: Google interview question

A similar question has been discussed earlier. Let us first discuss already discussed
 methods of the previous post which was for Balanced BSTs. The method 1 can be
 applied here also, but the time complexity will be O(n^2) in worst case.
 The method 2 can also be applied here, but the extra space required will be O(n)
  which violates the constraint given in this question. Method 3 can be applied here
   but the step 3 of method 3 can’t be done in O(n) for an unbalanced BST.

Thanks to Kumar for suggesting the following solution.

The idea is to use iterative inorder traversal. We use two auxiliary stacks for two
 BSTs. Since we need to print the elements in sorted form, whenever we get a smaller
 element from any of the trees, we print it. If the element is greater,
  then we push it back to stack for the next iteration
 *
 */




