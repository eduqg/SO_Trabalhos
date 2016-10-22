/*============================================================================*/
/*Name        : main.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the main*/
/*============================================================================*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <utime.h>
#include <unistd.h> 
#include <errno.h>

#define BUF_SIZE 8192

void copy_file(char** argv);
void file_info(struct stat file);



int main(int argc, char *argv[])
{
        if(argc != 3)
        {
                printf("Usage: ./q01 <file_name> <YYYYMMDDHHmm>\n");
                exit(1);
        }

        char* file_name = argv[1];
        char* datetime = argv[2];
 
        copy_file(argv);
        

        struct stat file;
        stat(file_name, &file);

        printf("\t\t\tFile info (before any modifications)\n\n");
        
        file_info(file);

        time_t file_datetime = time(NULL);
        struct tm* new_datetime = localtime(&file_datetime);
       
        char* new_year = (char *) calloc(5, sizeof(char));
        new_year = strncpy(new_year, datetime, 4);
        new_year[4] = '\0';
        
        char* new_month = (char *) calloc(3, sizeof(char));
        new_month = strncpy(new_month, datetime + 4, 2);
        new_month[2] = '\0';
        
        
        char* new_day = (char *) calloc(3, sizeof(char));
        new_day = strncpy(new_day, datetime + 6, 2);
        new_day[2] = '\0';
        
        char* new_hour = (char *) calloc(3, sizeof(char));
        new_hour = strncpy(new_hour, datetime + 8, 2);
        new_hour[2] = '\0';
        
        char* new_minutes = (char *) calloc(3, sizeof(char));
        new_minutes = strncpy(new_minutes, datetime + 10, 2);
        new_minutes[2] = '\0';
        
        new_datetime -> tm_year  = atoi(new_year) - 1900;
        new_datetime -> tm_mon = atoi(new_month) - 1;
        new_datetime -> tm_mday = atoi(new_day);
        new_datetime -> tm_yday = atoi(new_day) * atoi(new_month);
        new_datetime -> tm_hour = atoi(new_hour);
        new_datetime -> tm_min = atoi(new_minutes);
 
        mktime(new_datetime);
        
        struct utimbuf time_buf;
        
        time_buf.actime = mktime(new_datetime);
        time_buf.modtime = mktime(new_datetime);
        
        utime(file_name, &time_buf);
        
        stat(file_name, &file);

        printf("\n\n\t\t\tFile info (after modifications)\n\n");
        
        file_info(file);

        free(new_year);
        free(new_month);
        free(new_day);
        free(new_hour);
        free(new_minutes);

        
        return 0;
}


void copy_file(char** argv)
{   
 
        int input_file, output_file;    
        ssize_t ret_in, ret_out;        
        char buffer[BUF_SIZE];          


        input_file = open(argv[1], O_RDONLY);
        if (input_file == -1) 
        {
                perror ("open");
                exit(-1);
        }

        char* aux = (char *) calloc(strlen(argv[1]), sizeof(char));
        char* temp = argv[1];

        for(int  i = 0; temp[i] != '.'; ++i)
                aux[i] = temp[i];

  
        strcat(aux, ".bkp");

        output_file = open(aux, O_WRONLY | O_CREAT, 0644);
        
        if(output_file == -1)
        {
                perror("open");
                exit(-1);
        }
 
        while((ret_in = read (input_file, &buffer, BUF_SIZE)) > 0)
        {
                ret_out = write (output_file, &buffer, (ssize_t) ret_in);
                
                if(ret_out != ret_in)
                {
                        perror("write");
                        exit(-1);
                }
        }

        close (input_file);
        close (output_file);

}

void file_info(struct stat file)
{
        printf("Last Modification time: %s", ctime(&file.st_mtime));
        printf("Last acess time: %s", ctime(&file.st_atime));
}
