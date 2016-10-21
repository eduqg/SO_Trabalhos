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


void copy_file(char** argv)
{
 
    int input_file, output_file;    /* Input and output file descriptors */
    ssize_t ret_in, ret_out;        /* Number of bytes returned by read() and write() */
    char buffer[BUF_SIZE];          /* Character buffer */
 
    /* Create input file descriptor */
    
    input_file = open(argv [1], O_RDONLY);
    if (input_file == -1) 
    {
            perror ("open");
            return 2;
    }
 

    //Setting a bkp with an appropriate name
 	char* aux = (char *) calloc(strlen(argv[1]), sizeof(char));
	char* temp = argv[1];

	for(int  i = 0; temp[i] != '.'; ++i)
		aux[i] = temp[i];

	
	strcat(aux, ".bkp");


    /* Create output file descriptor */
    output_file = open(aux, O_WRONLY | O_CREAT, 0644);
    if(output_file == -1)
    {
        perror("open");
        return 3;
    }
 
    /* Copy process */
    while((ret_in = read (input_file, &buffer, BUF_SIZE)) > 0){
            ret_out = write (output_file, &buffer, (ssize_t) ret_in);
            if(ret_out != ret_in)
            {
                /* Write error */
                perror("write");
                return 4;
            }
    }
 
    /* Close file descriptors */
    
    close (input_file);
    close (output_file);
 
    return (EXIT_SUCCESS);
}

void set_datetime(char* argv)
{
    char* new_datetime = argv;
    printf("\n%s\n", new_datetime);

    //Setting Years
    char* new_year = (char *) calloc(3, sizeof(char));
    new_year = strncpy(new_year, &new_datetime[0], 4);
    new_year[3] = '\0';
    time_t year = atoi(new_year);
    printf("%d\n", year);

    //Setting Month 
    char* new_month = (char *) calloc(2, sizeof(char));
    new_month = strncpy(new_year, &new_datetime[3], 2);
    new_month[2] = '\0' ;
    time_t month = atoi(new_month);
    printf("%d\n", month);

    //Setting day
    char* new_day = (char *) calloc(3, sizeof(char));
    new_day = strncpy(new_day, &new_datetime[0], 4);
    new_day[3] = '\0';
    time_t day = atoi(new_day);
    printf("%d\n", day);

    //Setting  Hour
    char* new_hour = (char *) calloc(5, sizeof(char));
    new_hour = strncpy(new_hour, &new_datetime[5], 2);
    new_hour[2] = '\0';
    time_t hour = atoi(new_hour);
    printf("%d\n", hour);

    //Setting minutes
    char* new_minutes = (char *) calloc(5, sizeof(char));
    new_minutes = strncpy(new_minutes, &new_datetime[5], 2);
    new_minutes[2] = '\0';
    time_t minutes = atoi(new_minutes);
    printf("%d\n", minutes);

    //struct tm  new_timeinfo;

}

int main(int argc, char **argv)
{



	
	if(argc == 2)
	{	
	    struct stat actual_time;
	    stat(argv[1], &actual_time);
	    struct tm* timeinfo = localtime(&actual_time.st_ctime); 
	    printf(" %s\n  ", asctime(timeinfo));
        set_datetime(argv[2]);
	}
	else
		printf("ERROR: Usage %s file_name\n", argv[0]);
	
	

    return 0;
}

