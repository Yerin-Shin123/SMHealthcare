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

#define MAX_DIETS 100               // Maximum number of diets
#define MAX_FOOD_NAME_LEN 50      // Maximum length of the name of food

typedef struct { // by yerin, food information for structure
    char name[MAX_FOOD_NAME_LEN]; // by yerin, food name
    int calories; //by yerin, food calories
} Diet;

// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt"
*/

void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while (fscanf(file, "%s %d", diet_list[diet_list_size].name, &diet_list[diet_list_size].calories) == 2) {
	    //by yerin, bring diet information from file, and put diet_list array
        diet_list_size++;
        if (diet_list_size >= MAX_DIETS){ //by yerin, if diet list reach to max size then stop
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
    printf("The list of diets:\n");
    for (i = 0; i < diet_list_size; i++)
	{
        printf("%d. %s, %d calories\n", i + 1, diet_list[i].name, diet_list[i].calories); //by yerin, print index (i+1), food name, food calories
    }
    printf("0. Exit\n"); //by yerin, print exit option

    
   // ToCode: to enter the diet to be chosen with exit option
    printf("Choice your diet: "); //by yerin, consider user's oppinion
    scanf("%d", &choice);

    if (choice == 0)
	{
        printf("No diet choiced.\n"); //by yerin, If choice is 0, we print "No diet choiced"
        return;
    }

    if (choice < 1 || choice > diet_list_size)
	{
        printf("It's not appropriate choice.\n"); // by yerin, If choice is (choice < 1 || choice > diet_list_size), it is out of bound
        return;
    }


    // ToCode: to enter the selected diet in the health data
    printf("You choiced %s, it has %d calories.\n", diet_list[choice - 1].name, diet_list[choice - 1].calories);
    //by yerin, print name of diet and calories of diet

    // ToCode: to enter the total calories intake in the health data
    addDietToHealthData(health_data, diet_list[choice - 1].name, diet_list[choice - 1].calories);
    //by yerin, Add choiced diet data to health data

}
