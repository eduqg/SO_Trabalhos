/*============================================================================*/
/*Name        : main.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the main*/
/*============================================================================*/

#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <utime.h> 
#include <sys/time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
 
#define BUF_SIZE 8192

void copy_file(int argc, char** argv)
{
 
    int input_fd, output_fd;    /* Input and output file descriptors */
    ssize_t ret_in, ret_out;    /* Number of bytes returned by read() and write() */
    char buffer[BUF_SIZE];      /* Character buffer */
 
    /* Are src and dest file name arguments missing */
    if(argc != 2){
        printf ("Usage: %s file1 file2", argv[0]);
        return 1;
    }
 	
    /* Create input file descriptor */
    input_fd = open(argv [1], O_RDONLY);
    if (input_fd == -1) {
            perror ("open");
            return 2;
    }
 
    /* Create output file descriptor */
    output_fd = open(strcat(argv[1], ".bkp"), O_WRONLY | O_CREAT, 0644);
    if(output_fd == -1){
        perror("open");
        return 3;
    }
 
    /* Copy process */
    while((ret_in = read (input_fd, &buffer, BUF_SIZE)) > 0){
            ret_out = write (output_fd, &buffer, (ssize_t) ret_in);
            if(ret_out != ret_in){
                /* Write error */
                perror("write");
                return 4;
            }
    }
 
    /* Close file descriptors */
    close (input_fd);
    close (output_fd);
 
    return (EXIT_SUCCESS);
}


int main(int argc, char **argv)
{


	copy_file(argc, argv);

	/*
	if(argc == 2)
	{	

	    struct stat file_info;
	    stat(argv[1], &file_info);
	    struct tm* timeinfo = localtime(&file_info.st_ctime); // or gmtime() depending on what you want
	    printf("File time and date: %s", asctime(timeinfo));
	    //utimes(argv[1], )

	}
	else
		printf("ERROR: Usage %s file_name\n", argv[0]);
	
	*/

    return 0;
}

