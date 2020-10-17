#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "household.h"

/*
 *
 * i<MAX could be I<2
 * Check the whole if(v_income == EXIT||...)
 *
 * */

int main()
{

    //Array of households declared
    struct Household households[MAX];
    int i = 0;
    int reg_choice,t_choice,race_choice,income_input,income,fam_size;


    while (i < MAX)
    {
        printf("Data entry for household record number %d:\n\n", (i + 1));

        //Function to store users choice for region
        reg_choice = RegionInput();
printf("%d",reg_choice);
        srand(time(0));
        //DEFAULT condition
        if(reg_choice == 3)
            break;

        if(reg_choice >= 0 && reg_choice <= 2)
        {
            printf("Enter appropriate number for the town:\n");
            if (reg_choice == 0)
                printf(" Whitby (0), Oshawa (1) ");
            else if (reg_choice == 1)
                printf(" Mississauga (0), Brampton (1) ");
            else if (reg_choice == 2)
                printf(" Maple (0), Vaughan (1) ");

            //Function to store and validate user choice for town
            t_choice = townInput();
            int sizeIncome[3];
            int *arrPtr = sizeIncome;
            if (t_choice >= 0 && t_choice <= 1)
            {
                //Collect and validate Race input
                race_choice = raceInput();

                validateFamilyAndIncome(arrPtr);

                 //Assign the variables collected by sizeIncomeValidator to variables for later use
                 fam_size= sizeIncome[0];
                 income_input= sizeIncome[1];

                households[i].v_Race = race_choice;
                households[i].v_Size = fam_size;
                households[i].v_income = income_input;
                households[i].v_Region = reg_choice;
                households[i].v_Town = t_choice;

                printf("\n\n");
            }
        }

        if (race_choice == DEFAULT ||reg_choice==DEFAULT|| fam_size ==DEFAULT)
        {
            printf("Exiting  program..\n");
            break;
        }

        i++;
    }

    if (reg_choice == 3)
    {
        while (i < MAX)
        {
            reg_choice = rand() % 3;
            t_choice = rand() % 2;
            race_choice = rand() % 5;
            fam_size = rand() % 9 + 1;
            income = (rand() % 400 + 100) * 100;

            households[i].v_Region = reg_choice;
            households[i].v_Town = t_choice;
            households[i].v_Race = race_choice;
            households[i].v_Size = fam_size;
            households[i].v_income = income;
            i++;
        }
    }

    printInfo(households);
    userChoice(households);

    return 0;}