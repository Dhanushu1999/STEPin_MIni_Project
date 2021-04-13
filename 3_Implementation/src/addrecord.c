#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "addrecord.h"
#include "baseinfo.h"

void addrecord(FILE *fp)
{
	struct emp e;
    long int size = sizeof(e);
	fseek(fp, 0, SEEK_END);
	char another = 'y';

	while (another == 'y') {
		printf("\nEnter Name : ");
		scanf("%s", e.name);

		printf("\nEnter Age : ");
		scanf("%d", &e.age);

		printf("\nEnter Salary : ");
		scanf("%f", &e.salary);

		printf("\nEnter EMP-ID : ");
		scanf("%d", &e.id);

		fwrite(&e, size, 1, fp);

		printf("\nWant to add another record (Y/N) : ");
		fflush(stdin);

		scanf("%c", &another);
	}
}