//
// Created by Abdelrahman Mohamed on 2020-10-13.
//

#ifndef ABDELRAHMANMOHAMEDASSIGN2_HOUSEHOLD_H
#define ABDELRAHMANMOHAMEDASSIGN2_HOUSEHOLD_H


// constant values declaration
#define MAX 100
#define EXIT 9

// Declartion of user defined data type/structure
struct Household
{
    //variables set in order of the assignment
    int v_rgnion;
    int v_twnn;
    int v_rcee;
    int v_szee;
    int v_income;
};

// enumerations declaration
enum v_twnn { WHITBY = 0, OSHAWA, MISSISSAUGA = 0, BRAMPTON, MAPPLE = 0, VAUGHAN };
enum v_rgnion { DURHAM, PEEL, YORK };

enum v_rcee { CAUCASIAN, INDIGENOUS, AFRICAN_AMERICAN, ASIAN, OTHER};

// Input functions
int getPositiveInteger(const char* str);
int getInput();
char* getv_rgnion(int v_rgn);
char* getv_twnn(int v_rgn, int v_twn);
char* getv_rcee(int v_rce);
void userChoice(struct Household households[MAX]);
int regionInput();
int townInput();
int raceInput();






//Print function prototypes
void printHByrgn( struct Household households[MAX]);
void printHByrce( struct Household households[MAX]);
void printAvgHByRce( struct Household households[MAX]);
void printAvgv_income( struct Household households[MAX]);
void printAverageByTwnAndRgn( struct Household households[MAX]);
void printAvgByTwnAndRgn (struct Household households[MAX]);
void printInfo( struct Household households[MAX]);
void prntBelowPvrty( struct Household households[MAX]);
void prntBelowPvrtyByRce( struct Household households[MAX]);
void prntBelowPvrtyByTwnRgn( struct Household households[MAX]);




#endif //ABDELRAHMANMOHAMEDASSIGN2_HOUSEHOLD_H
