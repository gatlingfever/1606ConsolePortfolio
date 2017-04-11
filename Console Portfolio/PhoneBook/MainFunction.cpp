#include "StructHeader.h"

void funcSwapData(st_PersonalData *ptr1, st_PersonalData *ptr2)
{
	st_PersonalData st_Temp;
	st_Temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = st_Temp;
}

void funcInputData(st_PersonalData *ptr_Person)
{
	printf("name : ");		scanf_s("%s", ptr_Person->sName, sizeof(ptr_Person->sName));			getchar();
	printf("Pnum : ");		scanf_s("%s", ptr_Person->sPhoneNumber, sizeof(ptr_Person->sPhoneNumber));	getchar();
	printf("age~ : ");		scanf_s("%d", &ptr_Person->nAge);			getchar();
}

void funcPrintOneData(st_PersonalData *ptr_Person)
{
	printf("name : %s \n", ptr_Person->sName);
	printf("Pnum : %s \n", ptr_Person->sPhoneNumber);
	printf("age~ : %d \n", ptr_Person->nAge);
}

void funcDeleteOneData(st_PersonalData *ptr_Person)
{
	strcpy_s(ptr_Person->sName, "\0");
	strcpy_s(ptr_Person->sPhoneNumber, "\0");
	ptr_Person->nAge = -1;
}