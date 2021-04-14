#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "baseinfo.h"
#include "deleterecord.h"

void deleterecord(FILE *fp)
{
	struct employee emp;
    long int size = sizeof(emp);
	FILE *ft;
	system("cls");
	char empname[50];
	char contAnother = 'y';

	while (contAnother == 'y') 
	{
		printf("\nEnter employee name to delete : ");
		scanf("%s", empname);

		ft = fopen("temp.txt", "wb");
		rewind(fp);
		while (fread(&emp, size,1, fp)== 1)
		{
			if (strcmp(emp.name,empname)!= 0)
			{
				fwrite(&emp, size, 1, ft);
			}
		}

		fclose(fp);
		fclose(ft);
		remove("data.txt");
		rename("temp.txt", "data.txt");
		fp = fopen("data.txt", "rb+");

		printf("\nWant to delete another record (Y/N) :");
		fflush(stdin);
		contAnother = getchar();
	}
}
