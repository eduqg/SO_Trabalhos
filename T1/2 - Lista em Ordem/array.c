void initialize(int* vector)
{
	int vector_length = 0;
	scanf("%d", &vector_length);
	vector = (int*) calloc(vector_length, sizeof(int));
}

void destroy(int* vector)
{
	free(vector);
}

void print_vector(int* vector)
{
	int counter = 0;
	for(counter  = 0; counter < vector_length; ++counter)
		printf("%d  ", &vector[counter]);

	printf("\n");
}
