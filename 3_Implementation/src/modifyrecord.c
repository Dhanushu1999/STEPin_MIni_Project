#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "baseinfo.h"
#include "modifyrecord.h"

void modifyrecord(FILE *fp)
{
	struct emp e;
    long int size = sizeof(e);
	system("cls");

	char empname[50];
	char another = 'y';

	while (another == 'y') 
	{
		printf("\nEnter employee name to modify : ");
		scanf("%s", empname);

		rewind(fp);

		// While File is open
		while (fread(&e, size, 1, fp) == 1) 
		{
			// Compare the employee name
			// with ename
			if (strcmp(e.name, empname) == 0) 
			{
				printf("\nEnter new name:");
				scanf("%s", e.name);
				printf("\nEnter new age :");
				scanf("%d", &e.age);
				printf("\nEnter new salary :");
				scanf("%f", &e.salary);
				printf("\nEnter new EMP-ID :");
				scanf("%d", &e.id);

				fseek(fp, -size, SEEK_CUR);
				fwrite(&e, size, 1, fp);
				break;
			}
		}

		// Ask for modifying another record
		printf("\nWant to modify another record (Y/N) :");
		fflush(stdin);
		scanf("%c", &another);
	}
}

