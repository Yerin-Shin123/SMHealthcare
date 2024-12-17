//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100           // Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50   // Maximum length of the name of exercise


// To declare the structure of the exercises
typedef struct{
   char exercise_name[MAX_EXERCISE_NAME_LEN];
   int calories_burned_per_minute;
}Exercise; // by yerin  creating a structure 

static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;

/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char*EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) {
        printf("No file for exercises. \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while (fscanf(file,"%s %d",exercise_list[exercise_list_size].exercise_name,&exercise_list[exercise_list_size].calories_burned_per_minute) != EOF) //by yerin
         
        if (exercise_list_size >= MAX_EXERCISES){
        	exercise_list_size++;
        	printf("Be careful! Reach to MAX_SIZE exercise.\n"); //present max size of exercise by yerin
            break;
      }
    }

    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
             2. enter the duration of the exercise
             3. enter the selected exercise and the total calories burned in the health data
*/

void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    for (i = 0; i < exercise_list_size; i++) {
        printf("%d. %s (%d Kcal burned per minute)\n", i + 1, exercise_list[i].exercise_name, exercise_list[i].calories_burned_per_minute);
} 
    printf("%d. Exit\n",exercise_list_size+1);//by yerin provide exercise option

    // ToCode: to enter the exercise to be chosen with exit option
    printf("Choose an exercise number(1-%d): ",exercise_list_size+1); // by yerin, choose exercise number
    scanf("%d", &choice);  
	 
    if (choice == exercise_list_size+1) {
        printf("Exit selected. No exercise recorded.\n"); //by yerin, if no choose please put exercise choice
        return;
    } 
	else if (choice < 1 || choice > exercise_list_size) {
        printf("Be careful! Invaild options choiced. Try again.\n"); 
        return;
    }
 
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise(in min): ");
    scanf("%d", &duration);
    if (duration <= 0) {
        printf("Be careful! Duration have to be positive number.\n"); // by yerin duration have to be positive
        return;
    }

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    int calories_burned = duration * exercise_list[choice - 1].calories_burned_per_minute;
    health_data->total_calories_burned+=calories_burned;
    
    printf("Today you consumed %d kcal while you exercising %s for %d minutes.\n",calories_burned, exercise_list[choice-1].exercise_name, duration); 
	//by yerin pm 12:12, present name of exercise and minutes and consumed calories
	    
}
