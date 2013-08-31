/*
 * ContainerWithMostWater.cpp
 *
 *  Created on: Apr 9, 2013
 *      Author: root
 */

/* Given n non-negative integers a1, a2, ..., an, where each represents
 * a point at coordinate (i, ai). n vertical lines are drawn such that
 *  the two endpoints of line i is at (i, ai) and (i, 0).
 *  Find two lines, which together with x-axis forms a container,
 *  such that the container contains the most water.
    Note: You may not slant the container.
 *
 */

#include<constant.h>
int maxArea(vector<int> &height) {
      int area=0,temp=0;;
      int i=0,j=height.size()-1;
      while(i<j){
    	  temp=min(height[i],height[i]) *(j-i);
    	  if(area<temp)
    		  area=temp;
    	  if(height[i]<height[j])
    		  i++;
    	  else
    		  j--;
      }
   return area;
   }
