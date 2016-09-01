#include<stdio.h>
void main()

{
	int f1,f2; // defining fifo variables.

	f1=mkfifo("pipeA",0600);//making fifo with name as pipeA and approving permissions.

	if(f1>0)
		printf("\n pipeA is not created");  // to check wheter the pipe is created or not
	else
		printf("\n pipeA is created");

	f2=mkfifo("pipeB",0600);//making fifo with name as pipeB and approving permissions (like pipeA).


	if(f2>0)                                        // to check whether the pipe is created or not.
		printf("\n pipeB is not created");
	else
                printf("\n pipeB is created\n");

}
