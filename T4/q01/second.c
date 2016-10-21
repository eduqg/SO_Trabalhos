#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <utime.h> 
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 8192

//system("cp -p argv[1] argv[1].bkp")
/*
void copy_file(char** argv)
{   
 
    int input_file, output_file;    
    ssize_t ret_in, ret_out;        
    char buffer[BUF_SIZE];          
 
    
    input_file = open(argv [1], O_RDONLY);
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
 
    while((ret_in = read (input_file, &buffer, BUF_SIZE)) > 0){
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

*/

void setDate(const char* dataStr, struct stat actual_time) // AAAAMMDDHHmm // format like MMDDYY
{
  char buf[3] = {0};

  strncpy(buf, dataStr + 0, 2);
  unsigned short month = atoi(buf);

  strncpy(buf, dataStr + 2, 2);
  unsigned short day = atoi(buf);

  strncpy(buf, dataStr + 4, 2);
  unsigned short year = atoi(buf);

  struct tm*  new_tm = localtime(&actual_time.st_ctime);
  

  if(tm_ptr)
  {
    new_tm  -> tm_mon  = month - 1;
    new_ptr -> tm_mday = day;
    new_ptr -> tm_year = year + (2000 - 1900);

    const struct timeval tv = {mktime(tm_ptr), 0};
    settimeofday(&tv, 0);
  }
}

int main(int argc, char** argv)
{

  struct stat old_time;
  struct stat actual_time;

  system("cp -p argv[1] argv[1].bkp");

  //Creating file BKP
   //copy_file(argv);

  //Changing Actual Timeinfo
  stat(argv[1], &actual_time);
  struct tm* timeinfo = localtime(&actual_time.st_ctime); 
  printf("Old time: %s\n", asctime(timeinfo));
 

  //Printing bkp info
  stat("main.bkp", &old_time);
  struct tm* old_timeinfo = localtime(&old_time.st_ctime); 
  printf("Old Time/Setted: %s\n", asctime(old_timeinfo));

  //Setting new date
  setDate(argv[2], actual_time);
  printf("New Time: %s\n", asctime(timeinfo));


  
  return 0;
}