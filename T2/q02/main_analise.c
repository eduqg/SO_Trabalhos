#include <stdlib.h>
#include <stdio.h>

void print_vector(int size, int vector[]){
    int i = 0;
    for(i = 0; i < size; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int* discover_biggest(int x[], int *w, int size){
    int i = 0, j = 0;

    for(i = 0; i < size; ++i){
            for(j = i + 1; j < size; ++j){
                if(x[i] < x[j]){
                    w[i] = 0;
                }
                if(x[i] > x[j]){
                    w[j] = 0;
                }

            }
        }

        return w;

}

int main(int argc, char **argv)
{


    if(argc > 2)
    {
        const int size = atoi(argv[1]);

        if(size > 100)
        {
            printf("ERROR: The limit of size vector is 100\n");
            exit(0);
        }
        int i = 0;
        int w_tam = 100;
        int x_tam = 100;

        int x[x_tam];
        int *w;

        w = (int*) calloc(w_tam, sizeof(int));

        printf("Number of input values = %d\n\n",size);
        printf("Input values x = ");
        for(i = 0; i < size; i++){
            x[i] = atoi(argv[i+2]);
        }
        print_vector(size, x);

        for(i = 0; i < size; i++){
            w[i]=1;
        }
        printf("After initialization w = ");
        print_vector(size, w);

        w = discover_biggest(x ,w , size);

        printf("\n");

        printf("After Step 2\n");
        printf("w = ");
        print_vector(size, w);

        for(i = 0; i< size; i++){
            if(w[i]==1){
                printf("Maximum: %d\n", x[i]);
                printf("Location: %d\n", i);
            }
        }


    }
    else
    {
        printf("Usage: %s <num_inputs> <num_1> ... <num_n>\n", argv[0]);

        exit(-1);

    }

    return 0;
}