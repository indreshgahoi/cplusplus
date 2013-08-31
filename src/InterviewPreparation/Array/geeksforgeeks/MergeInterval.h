/*
 * MergeInterval.h
 *
 *  Created on: Apr 7, 2013
 *      Author: root
 */

#ifndef MERGEINTERVAL_H_
#define MERGEINTERVAL_H_

#include<vector>
#include <sstream>
struct Interval{
	int start;
	int end;

	bool operator<(const Interval &I2)const{
		if(start<I2.start) return true ;
		else return false;

	}

};

class MergeInterval {
public:
	MergeInterval();
	virtual ~MergeInterval();
	std::vector<Interval> mergeOverLapInterval(std::vector<Interval> intervals);
};

#endif /* MERGEINTERVAL_H_ */
