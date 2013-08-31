/*
 * GrayCode.cpp
 *
 *  Created on: Mar 17, 2013
 *      Author: indresh
 */

#include <iostream>
#include <string>
#include<vector>
using namespace std;

/*
 * http://en.wikipedia.org/wiki/Gray_code
 * conversion from gray to binary
 * Let us suppose  i^(i/2)
 */

vector<int> grayCode(int n) {

	  vector<int> res;
	  int shifts=(1<<n);
	  for(int i=0;i<shifts;i++){
		  res.push_back(i^(i>>1));
	  }
	  return res;
    }
