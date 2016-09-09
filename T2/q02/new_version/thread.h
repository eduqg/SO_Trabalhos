typedef struct args ARGS;

struct args
{
	int i;
	int j;
	int i_value;
	int j_value;
	int *w;
	int *x;
};

int* initialize_vector(int size, char **input);

void print_vector(int size, int *vector);

void destroy(int *v);

int* set_vector(int size, int *x);

void* set_one(void* args);

int* calculate_bigger(int size, ARGS *args);

void* compare_values(void* args);



