/*
 * HexaDecimalTest.c
 *
 *  Created on: Jul 11, 2013
 *      Author: root
 */

#include <stdio.h>
#include <stdint.h>

#define debugu(x)  printf(#x"=%u\n",x);
int main()
{
	uint32_t a=(float) 0x100000000;

	debugu(a)
	return 0;
}



