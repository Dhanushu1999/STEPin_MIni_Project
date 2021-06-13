#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "addrecord.h"
#include "baseinfo.h"

int addrecord(FILE *fp,struct  employee *emp,int temp)
{
	if(temp!=1)
	{
		//struct employee emp ;
        long int size = sizeof(struct employee);
	    fseek(fp, 0, SEEK_END);
	    char contAnother = 'y';
		

	    while (contAnother == 'y') 
		{
			char ch;
		    printf("\nEnter Name : ");
		    scanf("%s", emp->name);

		    printf("\nEnter Age : ");
		    scanf("%d", &emp->age);

		    printf("\nEnter Salary : ");
		    scanf("%f", &emp->salary);

		    printf("\nEnter EMP-ID : ");
		    scanf("%d", &emp->id);

		    fwrite(emp, size, 1, fp);

		    printf("\nWant to add another record (Y/N) : ");
		    while ((ch=(getchar()) )!= '\n');

		    scanf("%c", &contAnother);
		}
	}
	else
	{
		return 0;
	}

	
}