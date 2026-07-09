#include "grade_school.h"
#include <string.h>
#include <stdio.h>
bool add_student(roster_t *roster,char *name, uint8_t inp_grade)
{
    // roster_t result;
    // result.count = 1;
    // int len_string = strlen(name);
    // printf("add_student\n");
    // printf("%s\n",name);
    // printf("%i\n",inp_grade);
    // printf("%li\n",roster->count);
    // printf("%i\n",roster->students[1].grade);
    for (int i = 0; i < (int)roster->count; i++)
    {
        // printf("Checking dup: '%s' vs '%s' -> %d\n",roster->students[i].name,name,strcmp(roster->students[i].name, name));
        if (strcmp(roster->students[i].name,name) == 0)
        {
            // printf("DUPLICATE FOUND! Rejecting.\n");
            return false;
        }
    }

    if (roster->count == 0)
    {
        roster->students[roster->count].grade = inp_grade;
        strcpy(roster->students[roster->count].name,name);
        roster->count++;
    }
    // else if (inp_grade > roster->students[roster->count - 1].grade) 
    //     {
    //         roster->students[roster->count].grade = inp_grade;
    //         strcpy(roster->students[roster->count].name,name);
    //         roster->count++;
    //         }
    else {
    // All other cases: find position or append
    int insert_index = -1;
    
    for (int i = 0; i < (int)roster->count; i++) {
        if ((roster->students[i].grade > inp_grade) || 
            (roster->students[i].grade == inp_grade && strcmp(name, roster->students[i].name) < 0)) {
            insert_index = i;
            break;
        }
    }
    if (insert_index != -1) {

        for (int j = roster->count; j > insert_index; j--) {
            strcpy(roster->students[j].name, roster->students[j-1].name);
            roster->students[j].grade = roster->students[j-1].grade;
        }
        strcpy(roster->students[insert_index].name, name);
        roster->students[insert_index].grade = inp_grade;
    } 
        else 
        {
        strcpy(roster->students[roster->count].name, name);
        roster->students[roster->count].grade = inp_grade;
    }
    roster->count++;
}
    // printf("%s\n",roster->students[0].name);
    // printf("%i\n",roster->students[0].grade);
    // for (int i = 0; i < (int)roster->count; i++)
    // {
    //     printf("%s with grade %i\n",roster->students[i].name,roster->students[i].grade);
    // }
    // printf("%li\n",roster->count);
    return true;
}
void init_roster(roster_t *roster)
{
    // printf("init_roster\n");
    roster->count = 0;
    // char *s = "Babita";
     // len = strlen(s);
    // for (int i = 0; i < 6; i++)
    // {
        // roster->students[1].name[i] = s[i];
    // }
    // roster->students[1].name[0] = '\0';
    // printf("%li\n",roster->count);
    // printf("%i\n",roster->students[1].grade);
    // printf("name %s\n",roster->students[1].name);
    // printf("character %c\n",roster->students[1].name[4]);
    for (int i = 0; i < 20; i++)
    {
        roster->students[i].grade = 0;
        for (int j =0 ; j < 20; j++)
        {
            roster->students[i].name[j] = '\0';
        }
    }
    // printf("name %s\n",roster->students[1].name);
    // printf("character %c\n",roster->students[1].name[4]);
}
roster_t get_grade(roster_t *roster, uint8_t desired_grade)
{
    roster_t result;
    result.count = roster->count;
    printf("get_grade\n");
    int count = 0;
    for (int i = 0; i < (int)roster->count; i++)
    {
        // printf("%s\n",roster->students[i].name);
        if (desired_grade == roster->students[i].grade)
        {
            strcpy(result.students[count].name,roster->students[i].name);
            printf("%s\n",result.students[count].name);
            count++;
        }
    }
    // printf("%li\n",roster->count);
    // printf("%i\n",roster->students[1].grade);
    // printf("%i\n",desired_grade);
    result.count = count;
    return result;   
}