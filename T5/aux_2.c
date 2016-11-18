#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int printed_lines = 0;
int lines_before[10];
int lines_after[10];
pthread_mutex_t mutex;
pthread_t *threads;
int n;
int activated;

void *send_output(void *arg)
{
        int* idx = (int*)arg;
        lines_before[*idx] = printed_lines;
        int i;

        while(!activated) {
                usleep(500000);
                pthread_mutex_lock(&mutex);
                for (i=0; i < *idx+1; ++i) {
                        printf("%c", 'a'+*idx);
                }
                printf("\n");
                printed_lines++;
                pthread_mutex_unlock(&mutex);
        }

        lines_after[*idx] = printed_lines - lines_before[*idx] - 1;
        pthread_exit(0);
}

void handler(int idx)
{
        printf("Encerrando a aplicação. Aguardando a finalização de threads...\n");
        activated = 1;

        int i;
        for (i=0; i < n; ++i) {
                pthread_join(threads[i], NULL);
        }

        printf("Aplicação encerrada com sucesso!\nEstatísticas:\n");
        for (i=0; i < n; ++i) {
                printf("thread %d: %d linhas\n", i+1, lines_after[i]);
        }
}

int main(int argc, char const *argv[])
{
        if (argc < 2) {
                printf("You need at least one parameter, and the first must be a number.\n");
                return 0;
        } else {
                if (!(argv[1][0]>='0' && argv[1][0]<='9')) {
                        printf("The first argument must be a number.\n");
                        return 0;
                }
        }
        n = atoi(argv[1]);
        if (n < 1) {
                printf("The first argument must be higher than zero.\n");
                return 0;
        }

        activated = 0;

        memset(lines_before, 0, sizeof lines_before);
        memset(lines_after, 0, sizeof lines_after);
        signal(SIGINT, handler);

        n = n > 10 ? 10 : n; // n = min(10, n);

        threads = malloc(sizeof(pthread_t)*n);

        int elements[10], i;
        for (i=0; i < 10; ++i) {
                elements[i] = i;
        }

        for (i=0; i < n; ++i) {
                pthread_create(&threads[i], NULL, send_output, &elements[i]);
        }

        // while for the handler to continue
        while (!activated) {}

        // free threads
        free(threads);
        return 0;
}