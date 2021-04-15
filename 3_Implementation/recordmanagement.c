/**
 * @file recordmanagement.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<errno.h>
#include "recordmanagement.h"



int main()
{
	FILE *fp;
	int user_choice;
	struct employee *emp = (struct employee *)calloc(1, sizeof(struct employee));

	// opening the file
	fp = fopen("data.txt", "rb+");

	// showing error if file is
	// unable to open.
	if (fp == NULL) 
	{
		fp = fopen("data.txt", "wb+");
		if (fp == NULL) 
		{
			fprintf(stderr, "Error opening file: %s\n", strerror( errno ));
			exit(1);
		}
	}

	system("Color 0F");
	printf("\n\n\n\n\t\t=====================================================");
	printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\t\t=====================================================");
	printf("\n\t\t[|||||||||||||||| EMPLOYEE RECORD ||||||||||||||||]\t");
	printf("\n\t\t=====================================================");
	printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\t\t===================================================\n");

	system("pause");

	while (1) 
	{
		// Clearing console and asking the5
		// user for input
		system("cls");
		
		//printf("\n 1. ADD RECORD\n");
		printf("\n 1. ADD RECORD\n");
		printf("\n 2. DELETE RECORD\n");
		printf("\n 3. DISPLAY RECORDS\n");
		printf("\n 4. MODIFY RECORD\n");
		printf("\n 5. EXIT\n");
		printf("\nENTER YOUR CHOICE...\n");
		fflush(stdin);
		scanf("%d", &user_choice);

		// Switch Case
		switch (user_choice) 
		{
		case 1:

			// Add the records
			addrecord(fp,emp,0);
			free(emp);
			break;

		case 2:

			// Delete the records
			deleterecord(fp,0);
			break;

		case 3:

			// Display the records
			displayrecord(fp,0);
			break;

		case 4:

			// Modify the records
			modifyrecord(fp,0);
			break;

		case 5:
			fclose(fp);
			exit(0);
			break;

		default:
			printf("\nINVALID CHOICE...\n");
		}
	}

	return 0;
}