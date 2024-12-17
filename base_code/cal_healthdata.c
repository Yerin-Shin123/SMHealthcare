//
//  cal_healthdata.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"


/*
    description : enter the exercise and diet history in "health_data.txt" 
    input parameters : health_data - data object in which the selected exercise and diet is stored
    return value : No
    
    operation : 1. save the chosen exercise and total calories burned 
    			2. save the chosen diet and total calories intake 
    			3. save the total remaining calrories
*/

void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {
	int i;
    FILE* file = fopen(HEALTHFILEPATH, "a");
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    for(i=0; i<health_data->exercise_list_size; i++){
    	fprintf(file, "%s: %d kcal\n", health_data->exercise_list[i].exercise_name, health_data->exercise_list[i].calories_burned_per_minute);
	}//by yerin
    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");
    for (i = 0; i < health_data->diet_list_size; i++) {
        fprintf(file, "%s: %d kcal\n", health_data->diet_list[i].food_name, health_data->diet_list[i].calories_intake);//by yerin 12/17 11:37

    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    fprintf(file, "Calories burned: %d\n", health_data->total_calories_burned);
    fprintf(file, "Calories intake: %d\n", health_data->total_calories_intake);
    fprintf(file, "Remaining calories: %d\n", DAILY_CALORIE_GOAL - health_data->total_calories_burned + health_data->total_calories_intake);

    fclose(file);
}//by yerin

/*
    description : print the history of exercised and diets
    input parameters : health_data - data object in which the history of the exercise and diet is to be printed
    return value : No
    
    operation : 1. print out the saved history of exercises
    			2. print out the saved history of diets
    			3. print out the saved history of calories
*/

void printHealthData(const HealthData* health_data) {
	int i;
	int exercise_list_size=0;

	// ToCode: to print out the saved history of exercises
	printf("=========================== History of Exercise =======================\n");
    for (i = 0; i < health_data->exercise_list_size; i++) 
	{
        printf("%d. %s: %d kcal\n", i + 1, health_data->exercise_list[i].exercise_name, health_data->exercise_list[i].calories_burned_per_minute);
    }
  
    printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");
    for (i = 0; i < health_data->diet_list_size; i++) 
	{
        printf("%d. %s: %d kcal\n", i + 1, health_data->diet_list[i].food_name, health_data->diet_list[i].calories_intake);
    }


    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
 
    printf("Basal Metabolic Rate: %d kcal\n", BASAL_METABOLIC_RATE);
    printf("Total Calories Burned: %d kcal\n", health_data->total_calories_burned);
    printf("Total Calories Intake: %d kcal\n", health_data->total_calories_intake);
    int remaining_calories = DAILY_CALORIE_GOAL - health_data->total_calories_burned + health_data->total_calories_intake;
    printf("Remaining Calories: %d kcal\n", remaining_calories);
 

    printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    
     if (remaining_calories == 0) {
        printf("You consumed all your calories for today!\n");
    } else if (remaining_calories > 0) {
        printf("You need to exercise more to burn %d kcal!\n", remaining_calories);
    } else {
        printf("Be careful! You have exceeded your calorie limit by %d kcal!\n", -remaining_calories);
    }

	 printf("=======================================================================\n");
}
