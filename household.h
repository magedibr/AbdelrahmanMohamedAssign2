//
// Created by Abdelrahman Mohamed on 2020-10-13.
//

#ifndef ABDELRAHMANMOHAMEDASSIGN2_HOUSEHOLD_H
#define ABDELRAHMANMOHAMEDASSIGN2_HOUSEHOLD_H


// constant values declaration
#define MAX 100
#define EXIT 9

// structure declaration
struct Household
{
    int v_rgnion;
    int v_twnn;
    int v_rcee;
    int v_szee;
    int v_income;
};

// enumerations declaration
enum v_rgnion { DURHAM, PEEL, YORK };
enum v_twnn { WHITBY = 0, OSHAWA, MISSISSAUGA = 0, BRAMPTON, MAPPLE = 0, VAUGHAN };
enum v_rcee { CAUCASIAN, INDIGENOUS, AFRICAN_AMERICAN, ASIAN, OTHER};

// function prototypes
char* getv_rgnion(int v_rgn);
char* getv_twnn(int v_rgn, int v_twn);
char* getv_rcee(int v_rce);
int getPositiveInteger(const char* str);
void printInfo(const struct Household households[MAX]);
int getMenuChoice();
void printHByrgn(const struct Household households[MAX]);
void printHByrce(const struct Household households[MAX]);
void printAvgv_income(const struct Household households[MAX]);
void printAverageByTwnAndRgn(const struct Household households[MAX]);
void printAvgByTwnAndRgn(const struct Household households[MAX]);
int Pvrty(const struct Household households[MAX], int i);
void prntBelowPvrty(const struct Household households[MAX]);
void prntBelowPvrtyByRce(const struct Household households[MAX]);
void prntBelowPvrtyByTwnRgn(const struct Household households[MAX]);
#endif //ABDELRAHMANMOHAMEDASSIGN2_HOUSEHOLD_H
