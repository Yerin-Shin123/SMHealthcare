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

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


typedef struct{
    char name[MAX_EXERCISE_NAME_LEN]; // by yerin, exercise name
    int calories_per_min; // by yerin, calories burned per minute
}Exercise; 

// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;


/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while (fscanf(file, "%s %d", exercise_list[exercise_list_size].name, &exercise_list[exercise_list_size].calories_per_min) == 2) {
    	//by yerin, bring exercise information from file, and put exercise_list array
    	exercise_list_size++;  
        if (exercise_list_size >= MAX_EXERCISES){
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
    for (i = 0; i < exercise_list_size; i++) 
	{
        printf("%d. %s, %d calories/min\n", i + 1, exercise_list[i].name, exercise_list[i].calories_per_min);
        //by yerin, print index (i+1), exercise name, the exercise's calories burned per minute
    }
    printf("0. Exit\n"); //by yerin, print exit option

    // ToCode: to enter the exercise to be chosen with exit option
    printf("Choice your exercise: "); //by yerin, consider user's oppinion
    scanf("%d", &choice);

    if (choice == 0) {
        printf("No exercise choiced.\n"); //by yerin, If user's choice is 0, we print "No exercise choiced"
        return;
    }

    if (choice < 1 || choice > exercise_list_size) {
        printf("It's not appropriate choice.\n"); // by yerin, If user's choice is (choice < 1 || choice > exercise_list_size), it is out of bound
        return;
    }

    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);
    
    if (duration <= 0) { //by yerin, If exercise time<=0, we will tell you that it is not correct
        printf("It's not appropriate duration.\n");
        return;
    }
    
    int calories_burned = exercise_list[choice - 1].calories_per_min * duration; 
    printf("You burned %d calories by exercising %s for %d minutes.\n", calories_burned, exercise_list[choice - 1].name, duration);
    //by yerin, It tells that how many calories you burned by doing some exercise
    
    // ToCode: to enter the selected exercise and total calcories burned in the health data
    addExerciseToHealthData(health_data, exercise_list[choice - 1].name, calories_burned);
    //by yerin, Add choiced exercise data to health data
}
