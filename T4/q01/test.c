#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_datetime(char* argv)
{
	char* new_datetime = argv;
	printf("%s\n", new_datetime);

	//Setting Years
	char* new_year = (char *) calloc(3, sizeof(char));
	new_year = strncpy(new_year, &new_datetime[0], 4);
	new_year[3] = '\0';
	int year = atoi(new_year);
	printf("%d\n", year);

	//Setting Month 
	char* new_month = (char *) calloc(2, sizeof(char));
	new_month = strncpy(new_year, &new_datetime[3], 2);
	new_month[2] = '\0'	;
	int month = atoi(new_month);
	printf("%d\n", month);

	//Setting day
	char* new_day = (char *) calloc(3, sizeof(char));
	new_day = strncpy(new_day, &new_datetime[0], 4);
	new_day[3] = '\0';
	int day = atoi(new_day);
	printf("%d\n", day);

	//Setting  Hour
	char* new_hour = (char *) calloc(5, sizeof(char));
	new_hour = strncpy(new_hour, &new_datetime[5], 2);
	new_hour[2] = '\0';
	int hour = atoi(new_hour);
	printf("%d\n", hour);

	//Setting minutes
	char* new_minutes = (char *) calloc(5, sizeof(char));
	new_minutes = strncpy(new_minutes, &new_datetime[5], 2);
	new_minutes[2] = '\0';
	int minutes = atoi(new_minutes);
	printf("%d\n", minutes);

}

int main(int argc, char **argv)
{

	set_datetime(argv[1]);

	return 0;
}


