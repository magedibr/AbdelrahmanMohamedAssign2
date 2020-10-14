#include <limits.h>
// getv_rgnion function implementation
#include "household.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char term[100];

char* getv_rgnion(int v_rgn)
{
    switch (v_rgn)
    {
        case DURHAM:
            return "Durham";

        case PEEL:
            return "Peel";

        case YORK:
            return "York";

        default:
            return "NONE";
    }
}

// getv_twnn function implementation
char* getv_twnn(int v_rgn, int v_twn)
{
    if (v_rgn == DURHAM && v_twn == WHITBY)
        return "Whitby";
    else if (v_rgn == DURHAM && v_twn == OSHAWA)
        return "Oshawa";
    else if (v_rgn == PEEL && v_twn == MISSISSAUGA)
        return "Missisauga";
    else if (v_rgn == PEEL && v_twn == BRAMPTON)
        return "Brampton";
    else if (v_rgn == YORK && v_twn == MAPPLE)
        return "Mapple";
    else if (v_rgn == YORK && v_twn == VAUGHAN)
        return "Vaughan";
    else
        return "NA";
}


char* getv_rcee(int v_rce)
{
    switch (v_rce)
    { case INDIGENOUS:
            return "Indigenous";
        case CAUCASIAN:
            return "Caucasian";
        case ASIAN:
            return "Asian";


        case AFRICAN_AMERICAN:
            return "African American";



        case OTHER:
            return "Other";

        default:
            return "NONE";
    }
} // end of getv_rcee function

// getPositiveInteger function implementation
int getPositiveInteger(const char* str)
{
    if (str == NULL || *str == '\0')
        return 0;

    char* chPtr;
    strtod(str, &chPtr);

    if (*chPtr == '\0')
        return atoi(str);
    else
        return 0;
} // end of getPositiveInteger function

// printInfo function implementation
void printInfo( struct Household households[MAX])
{
    FILE* outfile;
    outfile = fopen("output.txt", "w");
    fprintf(outfile, "%10s%10s%15s%20s%15s%15s\n", "Number", "v_income", "Family v_szee", "v_rcee", "v_rgnion", "v_twnn");
    for (int i = 0; i < MAX; i++)
    {
        fprintf(outfile, "%10d%10d%15d%20s%15s%15s\n", (i + 1), households[i].v_income, households[i].v_szee, getv_rcee(households[i].v_rcee), getv_rgnion(households[i].v_rgnion), getv_twnn(households[i].v_rgnion, households[i].v_twnn));
    }
    printf("contents to file written successfully !\n");
    fclose(outfile);

    printf("%10s%10s%15s%20s%15s%15s\n", "Number", "v_income", "Family v_szee", "v_rcee", "v_rgnion", "v_twnn");
    for (int i = 0; i < MAX; i++)
    {
        printf("%10d%10d%15d%20s%15s%15s\n", (i + 1), households[i].v_income, households[i].v_szee, getv_rcee(households[i].v_rcee), getv_rgnion(households[i].v_rgnion), getv_twnn(households[i].v_rgnion, households[i].v_twnn));
    }
} // end of printInfo function



// print by region function
void printHByrgn( struct Household households[MAX])
{
    int durhams = 0;
    int peels = 0;
    int yorks = 0;

    for (int i = 0; i < MAX; i++)
    {
        if (households[i].v_rgnion == DURHAM)
            durhams++;
        if (households[i].v_rgnion == PEEL)
            peels++;

        if (households[i].v_rgnion == YORK)
            yorks++;
    }
    printf("Durham Region : %d\n", durhams);
    printf("Peel Region: %d\n", peels);

    printf("York Region: %d\n", yorks);
}

// printHByrce function implementation
void printHByrce( struct Household households[MAX])
{
    int caucasians = 0;
    int indigenouses = 0;
    int africanAmericans = 0;
    int asians = 0;
    int others = 0;

    for (int i = 0; i < MAX; i++)
    {
        if (households[i].v_rcee == CAUCASIAN)
            caucasians++;

        if (households[i].v_rcee == INDIGENOUS)
            indigenouses++;

        if (households[i].v_rcee == AFRICAN_AMERICAN)
            africanAmericans++;

        if (households[i].v_rcee == ASIAN)
            asians++;

        if (households[i].v_rcee == OTHER)
            others++;
    }

    printf("Caucasians: %d\n", caucasians);
    printf("Indigenous: %d\n", indigenouses);
    printf("African American: %d\n", africanAmericans);
    printf("Asian: %d\n", asians);
    printf("Others: %d\n", others);
} // end of printHByrce function



void printAverageByTwnAndRgn(struct Household households[MAX])
{
    int durhamWhitby = 0, durhamWhitbyv_income = 0;
    int durhamOshawa = 0, durhamOshawav_income = 0;
    int peelMississauga = 0, peelMississaugav_income = 0;
    int peelBrampton = 0, peelBramptonv_income = 0;
    int yorkMapple = 0, yorkMapplev_income = 0;
    int yorkVaughan = 0, yorkVaughanv_income = 0;

    for (int i = 0; i < MAX; i++)
    {
        if (households[i].v_rgnion == DURHAM && households[i].v_twnn == WHITBY)
        {
            durhamWhitby++;
            durhamWhitbyv_income += households[i].v_income;
        }

        if (households[i].v_rgnion == DURHAM && households[i].v_twnn == OSHAWA)
        {
            durhamOshawa++;
            durhamOshawav_income += households[i].v_income;
        }

        if (households[i].v_rgnion == PEEL && households[i].v_twnn == MISSISSAUGA)
        {
            peelMississauga++;
            peelMississaugav_income += households[i].v_income;
        }

        if (households[i].v_rgnion == PEEL && households[i].v_twnn == BRAMPTON)
        {
            peelBrampton++;
            peelBramptonv_income += households[i].v_income;
        }

        if (households[i].v_rgnion == YORK && households[i].v_twnn == MAPPLE)
        {
            yorkMapple++;
            yorkMapplev_income += households[i].v_income;
        }

        if (households[i].v_rgnion == YORK && households[i].v_twnn == VAUGHAN)
        {
            yorkVaughan++;
            yorkVaughanv_income += households[i].v_income;
        }
    }

    printf("Durham regnion:\n");
    printf("Average annual income of Oshawa: %d\n", (durhamOshawav_income / durhamOshawa));
    printf("Average annual income of Whitby: %d\n", (durhamWhitbyv_income / durhamWhitby));

    printf("\nPeel rgeion:\n");
    printf("Average annual income of Mississauga: %d\n", (peelMississaugav_income / peelMississauga));
    printf("Average annual income of Brampton: %d\n", (peelBramptonv_income / peelBrampton));

    printf("\nYork v_rgnion:\n");
    printf("Average annual income of Maple: %d\n", (yorkMapplev_income / yorkMapple));
    printf("Average annual income of Vaughan: %d\n", (yorkVaughanv_income / yorkVaughan));
} // end of printAverageByTwnAndRgn function

// printAvgv_income function implementation
void printAvgv_income( struct Household households[MAX])
{
    int totalv_income = 0;

    for (int i = 0; i < MAX; i++)
    {
        totalv_income += households[i].v_income;
    }

    printf("The average household v_income: %d\n", (totalv_income / MAX));
}

// printAvgByTwnAndRgn function implementation
void printAvgByTwnAndRgn( struct Household households[MAX])
{
    int caucasians = 0, asians = 0,
            asianv_income = 0,
            caucasianv_income = 0,
            indigenouses = 0,
            indigenousv_income = 0,
            africanAmericans = 0,
            africanAmericanv_income = 0,
            others = 0,
            otherv_income = 0;


    for (int i = 0; i < MAX; i++)
    {
        if (households[i].v_rcee == CAUCASIAN)
        {
            caucasians++;
            caucasianv_income += households[i].v_income;
        }

        if (households[i].v_rcee == INDIGENOUS)
        {
            indigenouses++;
            indigenousv_income += households[i].v_income;
        }

        if (households[i].v_rcee == AFRICAN_AMERICAN)
        {
            africanAmericans++;
            africanAmericanv_income += households[i].v_income;
        }

        if (households[i].v_rcee == ASIAN)
        {
            asians++;
            asianv_income += households[i].v_income;
        }

        if (households[i].v_rcee == OTHER)
        {
            others++;
            otherv_income += households[i].v_income;
        }
    }

    printf("Average annual income of Caucasians: %d\n", (caucasianv_income / caucasians));
    printf("Average annual income of Indigenous: %d\n", (indigenousv_income / indigenouses));
    printf("Average annual income of African Americans: %d\n", (africanAmericanv_income / africanAmericans));
    printf("Average annual income of Asian: %d\n", (asianv_income / asians));
    printf("Average annual income of Others: %d\n", (otherv_income / others));
} // end of printAvgByTwnAndRgn function

//Function to calculate poverty based on given requirments
int Pvrty(const struct Household households[MAX], int i)
{
    if ((households[i].v_szee == 1 && households[i].v_income < 15000) ||
        (households[i].v_szee == 2 && households[i].v_income < 20000) ||
        (households[i].v_szee == 3 && households[i].v_income < 25000) ||
        (households[i].v_szee == 4 && households[i].v_income < 30000) ||
        (households[i].v_szee >= 5 && households[i].v_income < 40000))
    {
        //Positive poverty indicator
        return 1;
    }
    return 0;
}

// prntBelowPvrty function implementation
void prntBelowPvrty( struct Household households[MAX])
{
    int underPoverty = 0;

    for (int i = 0; i < MAX; i++)
    {if (Pvrty(households, i) == 1)
        {underPoverty++;
        }
    }

    //Rounding to the nearest 100
    double result = round((double)underPoverty / MAX * 100);
    //.2f used to format the answer to match the rounding
    printf("Number of households below poverty line are: %.2f%%\n", result);
}

// prntBelowPvrtyByRce function implementation
void prntBelowPvrtyByRce( struct Household households[MAX])
{


    int africanAmericans = 0;
    int africanAmericansUnderPoverty = 0;
    int caucasians = 0;
    int caucasiansUnderPoverty = 0;
    int asians = 0;
    int asiansUnderPoverty = 0;
    int indigenouses = 0;
    int indigenousesUnderPoverty = 0;
    int others = 0;
    int othersUnderPoverty = 0;

    for (int i = 0; i < MAX; i++)
    {if (households[i].v_rcee == CAUCASIAN)
        {caucasians++;
            if (Pvrty(households, i) == 1)
            {caucasiansUnderPoverty++;
            }
        }
        if (households[i].v_rcee == INDIGENOUS)
        {
            indigenouses++;
            if (Pvrty(households, i) == 1)
            {
                indigenousesUnderPoverty++;
            }
        }
        if (households[i].v_rcee == AFRICAN_AMERICAN)
        {
            africanAmericans++;
            if (Pvrty(households, i) == 1)
            {
                africanAmericansUnderPoverty++;
            }
        }

        if (households[i].v_rcee == ASIAN)
        {
            asians++;
            if (Pvrty(households, i) == 1)
            {
                asiansUnderPoverty++;
            }
        }

        if (households[i].v_rcee == OTHER)
        {
            others++;
            if (Pvrty(households, i) == 1)
            {
                othersUnderPoverty++;
            }
        }
    }

    double caucasiansResult = round((double)caucasiansUnderPoverty / caucasians * 100);
    double indigenousesResult = round((double)indigenousesUnderPoverty / indigenouses * 100);
    double africanAmericansResult = round((double)africanAmericansUnderPoverty / africanAmericans * 100);
    double asiansResult = round((double)asiansUnderPoverty / asians * 100);
    double othersResult = round((double)othersUnderPoverty / others * 100);

    printf("Number of households below poverty line by Caucasians are: %.2f%%\n", caucasiansResult);
    printf("Number of households below poverty line by Indigenous are: %.2f%%\n", indigenousesResult);
    printf("Number of households below poverty line by African American are: %.2f%%\n", africanAmericansResult);
    printf("Number of households below poverty line by Asian are: %.2f%%\n", asiansResult);
    printf("Number of households below poverty line by Other are: %.2f%%\n", othersResult);
}

//Function to iterate through households,calculate the poverty in each region then display the AVG by Town and Reigon
void prntBelowPvrtyByTwnRgn( struct Household households[MAX])
{
    int peelBrampton = 0, peelBramptonUnderPoverty = 0;
    int yorkMapple = 0, yorkMappleUnderPoverty = 0;
    int yorkVaughan = 0, yorkVaughanUnderPoverty = 0;
    int durhamWhitby = 0, durhamWhitbyUnderPoverty = 0;
    int durhamOshawa = 0, durhamOshawaUnderPoverty = 0;
    int peelMississauga = 0, peelMississaugaUnderPoverty = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (households[i].v_rgnion == DURHAM && households[i].v_twnn == WHITBY)
        {
            durhamWhitby++;
            if (Pvrty(households, i) == 1)
            {
                durhamWhitbyUnderPoverty++;
            }
        }
        if (households[i].v_rgnion == DURHAM && households[i].v_twnn == OSHAWA)
        {
            durhamOshawa++;

            if (Pvrty(households, i) == 1)
            {
                durhamOshawaUnderPoverty++;
            }
        }
        if (households[i].v_rgnion == PEEL && households[i].v_twnn == MISSISSAUGA)
        {
            peelMississauga++;
            if (Pvrty(households, i) == 1)
            {
                peelMississaugaUnderPoverty++;
            }
        }
        if (households[i].v_rgnion == PEEL && households[i].v_twnn == BRAMPTON)
        {
            peelBrampton++;
            if (Pvrty(households, i) == 1)
            {
                peelBramptonUnderPoverty++;
            }
        }
        if (households[i].v_rgnion == YORK && households[i].v_twnn == MAPPLE)
        {
            yorkMapple++;
            if (Pvrty(households, i) == 1)
            {
                yorkMappleUnderPoverty++;
            }
        }
        if (households[i].v_rgnion == YORK && households[i].v_twnn == VAUGHAN)
        {
            yorkVaughan++;
            if (Pvrty(households, i) == 1)
            {
                yorkVaughanUnderPoverty++;
            }
        }
    }
    double yorkVaughanResult = round((double)yorkVaughanUnderPoverty / yorkVaughan * 100);
    double durhamWhitbyResult = round((double)durhamOshawaUnderPoverty / durhamOshawa * 100);
    double yorkMappleResult = round((double)yorkMappleUnderPoverty / yorkMapple * 100);
    double durhamOshawaResult = round((double)durhamWhitbyUnderPoverty / durhamWhitby * 100);
    double peelMississaugaResult = round((double)peelMississaugaUnderPoverty / peelMississauga * 100);
    double peelBramptonResult = round((double)peelBramptonUnderPoverty / peelBrampton * 100);
    printf("Durham v_rgnion:\n");
    printf("Number of households below poverty line Oshawa are: %.2f%%\n", durhamWhitbyResult);
    printf("Number of households below poverty line Whitby are: %.2f%%\n", durhamOshawaResult);
    printf("\nYork v_rgnion:\n");
    printf("Number of households below poverty line Maple are: %.2f%%\n", yorkMappleResult);
    printf("Number of households below poverty line Vaughan are: %.2f%%\n", yorkVaughanResult);
    printf("\nPeel v_rgnion:\n");
    printf("Number of households below poverty line Mississauga are: %.2f%%\n", peelMississaugaResult);
    printf("Number of households below poverty line Brampton are: %.2f%%\n", peelBramptonResult);


}
// getMenuChoice function implementation
int getInput()
{
    int input;

    puts("\nMenu\n"
         "Enter your choice to display\n"
         "1. Households by v_region\n"
         "2. Households by v_race\n"
         "3. Average household income\n"
         "4. Average household by town and region\n"
         "5. Average household by race\n"
         "6. Percentage of households below poverty\n"
         "7. Percentage of households below poverty by race\n"
         "8. Percentage of households below poverty by town and region\n"
         "0. Exit\n");
    scanf("%d", &input);
    return input;
}




//Array of function pointers to direct user input
void (*funcArray[8])(struct Household[])={      //missing function
         printHByrgn,               //1
       printHByrce,               //2
       printAvgv_income,          //3
         printAverageByTwnAndRgn,   //4
        printAvgByTwnAndRgn,       //5
   prntBelowPvrty,            //6
     prntBelowPvrtyByRce,       //7
         prntBelowPvrtyByTwnRgn};   //8

void userChoice(struct Household households[MAX]) {
 int input ;

    do {
       input=getInput();
        switch (input) {
            case 1:
             //   (*funcArray[1])(*households);
                (*funcArray[2])(households);
                break;

            case 2:
                (*funcArray[3])(households);
                break;

            case 3:

                (*funcArray[4])(households);
                break;

            case 4:

                (*funcArray[5])(households);
                break;

            case 5:
                (*funcArray[6])(households);
                break;

            case 6:
                (*funcArray[7])(households);
                break;

            case 7:
                (*funcArray[8])(households);
                break;

            case 8:
                (*funcArray[8])(households);
                break;
//
            case 0:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }
    }while (input != 0);

    }

    //Struct variables set to Exit value by default.
        int v_rgn = EXIT;
        int v_twn = EXIT;
        int v_rce = EXIT;



        int regionInput(){

        printf("Enter appropriate number for the region:\n");
        printf(" Durham (0), PEEL (1), YORK (2)\n");
        printf("or enter 3 to skip user inputs to generate rest of the records randomly ");
        scanf("%d", &v_rgn);

        while (v_rgn != 9&& (v_rgn < 0 || v_rgn > 3) )
        {
            printf("Invalid data. You should enter one integer in the range 0 through 3 or enter 9 to exit. Try again\n");
            scanf("%d", &v_rgn);
        }
        return v_rgn;

}

   int townInput(){
       scanf("%d", &v_twn);

       while ((v_twn < 0 || v_twn > 1) && v_twn != 9)
       {
           printf("Invalid data. You should enter one integer in the range 0 through 1 or enter 9 to exit. Try again\n");
           scanf("%d", &v_twn);
       }
       return v_twn;

        }

   int raceInput(){

       printf("Enter appropriate number for the race:\n");
       printf(" Caucasian (0), Indigenous (1), African American (2), Asian (3), Others (4) ");
       scanf("%d", &v_rce);

       while ((v_rce < 0 || v_rce > 4) && v_rce != 9)
       {
           printf("Invalid data. You should enter one integer in the range 0 through 4 or enter 9 to exit. Try again\n");
           scanf("%d", &v_rce);
       }
       return v_rce;
        }


































