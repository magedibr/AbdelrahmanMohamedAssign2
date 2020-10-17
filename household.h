//
// Created by Abdelrahman Mohamed on 2020-10-13.
//

#ifndef ABDELRAHMANMOHAMEDASSIGN2_HOUSEHOLD_H
#define ABDELRAHMANMOHAMEDASSIGN2_HOUSEHOLD_H


// constant values declaration
#define MAX 100
#define DEFAULT 9

// Declaration of user defined data type/structure
struct Household
{
    //Household variables
    int v_Region;
    int v_Town;
    int v_Race;
    int v_Size;
    int v_income;
};

// enumerations declaration
enum v_Town { WHITBY = 0, OSHAWA, MISSISSAUGA = 0, BRAMPTON, MAPPLE = 0, VAUGHAN };
enum v_Region { DURHAM, PEEL, YORK };
enum v_Race { CAUCASIAN, INDIGENOUS, AFRICAN_AMERICAN, ASIAN, OTHER};

// Input functions Prototypes
void clearingData();
void validateFamilyAndIncome(int *ptr);
int getInput();
char* getv_Region(int v_rgn);
char* getv_Town(int v_rgn, int v_Town);
char* getv_Race(int v_rce);
void userChoice(struct Household households[MAX]);
int RegionInput();
int townInput();
int raceInput();



//Print function prototypes
void printHByrgn( struct Household households[MAX]);
void printHByrce( struct Household households[MAX]);
void printAvgHByRce( struct Household households[MAX]);
void printAvgv_income( struct Household households[MAX]);
void printAverageByTownAndRgn( struct Household households[MAX]);
void printAvgByTownAndRgn (struct Household households[MAX]);
void printInfo( struct Household households[MAX]);
void prntBelowPvrty( struct Household households[MAX]);
void prntBelowPvrtyByRce( struct Household households[MAX]);
void prntBelowPvrtyByTownRgn( struct Household households[MAX]);




#endif //ABDELRAHMANMOHAMEDASSIGN2_HOUSEHOLD_H
