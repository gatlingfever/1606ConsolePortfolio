#include "StructHeader.h"

void funcShowMenu()
{
	printf("*** 1. Insert \n");
	printf("*** 2. Delete \n");
	printf("*** 3. Search \n");
	printf("*** 4. Print All \n");
	printf("*** 5. Exit \n");
}


int main()
{
	int nOption(0);
	int nMemoryCount(0);
	int nIndex(0);
	st_PersonalData *st_Person = (st_PersonalData *)malloc(sizeof(st_PersonalData));
	

	printf("*** Welcome! Test Phonebook Program!!!***\n\n");
	

	FILE *strLoadFile;
	fopen_s(&strLoadFile, "PhonebookData.bin", "rb");

	if (strLoadFile == NULL)
		printf("*** Load Fail : PhonebookData.bin doesn't exist *** \n");
	else
	{
		int i(0);
		while (i != 1)
		{
			nMemoryCount++;
			st_Person = (st_PersonalData *)realloc(st_Person, sizeof(st_PersonalData)*nMemoryCount);

			fscanf_s(strLoadFile, "%s", st_Person[nMemoryCount - 1].sName, sizeof(st_Person[nMemoryCount - 1].sName));
			fscanf_s(strLoadFile, "%s", st_Person[nMemoryCount - 1].sPhoneNumber, sizeof(st_Person[nMemoryCount - 1].sPhoneNumber));
			fscanf_s(strLoadFile, "%d", &st_Person[nMemoryCount - 1].nAge);
			
			i++;
		}
		fclose(strLoadFile);
		printf("*** %d Person Loaded \n", i);
	}
			
	while (nOption != -1)
	{
		for (int i = 0; i < nMemoryCount; i++)
		{
			int nPointer(0);
			nPointer = i;
			for (int j = i + 1; j < nMemoryCount; j++)
			{
				if (strcmp(st_Person[i].sName, st_Person[j].sName) > 0)
					nPointer = j;
			}
			funcSwapData(&st_Person[i], &st_Person[nPointer]);
		}
		
		printf("\n");

		funcShowMenu();

		printf("\n*** Your Choose? : ");
		scanf_s("%d", &nOption);

		switch (nOption)
		{
		case 1: 
			nMemoryCount++;
			st_Person = (st_PersonalData *)realloc(st_Person, sizeof(st_PersonalData)*nMemoryCount);
			funcInputData(&st_Person[nMemoryCount - 1]);
			for (int i = 0; i < nMemoryCount - 1; i++)
			{
				if (strcmp(st_Person[nMemoryCount - 1].sName, st_Person[i].sName)==0)
				{
					printf("*** Already ");		printf("%s", st_Person[nMemoryCount - 1].sName);	printf(" Exist! \n");
					printf("*** 1. Delete Original?   2. Ctrl Z? : ");
					int nInputOption(0);
					scanf_s("%d", &nInputOption);
					switch (nInputOption)
					{
					case 1:
						funcDeleteOneData(&st_Person[i]);
						break;
					case 2:
						funcDeleteOneData(&st_Person[nMemoryCount - 1]);
						break;
					default:
						printf("*** Wrong Number! \n\n");
						continue;
					}
				}
			}
			break;	
		case 2: 
			printf("*** Delete Who? : ");
			char sTempNameDelete[20];
			scanf_s("%s", sTempNameDelete, sizeof(sTempNameDelete));
			for (int i = 0; i < nMemoryCount; i++)
			{
				if (strcmp(sTempNameDelete, st_Person[i].sName) == 0)
					funcDeleteOneData(&st_Person[i]);
			}
			break;
		case 3: 
			printf("*** Find Who? : ");
			char sTempNameFind[20];
			scanf_s("%s", sTempNameFind, sizeof(sTempNameFind));
			for (int i = 0; ; i++)
			{
				if (strcmp(sTempNameFind, st_Person[i].sName)==0)
				{
					funcPrintOneData(&st_Person[i]);
					printf("\n");
					break;
				}
				else if (i >= nMemoryCount)
				{
					printf("*** There's no ");
					printf("%s \n\n", sTempNameFind);
					break;
				}
			}
			break;
		case 4:
			for (int i = 0; i < nMemoryCount; i++)
			{
				if (st_Person[i].nAge != -1)
				{
					funcPrintOneData(&st_Person[i]);
					printf("\n");
				}
			}
			break;
		case 5: 
			nOption = -1; 
			break;
		default: 
			printf("*** Wrong Number! \n\n"); 
			break;
		}
	}


	FILE *strSaveFile;
	fopen_s(&strSaveFile, "PhonebookData.bin", "wb+");
	if (strSaveFile == NULL)
	{
		printf("*** Error : Save Failed \n\n");
		main();
	}
	else
	{
		for (int i = 0; i < nMemoryCount; i++)
		{
			if (st_Person[i].nAge != -1)
			{
				fprintf(strSaveFile, "%s ", st_Person[i].sName);
				fprintf(strSaveFile, "%s ", st_Person[i].sPhoneNumber);
				fprintf(strSaveFile, "%d\n", st_Person[i].nAge);
			}
		}
	}

	fclose(strSaveFile);


	free(st_Person);

	
	return 0;
}