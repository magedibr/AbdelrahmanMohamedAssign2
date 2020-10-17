//Create by: Abdelrahman Mohamed
//Date:16/10/2020
//Function implementations

#include "household.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>



char* getv_Region(int v_rgn)
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
            return "NA";
    }
}

// getv_Town function implementation
char* getv_Town(int v_rgn, int v_Town)
{
    if (v_rgn == DURHAM && v_Town == WHITBY)
        return "Whitby";
    else if (v_rgn == DURHAM && v_Town == OSHAWA)
        return "Oshawa";
    else if (v_rgn == PEEL && v_Town == MISSISSAUGA)
        return "Missisauga";
    else if (v_rgn == PEEL && v_Town == BRAMPTON)
        return "Brampton";
    else if (v_rgn == YORK && v_Town == MAPPLE)
        return "Mapple";
    else if (v_rgn == YORK && v_Town == VAUGHAN)
        return "Vaughan";
    else
        return "NA";
}


char* getv_Race(int v_rce)
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
            return "Other";

        default:
            return "NA";
    }
}

//Pointer function used to be able to change the value of the passed array
//Function to Validate and set Family size and income to the nearest 100
void validateFamilyAndIncome(int *ptr) {
    char buffer[11];
    int ctr;
    int Positivesize;
    int Positiveincome;

    printf("Enter family(household) size and total annual income ( to the nearest hundred) separated by space/Tab: ");
    fgets(buffer, sizeof(buffer), stdin);
    ctr = sscanf(buffer, " %d%d", &Positivesize, &Positiveincome);

    if (ctr != 2 || Positiveincome % 100 != 0 || Positiveincome < 1 || Positivesize < 1) {
        printf("Invalid data. Enter two positive integers separated by space/tab, first one for size of the family and second one for total annualincome. Try again\n");
        validateFamilyAndIncome((int*) ptr);
    }else {
        ptr[0] = Positivesize;
        ptr[1] = Positiveincome;
    }
}





// printInfo function implementation
void printInfo( struct Household households[MAX])
{


    printf("%10s%10s%15s%20s%15s%15s\n","Number","Income","Family Size","Race","Region" ,"Town");
    for (int i = 0; i < MAX; i++)
    {
        printf("%10d%10d%15d%20s%15s%15s\n", (i + 1), households[i].v_income, households[i].v_Size, getv_Race(households[i].v_Race), getv_Region(households[i].v_Region), getv_Town(households[i].v_Region, households[i].v_Town));
    }


}


// print by Region function
void printHByrgn( struct Household households[MAX])
{
    int durhams = 0;
    int peels = 0;
    int yorks = 0;

    for (int i = 0; i < MAX; i++)
    {
        if (households[i].v_Region == DURHAM)
            durhams++;
        if (households[i].v_Region == PEEL)
            peels++;

        if (households[i].v_Region == YORK)
            yorks++;
    }
    printf("Durham Region : %d\n", durhams);
    printf("Peel Region: %d\n", peels);

    printf("York Region: %d\n", yorks);
}


void printAvgHByRce( struct Household households[MAX])
{
    int caucasians = 0;
    int caucasianIncome = 0;
    int indigenouses = 0;
    int indigenousIncome = 0;
    int africanAmericans = 0;
    int africanAmericanIncome = 0;
    int asians = 0;
    int asianIncome = 0;
    int others = 0;
    int otherIncome = 0;

    for (int i = 0; i < MAX; i++)
    {
        if (households[i].v_Race == CAUCASIAN)
        {
            caucasians++;
            caucasianIncome += households[i].v_income;
        }

        if (households[i].v_Race == INDIGENOUS)
        {
            indigenouses++;
            indigenousIncome += households[i].v_income;
        }

        if (households[i].v_Race == AFRICAN_AMERICAN)
        {
            africanAmericans++;
            africanAmericanIncome += households[i].v_income;
        }

        if (households[i].v_Race == ASIAN)
        {
            asians++;
            asianIncome += households[i].v_income;
        }

        if (households[i].v_Race == OTHER)
        {
            others++;
            otherIncome += households[i].v_income;
        }
    }

    printf("Average annual income of Caucasians: %d\n", (caucasianIncome / caucasians));
    printf("Average annual income of Indigenous: %d\n", (indigenousIncome / indigenouses));
    printf("Average annual income of African Americans: %d\n", (africanAmericanIncome / africanAmericans));
    printf("Average annual income of Asian: %d\n", (asianIncome / asians));
    printf("Average annual income of Others: %d\n", (otherIncome / others));
}


//Function to calculate poverty based on given requirements
int Pvrty( struct Household households[MAX], int i)
{
    if ((households[i].v_Size == 1 && households[i].v_income < 15000) ||
        (households[i].v_Size == 2 && households[i].v_income < 20000) ||
        (households[i].v_Size == 3 && households[i].v_income < 25000) ||
        (households[i].v_Size == 4 && households[i].v_income < 30000) ||
        (households[i].v_Size >= 5 && households[i].v_income < 40000))
    {
        //Positive poverty indicator
        return 1;
    }
    return 0;
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
        if (households[i].v_Race == CAUCASIAN)
            caucasians++;

        if (households[i].v_Race == INDIGENOUS)
            indigenouses++;

        if (households[i].v_Race == AFRICAN_AMERICAN)
            africanAmericans++;

        if (households[i].v_Race == ASIAN)
            asians++;

        if (households[i].v_Race == OTHER)
            others++;
    }

    printf("Caucasians: %d\n", caucasians);
    printf("Indigenous: %d\n", indigenouses);
    printf("African American: %d\n", africanAmericans);
    printf("Asian: %d\n", asians);
    printf("Others: %d\n", others);
}



void printAverageByTownAndRgn(struct Household households[MAX])
{
    int durhamWhitby = 0, durhamWhitbyv_income = 0;
    int durhamOshawa = 0, durhamOshawav_income = 0;
    int peelMississauga = 0, peelMississaugav_income = 0;
    int peelBrampton = 0, peelBramptonv_income = 0;
    int yorkMapple = 0, yorkMapplev_income = 0;
    int yorkVaughan = 0, yorkVaughanv_income = 0;

    for (int i = 0; i < MAX; i++)
    {
        if (households[i].v_Region == DURHAM && households[i].v_Town == WHITBY)
        {
            durhamWhitby++;
            durhamWhitbyv_income += households[i].v_income;
        }

        if (households[i].v_Region == DURHAM && households[i].v_Town == OSHAWA)
        {
            durhamOshawa++;
            durhamOshawav_income += households[i].v_income;
        }

        if (households[i].v_Region == PEEL && households[i].v_Town == MISSISSAUGA)
        {
            peelMississauga++;
            peelMississaugav_income += households[i].v_income;
        }

        if (households[i].v_Region == PEEL && households[i].v_Town == BRAMPTON)
        {
            peelBrampton++;
            peelBramptonv_income += households[i].v_income;
        }

        if (households[i].v_Region == YORK && households[i].v_Town == MAPPLE)
        {
            yorkMapple++;
            yorkMapplev_income += households[i].v_income;
        }

        if (households[i].v_Region == YORK && households[i].v_Town == VAUGHAN)
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

    printf("\nYork v_Region:\n");
    printf("Average annual income of Maple: %d\n", (yorkMapplev_income / yorkMapple));
    printf("Average annual income of Vaughan: %d\n", (yorkVaughanv_income / yorkVaughan));
}

// printAvgv_income function implementation
void printAvgv_income( struct Household households[MAX])
{
    int totalv_income = 0;

    for (int i = 0; i < MAX; i++)
    {
        totalv_income += households[i].v_income;
    }

    printf("The average household income: %d\n", (totalv_income / MAX));
}

// printAvgByTownAndRgn function implementation
void printAvgByTownAndRgn( struct Household households[MAX])
{
    int caucasians = 0,
            asians = 0,
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
        if (households[i].v_Race == CAUCASIAN)
        {
            caucasians++;
            caucasianv_income += households[i].v_income;
        }

        if (households[i].v_Race == INDIGENOUS)
        {
            indigenouses++;
            indigenousv_income += households[i].v_income;
        }

        if (households[i].v_Race == AFRICAN_AMERICAN)
        {
            africanAmericans++;
            africanAmericanv_income += households[i].v_income;
        }

        if (households[i].v_Race == ASIAN)
        {
            asians++;
            asianv_income += households[i].v_income;
        }

        if (households[i].v_Race == OTHER)
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
} // end of printAvgByTownAndRgn function



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
    {if (households[i].v_Race == CAUCASIAN)
        {caucasians++;
            if (Pvrty(households, i) == 1)
            {caucasiansUnderPoverty++;
            }
        }
        if (households[i].v_Race == INDIGENOUS)
        {
            indigenouses++;
            if (Pvrty(households, i) == 1)
            {
                indigenousesUnderPoverty++;
            }
        }
        if (households[i].v_Race == AFRICAN_AMERICAN)
        {
            africanAmericans++;
            if (Pvrty(households, i) == 1)
            {
                africanAmericansUnderPoverty++;
            }
        }

        if (households[i].v_Race == ASIAN)
        {
            asians++;
            if (Pvrty(households, i) == 1)
            {
                asiansUnderPoverty++;
            }
        }

        if (households[i].v_Race == OTHER)
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

//Function to iterate through households,calculate the poverty in each Region then display the AVG by Town and region
void prntBelowPvrtyByTownRgn( struct Household households[MAX])
{
    int peelBrampton = 0, peelBramptonUnderPoverty = 0;
    int yorkMapple = 0, yorkMappleUnderPoverty = 0;
    int yorkVaughan = 0, yorkVaughanUnderPoverty = 0;
    int durhamWhitby = 0, durhamWhitbyUnderPoverty = 0;
    int durhamOshawa = 0, durhamOshawaUnderPoverty = 0;
    int peelMississauga = 0, peelMississaugaUnderPoverty = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (households[i].v_Region == DURHAM && households[i].v_Town == WHITBY)
        {
            durhamWhitby++;
            if (Pvrty(households, i) == 1)
            {
                durhamWhitbyUnderPoverty++;
            }
        }
        if (households[i].v_Region == DURHAM && households[i].v_Town == OSHAWA)
        {
            durhamOshawa++;

            if (Pvrty(households, i) == 1)
            {
                durhamOshawaUnderPoverty++;
            }
        }
        if (households[i].v_Region == PEEL && households[i].v_Town == MISSISSAUGA)
        {
            peelMississauga++;
            if (Pvrty(households, i) == 1)
            {
                peelMississaugaUnderPoverty++;
            }
        }
        if (households[i].v_Region == PEEL && households[i].v_Town == BRAMPTON)
        {
            peelBrampton++;
            if (Pvrty(households, i) == 1)
            {
                peelBramptonUnderPoverty++;
            }
        }
        if (households[i].v_Region == YORK && households[i].v_Town == MAPPLE)
        {
            yorkMapple++;
            if (Pvrty(households, i) == 1)
            {
                yorkMappleUnderPoverty++;
            }
        }
        if (households[i].v_Region == YORK && households[i].v_Town == VAUGHAN)
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
    printf("Durham v_Region:\n");
    printf("Number of households below poverty line Oshawa are: %.2f%%\n", durhamWhitbyResult);
    printf("Number of households below poverty line Whitby are: %.2f%%\n", durhamOshawaResult);
    printf("\nYork v_Region:\n");
    printf("Number of households below poverty line Maple are: %.2f%%\n", yorkMappleResult);
    printf("Number of households below poverty line Vaughan are: %.2f%%\n", yorkVaughanResult);
    printf("\nPeel v_Region:\n");
    printf("Number of households below poverty line Mississauga are: %.2f%%\n", peelMississaugaResult);
    printf("Number of households below poverty line Brampton are: %.2f%%\n", peelBramptonResult);


}
// getMenuChoice function implementation
int getInput()
{
    int input;

    puts("\nMenu\n"
         "Enter your choice to display\n"
         "1. Households by Region\n"
         "2. Households by race\n"
         "3. Average household income\n"
         "4. Average household by town and Region\n"
         "5. Average household by race\n"
         "6. Percentage of households below poverty\n"
         "7. Percentage of households below poverty by race\n"
         "8. Percentage of households below poverty by town and Region\n"
         "0. Exit\n");
  scanf("%d", &input);
    return input;

}




//Array of function pointers to direct user input
void (*funcArray[9])(struct Household[])={

        printHByrgn,
        printHByrce,
        printAvgv_income,
        printAverageByTownAndRgn,
        printAvgHByRce,
        printAvgByTownAndRgn,
        prntBelowPvrty,
        prntBelowPvrtyByRce,
        prntBelowPvrtyByTownRgn};

void userChoice(struct Household households[MAX]) {
   int input ;
    do {
        input=getInput();
        switch (input) {
            case 1:

                (*funcArray[0])(households);
                break;

            case 2:
                (*funcArray[1])(households);
                break;

            case 3:

                (*funcArray[2])(households);
                break;

            case 4:

                (*funcArray[3])(households);
                break;

            case 5:
                (*funcArray[4])(households);
                break;

            case 6:
                (*funcArray[6])(households);
                break;

            case 7:
                (*funcArray[7])(households);
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

//Struct variables set to DEFAULT value by default.
int v_rgn = DEFAULT;
int v_Town = DEFAULT;
int v_rce = DEFAULT;

//Function to be able to clear data after user entry. Used in while loops to allow user to reenter data until validation occurs.
void purgeData() {
    int delete;
    while ((delete = getchar()) != '\n' && delete != EOF)
    {}
}

//Region Validation
int RegionInput(){

    printf("Enter appropriate number for the Region:\n");
    printf(" Durham (0), PEEL (1), YORK (2)\n");
    printf("or enter 3 to skip user inputs to generate rest of the records randomly\n");
while (1) {
        //Validate numeric input    Validate Range
    if (scanf("%d", &v_rgn) == 1 || (v_rgn > 0 && v_rgn < 4)) return v_rgn;
    printf("Invalid data. You should enter one integer in the range 0 through 3 or enter 9 to exit Try again\n");
   purgeData();
}

}
//Town input validation
int townInput(){
    while (1) {
        //Validate numeric input    Validate Range
        if (scanf("%d", &v_Town) == 1 || (v_Town >= 0 && v_Town <=1 )) return v_Town;
        printf("Invalid data. You should enter one integer in the range 0 through 1 or enter 9 to exit. Try again\n");
        purgeData();
    }
}



//Race input validation
int raceInput(){

    printf("Enter appropriate number for the race:\n");
    printf(" Caucasian (0), Indigenous (1), African American (2), Asian (3), Others (4) \n");
    while (1) {
        //Validate numeric input    Validate Range
        if (scanf("%d", &v_rce) == 1 || (v_rgn > 0 && v_rgn < 5)) return v_rce;
        printf("Invalid data. You should enter one integer in the range 0 through 4 or enter 9 to exit. Try again\n");
        purgeData();
    }
}
































