#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "baseinfo.h"
#include "deleterecord.h"

void deleterecord()
{
	struct emp e;
    long int size = sizeof(e);
	FILE *fp,*ft;
	system("cls");
	char empname[50];
	char another = 'y';

	while (another == 'y') 
	{
		printf("\nEnter employee name to delete : ");
		scanf("%s", empname);

		ft = fopen("temp.txt", "wb");
		rewind(fp);

		while (fread(&e, size,1, fp)== 1)
		{
			if (strcmp(e.name,empname)!= 0)
			{
				fwrite(&e, size, 1, ft);
			}
		}

		fclose(fp);
		fclose(ft);
		remove("data.txt");
		rename("temp.txt", "data.txt");
		fp = fopen("data.txt", "rb+");

		printf("\nWant to delete another record (Y/N) :");
		fflush(stdin);
		another = getche();
	}
}
