#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	char str[256]="start";

  //define fifo variables to write and read

	int fifo_write,fifo_read;
//Infinite loop
	while(strcmp(str,"end")!=0)
	{

         //opening a pipeA to write-only mode ( We can use "O_RDWR" also")

		fifo_write=open("pipeA",O_WRONLY);

       // checking for opening a pipe and assigning a task to pipeA to write to process 2

		if(fifo_write<0)
			printf("\n error opening write pipe");
		else
		{
			printf("\n enter text:\n");
			gets(str);
			write(fifo_write,str,255*sizeof(char));
			close(fifo_write);
		}

        //opening a pipeB to read-only mode ( We can use "O_RDWR" also) 

		fifo_read=open("pipeB",O_RDONLY);

     // Checking for opening a pipe and assiging a task to pipeB to read from process 2
		if(fifo_read<0)
			printf("\n Error opening read pipe");
		else
		{
			read(fifo_read,str,255*sizeof(char));
			close(fifo_read);
			printf("\n%s",str);
		}
	}
}

