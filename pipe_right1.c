#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
void main()
{

	char str[256]="start";

   //define fifo variables for process 2.

	int fifo_read,fifo_write;

   //infinte loop

	while(strcmp(str,"end")!=0)
	{

           //open pipeA in read only mode ( which is exactly opposite to process 1.)

		fifo_read=open("pipeA",O_RDONLY);

       // Checking opening a pipe and assigning a task to read from process 1. 
		if(fifo_read<0)
			printf("\n error opening read pipe");
		else
		{
			read(fifo_read,str,255*sizeof(char));
			close(fifo_read);
			printf("\n%s",str);
		}

     //open pepeB in write only mode ( which is opposite to process 1.)

		fifo_write=open("pipeB",O_WRONLY);

     // Checking opening a pipe and assinging a task to write to process1.
		if(fifo_write<0)
			printf("\nerror opening write pipe");
		else
		{
			printf("\nenter text:\n");
			gets(str);
			write(fifo_write,str,255*sizeof(char));
			close(fifo_write);
		}
	}
}


