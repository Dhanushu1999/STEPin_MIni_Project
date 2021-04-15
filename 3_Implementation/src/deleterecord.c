#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "baseinfo.h"
#include "deleterecord.h"

int deleterecord(FILE *fp,int flag)
{
	if(flag!=1)
	{
	    struct employee emp;
        long int size = sizeof(emp);
	    FILE *ft;
	    system("cls");
	    char empname[50];
	    char contAnother = 'y';
	    int check;

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
			    if (strcmp(emp.name,empname)== 0)
			    {
				    check=1;
			    }
		    }

		    fclose(fp);
		    fclose(ft);
		    if(check!=1)
		    {
			    remove("temp.txt");
			    printf("Requested data does not exist\n");
		    }
		    else
		    {
			    remove("data.txt");
		        rename("temp.txt", "data.txt");
		    }
		    fp = fopen("data.txt", "rb+");

		    printf("\nWant to delete another record (Y/N) :");
		    fflush(stdin);
		    contAnother = getchar();
	    }
	}
	else
	{
		return 0;
	}
}
