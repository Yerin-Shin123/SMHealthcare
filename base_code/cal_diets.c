//
//  cal_diets.c
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

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 

static Diet diet_list[MAX_DIETS];
static int diet_list_size= 0;

/*
    description : read the information in "diets.txt"
*/

void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for diets!\n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while(fscanf(file,"%s %d", diet_list[diet_list_size].food_name, &diet_list[diet_list_size].calories_intake) !=EOF) {//by yerin pm 10:39, read food name and calorie and store in the diet_list array
	diet_list_size++; //
	if(diet_list_size>=MAX_DIETS){
		printf("Be careful!! It's over max size!"); //by yerin pm 10:53, presen twarning message when the maximum size is exceeded
		break;
	}          
    }
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("available diet list:\n"); //by yerin, print message of information
     for (i = 0; i < diet_list_size; i++) {
        printf("%d. %s (%d Kcal)\n", i + 1, diet_list[i].food_name, diet_list[i].calories_intake); //by yerin, print food name and calories intake
    }
    printf("%d. Exit\n", diet_list_size+1);
    // by yerin 
    
    printf("choose a diet(1-%d):", diet_list_size+1);
    scanf("%d",&choice); //Selection entered by the user
    
    if(choice==diet_list_size+1){
    	printf("Exit selected. No diet recorded.\n");
    	return;
	}
    else if(choice<1||choice>diet_list_size){ //when selected number is out of valid number
    	printf("Warning! invaild options choiced. Try again.\n");
    	return;
	}
	
	int calories_intake=diets[choice-1].calories_intake;
	
	printf("Today you consumed %d kcal by eating %s.\n",calories_intake, diets[choice-1].food_name); //by yerin pm 11:20, present name of food and consumed calories
	    
	health_data->total_calories_intake+=calories_intake;
 
}

