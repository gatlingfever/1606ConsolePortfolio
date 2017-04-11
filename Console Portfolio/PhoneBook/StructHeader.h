#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char sName[10];
	char sPhoneNumber[20];
	int nAge;
} st_PersonalData;

void funcSwapData(st_PersonalData *ptr1, st_PersonalData *ptr2);
// void funcArrangeData(st_PersonalData *ptr_Person, int nMemoryCount);

void funcInputData(st_PersonalData *ptr_Person);
void funcPrintOneData(st_PersonalData *ptr_Person);
void funcDeleteOneData(st_PersonalData *ptr_Person);