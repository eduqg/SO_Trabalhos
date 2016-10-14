/*============================================================================*/
/*Name        : main.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the main*/
/*============================================================================*/

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

//Referencia: http://stackoverflow.com/questions/8436841/how-to-recursively-list-directories-in-c-on-linux
void listdir(const char *name, int level)
{
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name)))
        return;
    if (!(entry = readdir(dir)))
        return;

    do {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            int len = snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name);
            path[len] = 0;
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            printf("%*s[%s]\n", level*2, "", entry->d_name);
            listdir(path, level + 1);
        }
        else
            printf("%*s- %s\n", level*2, "", entry->d_name);
    } while (entry = readdir(dir));
    closedir(dir);
}


int main(int argc, char **argv)
{
	if(argc > 2)
	{
		printf("args 0: %s\n", argv[0]);
		printf("args 1: %s\n", argv[1]);
		printf("args 2: %s\n", argv[2]);

		listdir("/home/admin-lart/Documentos/FSO/SO_Trabalhos/T4", 0);
	}
	else
	{
		printf("Usage: %s <path> <string> <max_lines>\n", argv[0]);
		exit(-1);
	}


		
	return 0;
}
