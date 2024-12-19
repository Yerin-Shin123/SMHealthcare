//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
	// To initialize the health data object
    HealthData health_data = {0};
    health_data.basal_metabolic_rate = 2000;  // by yerin, set the basic metabolic rate for health data to 2000

    // Tocode: to read the list of the exercises and diets
    loadExercises(EXERCISEFILEPATH);//by yerin, bring exercise data from the file (EXERCISEFILEEPATH)
    loadDiets(DIETFILEPATH); //by yerin, bring diet data from the file (DIETFILEEPATH)


    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do {
    	if (health_data.remaining_calories <= 0){ // by yerin
            printf("You have consumed all your calories for today! \n");
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	inputExercise(&health_data); // by yerin, enter the exercise data and add it to health_data
                break;
                
            case 2:
            	inputDiet(&health_data); // by yerin, enter the diet data and add it to health_data
                break;
                
            case 3:
            	printHealthData(&health_data); // by yerin, print health_data
                break;
                
            case 4:
            	saveData(HEALTHFILEPATH, &health_data); // by yerin, save health data to a file
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while (choice != 4); // by yerin, run repeatedly until the user choices 4

    return 0;
}
