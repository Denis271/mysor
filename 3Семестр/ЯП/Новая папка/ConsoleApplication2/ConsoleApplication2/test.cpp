#include <stdio.h>
#include <stdlib.h>
#include <fstream> // подключаем файлы
#include <iostream>
using namespace std;

struct employee
{
	int empId, hrW, hrR;
	char empName, taxCode;
};

void display(struct employee e1)
{
	printf("%d \t %s \t %d \t %d \t %s \n", e1.empId, e1.empName, e1.hrW, e1.hrR, e1.taxCode);

	return;
}

int main_test(void)
{
	fstream fs;
	int choice, i, ch, option, ok = 0;

	struct employee e1;

	while (ok == 0) {
		// Choices
		printf("1.) Show All Records\n");
		printf("2.) Add 10 Records\n");
		printf("3.) Exit\n\n");
		printf("========================\n");
		printf("Enter Choice: ");
		scanf_s("%d", &choice);
		printf("========================\n");

		switch (choice)
		{
		case 1: printf("\nEmployee ID\t Employee Name\t Hours Worked\t Hourly Rate\n");
			break;

		case 2: printf("Witholding Tax :\n");
			printf("Code:\tDefinition:\tDeduction:");
			printf("\n\nS\tSingle\t\t500");
			printf("\n\nH\tHead of the\t450");
			printf("\n\tFamily");
			printf("\n\nM2\tMarried with\t400");
			printf("\n\t2 dependents");
			printf("\n\nM3\tMarried with\t300");
			printf("\n\t3 dependents");
				printf("\n\nEmployee ID: ");
				scanf_s("%d", &(e1.empId));
				printf("Employee Name: ");
				scanf_s(" %[^\n]s", &(e1.empName));
				printf("Hours Worked: ");
				scanf_s("\n%d", &(e1.hrW));
				printf("Hourly Rate: ");
				scanf_s("\n%d", &(e1.hrR));
				printf("Enter Tax Code: ");
				scanf_s("%s", &(e1.taxCode));
				fs.open("rab.txt", fstream::in | fstream::out | fstream::app);
				fs << "\n" << e1.empId + ';' + e1.empName + ';' + e1.hrR + ';' + e1.taxCode;
			break;
		case 3:
			break;

		default: printf("Invalid Choice");
		}
		printf("\nDo you want to continue? (Y/N): "); // Option choices if you wish to continue
		scanf_s("%s", &option);

		if (option == 'y' || option == 'Y')
		{
			printf("\n");
		}
		else if (option == 'n' || option == 'N')
		{
			ok++;
		}
	}
	return 0;
}
