#include <stdlib.h>
#include<math.h>
#include <stdio.h>
#include <time.h>
#include "household.h"
#define EXIT 9



int main()
{
    // intialize the random number generator
    srand(time(0));

    struct Household households[MAX];
    int v_rgn = EXIT, v_twn = EXIT, v_rce = EXIT, v_sze = EXIT, v_inc = EXIT;
    char term[20];
    int i = 0, choice;

    while (i < MAX)
    {
        printf("Data entry for household record number %d:\n\n", (i + 1));

        printf("Enter appropriate number for the region:\n");
        printf(" Durhan (0), PEEL (1), YORK (2)\n");
        printf("or enter 3 to skip user inputs to generate rest of the records randomly ");
        scanf("%d", &v_rgn);

        while ((v_rgn < 0 || v_rgn > 3) && v_rgn != 9)
        {
            printf("Invalid data. You should enter one integer in the range 0 through 3 or enter 9 to exit. Try again\n");
            scanf("%d", &v_rgn);
        }

        if(v_rgn == 3)
            break;

        if(v_rgn >= 0 && v_rgn <= 2)
        {
            printf("Enter appropriate number for the town:\n");
            if (v_rgn == 0)
                printf(" Whitby (0), Oshawa (1) ");
            else if (v_rgn == 1)
                printf(" Mississauga (0), Brampton (1) ");
            else if (v_rgn == 2)
                printf(" Maple (0), Vaughan (1) ");
            scanf("%d", &v_twn);

            while ((v_twn < 0 || v_twn > 1) && v_twn != 9)
            {
                printf("Invalid data. You should enter one integer in the range 0 through 1 or enter 9 to exit. Try again\n");
                scanf("%d", &v_twn);
            }

            if (v_twn >= 0 && v_twn <= 1)
            {
                printf("Enter appropriate number for the race:\n");
                printf(" Caucasian (0), Indigenous (1), African American (2), Asian (3), Others (4) ");
                scanf("%d", &v_rce);

                while ((v_rce < 0 || v_rce > 4) && v_rce != 9)
                {
                    printf("Invalid data. You should enter one integer in the range 0 through 4 or enter 9 to exit. Try again\n");
                    scanf("%d", &v_rce);
                }


                printf("Enter family(household) size and total annual income ( to the nearest hundred) separated by space/Tab: ");
                scanf("%d", &v_sze);
                scanf("%s", &term);
                v_inc = getPositiveInteger(term);

                while (v_sze < 1  || v_inc % 100 != 0|| v_inc < 1)
                {
                    printf("Invalid data. Enter two positive integers separated by space/tab, first one for size of the family and second one for total annualincome. Try again\n");
                    scanf("%d", &v_sze);
                    scanf("%s", &term);
                    v_inc = getPositiveInteger(term);
                }

                households[i].v_rgnion = v_rgn;
                households[i].v_twnn = v_twn;
                households[i].v_rcee = v_rce;
                households[i].v_szee = v_sze;
                households[i].v_income = v_inc;
                printf("\n\n");
            }
        }

        if (v_rce == EXIT ||v_rgn==EXIT||v_sze==9)
        {
            printf("Exiting the program..\n");
            break;
        }

        i++;
    }

    if (v_rgn == 3)
    {
        while (i < MAX)
        {
            v_rgn = rand() % 3;
            v_twn = rand() % 2;
            v_rce = rand() % 5;
            v_sze = rand() % 9 + 1;
            v_inc = (rand() % 400 + 100) * 100;

            households[i].v_rgnion = v_rgn;
            households[i].v_twnn = v_twn;
            households[i].v_rcee = v_rce;
            households[i].v_szee = v_sze;
            households[i].v_income = v_inc;
            i++;
        }
    }

    printInfo(households);

    do
    {
        choice = getMenuChoice();

        switch (choice)
        {
            case 1:
                printHByrgn(households);
                break;

            case 2:
                printHByrce(households);
                break;

            case 3:
                printAvgv_income(households);
                break;

            case 4:
                printAverageByTwnAndRgn(households);
                break;

            case 5:
                printAvgByTwnAndRgn(households);
                break;

            case 6:
                prntBelowPvrty(households);
                break;

            case 7:
                prntBelowPvrtyByRce(households);
                break;

            case 8:
                prntBelowPvrtyByTwnRgn(households);
                break;

            case 0:
                printf("Thank you.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 0);

    return 0;}