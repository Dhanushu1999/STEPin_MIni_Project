/**
 * @file project_main.c
 * @author Anupam (you@domain.com)
 * @brief main function of the program
 * @version 0.1
 * @date 2021-04-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include"library_management.h"

/**
 * @brief main function of the project
 * 
 * @return int 
 */
int main(){
    int task, success, ID, new_member_id, new_date_of_issue[3], new_due_date[3];
    char new_status[10], new_member_first_name[10],new_member_last_name[10], new_title[20];
    
    test_values (*function_pointer_enter_new_record)(int , char []) = enter_new_record;
    test_values (*function_pointer_delete_record)(int) = delete_record;
    test_values (*function_pointer_view_a_record)(int) = view_a_record;
    test_values (*function_pointer_update_record)(int, char [], int [], int [], char [],char [], int) = update_record;
    test_values (*function_pointer_view_all_records)() = view_all_records;
    int (*function_pointer_calculate_fine)(int, int, int, int) = calculate_fine;
    
    printf("1. View all books\n2. Add a new book\n3. Find a book\n4. Update the status of a book\n5. Delete records of a book\n6. Calculate fine\n");
    printf("Enter the task number to perform one of the tasks\n");
    scanf("%d",&task);
    printf("\n");
    
    if(task == 1){
        success = function_pointer_view_all_records();
    }else if(task == 2){
        printf("Enter the ID and title of new book\n");
        scanf("%d\n",&ID);    
        fgets(new_title, 20, stdin);
        success = function_pointer_enter_new_record(ID, new_title);
    }else if(task == 3){
        printf("Enter the ID of the book to search\n");
        scanf("%d",&ID);
        success = function_pointer_view_a_record(ID);
    }else if(task == 4){
        printf("Enter the ID of the book to update\n");
        scanf("%d",&ID);
        success = function_pointer_view_a_record(ID);
        if(success == 1){

            printf("Enter new status\n");
            scanf("%s", new_status);

            printf("Enter new date of issue\n");
            printf("date(dd): ");
            scanf("%d", &new_date_of_issue[0]);
            printf("month(mm): ");
            scanf("%d", &new_date_of_issue[1]);
            printf("year(yyyy): ");
            scanf("%d", &new_date_of_issue[2]);
            
            printf("Enter new due date\n");
            printf("date(dd): ");
            scanf("%d", &new_due_date[0]);
            printf("month(mm): ");
            scanf("%d", &new_due_date[1]);
            printf("year(yyyy): ");
            scanf("%d", &new_due_date[2]);
            
            printf("Enter first name of member\n");
            scanf("%s", new_member_first_name);
            
            printf("Enter last name of member\n");
            scanf("%s", new_member_last_name);
            
            printf("Enter member ID\n");
            scanf("%d", &new_member_id);
            
            success = function_pointer_update_record(ID, new_status, new_date_of_issue, new_due_date, new_member_first_name,new_member_last_name, new_member_id);
        }
    }else if (task==5){
        printf("Enter the ID of the book to delete\n");
        scanf("%d",&ID);
        success=function_pointer_delete_record(ID);
    }else if (task == 6) {
        printf("Enter the ID of the book to find it's fine\n");
        scanf("%d",&ID);
        success = function_pointer_view_a_record(ID);
        if(success == 1) {
            int t_date, t_month, t_year;
            printf("Enter today's date\ndate(dd):");
            scanf("%d", &t_date);
            printf("month(mm):");
            scanf("%d", &t_month);
            printf("year(yyyy):");
            scanf("%d", &t_year);
            int fine_to_pay = function_pointer_calculate_fine(ID, t_date, t_month, t_year);
            printf("Fine to be paid: %d Rs.\n", fine_to_pay);
        }

    }else{
        printf("Wrong input\n");
    }
    if(success == pass){
        printf("Operation successful\n");
    }else if(success == fail){
        printf("Operation unseccessful\n");
    }else{
        printf("Error condition\n");
    }
    return 0;
}