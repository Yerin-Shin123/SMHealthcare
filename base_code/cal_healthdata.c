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
    FILE* file = fopen(HEALTHFILEPATH, "w");
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    for (i = 0; i < health_data->exercise_count; i++) 
    {
        fprintf(file, "%s: %d Calories burned\n", health_data->exercises[i].name, health_data->exercises[i].calories_burned);
        // by yerin, record the name of the exercise and the calories burned on file in the form of "Exercise Name: Burn Calories"
    } 

    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");
    for (int i = 0; i < health_data->diet_count; i++) 
    {
        fprintf(file, "%s: %d calories consumed\n", health_data->diets[i].name, health_data->diets[i].calories);
        // by yerin, record the name of meal and the calories consumed on file in the form of "Diet Name: Eating Calories."
    } 


    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    fprintf(file, "Basal Metabolic Rate (BMR): %d calories\n", health_data->basal_metabolic_rate); // by yerin, record Basal Metabolic Rate
    fprintf(file, "Total Calories Burned: %d calories\n", health_data->total_burned_calories); // by yerin, record Total Calories Burned
    fprintf(file, "Total Calories Consumed: %d calories\n", health_data->total_consumed_calories); // by yerin, record Total Calories consumed
    fprintf(file, "Remaining Calories: %d calories\n", health_data->remaining_calories); //by yerin, record Remaining Calories

    fclose(file);
    // by yerin, close file
    
}

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
	
	// ToCode: to print out the saved history of exercises
	printf("=========================== History of Exercise =======================\n");
  
  
    printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");


    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
 
 
    printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    
    
	 printf("=======================================================================\n");
}
