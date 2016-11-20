/*============================================================================*/
/*Name        : q01.c*/
/*Author      : Eduardo Gomes and Miguel Pimentel*/
/*Version     :*/
/*Copyright   :*/
/*Description : Program that shoots n thrads( 1, 10) and display the position of character correspondent to alphabet*/
/*============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

typedef struct Args ARGS;

struct Args
{
    char character;
    int printed_lines;
    int index;
};


void stop_threads(int aux);
void* print_thread(void* args);
char* thread_output(int index, char value);
void destroy(pthread_t* threads, ARGS* args);
void print_stats(pthread_t* threads, int number_of_threads, ARGS* args);


pthread_mutex_t lock;
int is_actived = 1;


int main(int argc, char **argv)
{
    int number_of_threads = atoi(argv[1]);

    if(argc != 2 || number_of_threads > 10 || number_of_threads == 0)
    {
        printf("Usage: %s <number_of_threads>\n\n", argv[0]);
        printf("Ps: The number of threads must be grater than 0 and smaller than or equal to 10.\n");
        exit(1);
    }

    pthread_t* threads = (pthread_t *) calloc(number_of_threads, sizeof(pthread_t));
    ARGS* args = (ARGS *) calloc(number_of_threads, sizeof(ARGS));

    //Send a signal SIGINT and stop application with a ctrl + c
    signal(SIGINT, stop_threads);
    
    for(int i = 0; i < number_of_threads; ++i)
    {         
        args[i].character = 'a' + i;        
        args[i].index = i;

        pthread_create(&(threads[i]), NULL, &print_thread, &args[i]); 
    }

    print_stats( threads, number_of_threads, args);

    destroy(threads, args);

    return 0;
}


void print_stats(pthread_t* threads, int number_of_threads, ARGS* args)
{

    for(int i = 0; i < number_of_threads; ++i)
         pthread_join(threads[i], NULL);

    printf("Aplicação encerrada com sucesso!\n");
    printf("Estatísticas:\n");

    for(int i = 0; i < number_of_threads; ++i)
        printf("thread %d: %d linhas\n", i + 1, args[i].printed_lines);

}

void* print_thread(void* args)
{
    ARGS* aux = (ARGS *) args;

    int printed_line = aux -> printed_lines;
    int index =  aux -> index;
    char c = aux -> character;

    while(is_actived)
    {
        //Lock a thread using a mutex
        pthread_mutex_lock(&lock);
        
        if(!is_actived)
        {
            pthread_mutex_unlock(&lock);
            break;
        }

        printf("%s\n", thread_output(index, c));       
        usleep(500000);

        //Unlock a thread using a mutex
        pthread_mutex_unlock(&lock);        
        
        usleep(1);
        printed_line++;
    }

    aux -> printed_lines = printed_line;

    return args;
}

void stop_threads(int aux)
{
    printf("Encerrando a aplicação. Aguardando finalização de threads....\n");
    is_actived = 0;
}

char* thread_output(int index, char value)
{
    char *thread_expression;
    thread_expression = (char *) calloc((index + 1), sizeof(char));
    
    for(int i = 0; i < index + 1; ++i)
        thread_expression[i] = value;
     
    return thread_expression;
}

void destroy(pthread_t* threads, ARGS* args)
{
    free(threads);        
    free(args);
}

