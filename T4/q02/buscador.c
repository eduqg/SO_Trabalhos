/*========================================*/
/*Name        : main.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Contains the main*/
/*========================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

#include <fcntl.h>

int times_to_print;

void print_content(char *file_path){
    FILE *myfile;
    myfile=fopen(file_path,"r");
    int j;
    char c;

    printf("Arquivo encontrado: %s\n", file_path);
    for(j = 0; j<30;j++){
        c= fgetc(myfile);
        if(c == EOF)
            break;
        printf("%c",c);
    }
    printf("\n\n");
    fclose(myfile);
}

//Referencia: http://stackoverflow.com/questions/
//8436841/how-to-recursively-list-directories-in-c-on-linux
void listdir(const char *name, int level, char *test_name, int times_to_print)
{
    DIR *dir;
    struct dirent *entry;
    char file_path[1024];

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
            //printf("%*s[%s]\n", level*2, "", entry->d_name);
            listdir(path, level + 1, test_name, times_to_print);
        }
        else{
            //printf("%*s- %s\n", level*2, "", entry->d_name);
            if(strstr(entry->d_name, test_name) != NULL){
                strcpy(file_path, name);
                strcat(file_path, "/");
                strcat(file_path, entry->d_name);
                print_content(file_path);
                times_to_print--;
                printf("-----Times to print: %d\n", times_to_print);
            }
            if(times_to_print==0){
                 closedir(dir);
                 return;
            }
        }
    }while(entry = readdir(dir));
    closedir(dir);
}



int main(int argc, char **argv)
{
	if(argc > 2)
	{

                printf("Origem: %s\n", argv[1]);
                printf("Nome da substring: %s\n", argv[2]);
                printf("Quantidade de arquivos a serem lidos: %s\n\n", argv[3]);

                times_to_print = atoi(argv[3]);
                listdir(argv[1], 0, argv[2], times_to_print);
	}
	else
	{
		printf("Usage: %s <path> <string> <max_lines>\n", argv[0]);
		exit(-1);
	}

	return 0;
}
