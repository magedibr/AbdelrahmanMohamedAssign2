#include <stdlib.h>
#include<math.h>
#include <stdio.h>
#include <time.h>
#include "household.h"

int v_sze = EXIT;
int v_inc = EXIT;


int main()
{

    //Array of households declared
    struct Household households[MAX];
    struct Household* hhpt =households;

    char term[20];
    int i = 0;
    int reg_choice,t_choice,race_choice,income_input,income,fam_size;

    srand(time(0));
    while (i < MAX)
    {
        printf("Data entry for household record number %d:\n\n", (i + 1));

        //Function to store users choice for reigon
        reg_choice = regionInput();

        //exit condition
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

            if (t_choice >= 0 && t_choice <= 1)
            {
                race_choice = raceInput();
               printf("Enter family(household) size and total annual income ( to the nearest hundred) separated by space/Tab: ");
                scanf("%d", &fam_size);
                scanf("%s", &term);


                income_input = getPositiveInteger(term);

                while (fam_size < 1  || income_input % 100 != 0|| income_input < 1)
                {
                    printf("Invalid data. Enter two positive integers separated by space/tab, first one for size of the family and second one for total annualincome. Try again\n");
                    scanf("%d", &fam_size);
                    scanf("%s", &term);
                    income_input=getPositiveInteger(term);

                }

                households[i].v_rcee = race_choice;
                households[i].v_szee = fam_size;
                households[i].v_income = income_input;
                households[i].v_rgnion = reg_choice;
                households[i].v_twnn = t_choice;

                printf("\n\n");
            }
        }

        if (race_choice == EXIT ||reg_choice==EXIT|| fam_size ==EXIT)
        {
            printf("Exiting the program..\n");
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

            households[i].v_rgnion = reg_choice;
            households[i].v_twnn = t_choice;
            households[i].v_rcee = race_choice;
            households[i].v_szee = fam_size;
            households[i].v_income = income;
            i++;
        }
    }

   printInfo(households);
   userChoice(households);

    return 0;}