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


void copy_file(char** argv)
{   
 
        int input_file, output_file;    
        ssize_t ret_in, ret_out;        
        char buffer[BUF_SIZE];          


        input_file = open(argv[1], O_RDONLY);
        if (input_file == -1) 
        {
                perror ("open");
                return 2;
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
                return 3;
        }
 
        while((ret_in = read (input_file, &buffer, BUF_SIZE)) > 0)
        {
                ret_out = write (output_file, &buffer, (ssize_t) ret_in);
                
                if(ret_out != ret_in)
                {
                        perror("write");
                        return 4;
                }
        }

        close (input_file);
        close (output_file);

        return (EXIT_SUCCESS);
}

void output(struct stat fs)
{
        printf("Last Modification time: %s", ctime(&fs.st_mtime));
        printf("Last acess time: %s", ctime(&fs.st_atime));
        printf("Permissions: ");
        printf((S_ISDIR(fs.st_mode))  ? "d" : "-");
        printf((fs.st_mode & S_IRUSR) ? "r" : "-");
        printf((fs.st_mode & S_IWUSR) ? "w" : "-");
        printf((fs.st_mode & S_IXUSR) ? "x" : "-");
        printf((fs.st_mode & S_IRGRP) ? "r" : "-");
        printf((fs.st_mode & S_IWGRP) ? "w" : "-");
        printf((fs.st_mode & S_IXGRP) ? "x" : "-");
        printf((fs.st_mode & S_IROTH) ? "r" : "-");
        printf((fs.st_mode & S_IWOTH) ? "w" : "-");
        printf((fs.st_mode & S_IXOTH) ? "x" : "-");
        printf("\n");

}

int main(int argc, char *argv[])
{
        char* file_name = argv[1];
        char* datetime = argv[2];

        copy_file(argv);
        

        struct stat file;
        stat(file_name, &file);

        printf("\t\t\tFile info (before any modifications):\n\n");
        output(file);

        time_t t = time(NULL);
        struct tm* new_datetime = localtime(&t);
        char year[4], month[2], day[2], hour[2], minutes[2];
        
        for (int i=0; i < 4; ++i) 
        {
                year[i]= datetime[i];
        }
        
        for (int i=0; i < 2; ++i) 
        {
                day[i]= datetime[i + 6];
                hour[i]= datetime[i + 8];
                minutes[i]= datetime[i + 10];
                month[i]= datetime[i + 4];
        }

        new_datetime -> tm_min = atoi(minutes);
        new_datetime -> tm_hour = atoi(hour);
        new_datetime -> tm_mday = atoi(day);
        new_datetime -> tm_mon = atoi(month) - 1;
        new_datetime -> tm_year  = atoi(year) - 1900;
        new_datetime -> tm_yday = atoi(day) * atoi(month);
        
        mktime(new_datetime);
        
        printf("%s\n", asctime(new_datetime));

        struct utimbuf time_buf;
        
        time_buf.actime = mktime(new_datetime);
        time_buf.modtime = mktime(new_datetime);
        
        utime(file_name, &time_buf);
        stat(file_name, &file);

        printf("\n\n\t\t\tFile info (after modifications)\n\n");
        printf("Last Modification time: %s", ctime(&file.st_mtime));
        printf("Last acess time: %s", ctime(&file.st_atime));

        
        return 0;
}