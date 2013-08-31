/*
 * shared_memory.h
 *
 *  Created on: May 12, 2013
 *      Author: Indresh Gahoi
 */

#ifndef SHARED_MEMORY_H_
#define SHARED_MEMORY_H_

#define NOT_READY -1
#define FILLED 0
#define TAKEN 1

struct Memory{
	int status;
	int data[4];
};



#endif /* SHARED_MEMORY_H_ */
