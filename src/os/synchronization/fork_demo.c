/*
 * fork_demo.c
 *
 *  Created on: May 4, 2013
 *      Author: Indresh Gahoi
 */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int a[100], i, child_sum=0, parent_sum=0, sum;
        FILE *fp;

	for (i=0; i<100; i++) a[i] = i;
	if (fork() == 0) {
		// This is child
		for (i=0; i<50; i++) child_sum += a[i];
		printf("Child saying: my sum is %d\n", child_sum);
		fp = fopen("child_result.txt", "w");
		fprintf(fp, "%d\n", child_sum);
		fclose(fp);
        }
        else {
		for (i=50; i<100; i++) parent_sum += a[i];
		printf("Parent saying: my sum is %d\n", parent_sum);
		// wait for child
		wait (NULL);
		// Read child result
		fp = fopen("child_result.txt", "r");
		fscanf(fp, "%d", &sum);
		fclose(fp);
                printf("Total sum: %d\n", sum+parent_sum);
	}
	return 0;
}



