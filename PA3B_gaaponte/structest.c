#include <stdio.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {

	printf("Tests for makeEmployee(): \n");
	struct Employee *e;
	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	printEmployee(e);
	printf("\n");

	struct Employee *e2;
	e2 = makeEmployee(1964, 1994, "Phil Coulson");
	printEmployee(e2);
	printf("\n");

	struct Employee *e3;
	e3 = makeEmployee(1988, 2010, "Daisy Johnson");
	printEmployee(e3);
	printf("\n");

	struct Employee *e4;
	e4 = makeEmployee(1981, 2006, "Leopold Fitz");
	printEmployee(e4);
	printf("\n");

	struct Employee *e5;
	e5 = makeEmployee(1982, 2006, "Jemma Simmons");
	printEmployee(e5);
	printf("\n");

	printf("Tests for buildRandEmployee(): \n");

	struct Employee *randomEmployee;
	randomEmployee = buildRandEmployee();
	printEmployee(randomEmployee);
	printf("\n");

	printf("Tests for buildRandEmployeeList(): \n");

	printf("Originals: \n");
	struct Employee** employeesOfShield = buildRandEmployeeList(10);
	printEmployee(employeesOfShield[0]);
	printf("Pointer: %p\n", employeesOfShield[0]);
	printf("\n");
	printEmployee(employeesOfShield[1]);
	printf("Pointer: %p\n", employeesOfShield[1]);
	printf("\n");

	printf("Test for shallowDupPointers(): \n");

	printf("Duplicates: \n");
	struct Employee** lmdEmployeesOfShield = shallowDupPointers(10, employeesOfShield);
	printEmployee(lmdEmployeesOfShield[0]);
	printf("Pointer: %p\n", lmdEmployeesOfShield[0]);
	printf("\n");
	printEmployee(lmdEmployeesOfShield[1]);
	printf("Pointer: %p\n", lmdEmployeesOfShield[1]);
	printf("\n");

	printf("Tests for deepDupPointers() (Extra Credit): \n");

	printf("Originals: \n");
	struct Employee** gcpdEmployees = buildRandEmployeeList(10);
	printEmployee(gcpdEmployees[0]);
	printf("Pointer: %p\n", gcpdEmployees[0]);
	printf("\n");
	printEmployee(gcpdEmployees[1]);
	printf("Pointer: %p\n", gcpdEmployees[1]);
	printf("\n");

	printf("Duplicates: \n");
	struct Employee** penguinsGCPDEmployees = deepDupPointers(10, gcpdEmployees);
	printEmployee(penguinsGCPDEmployees[0]);
	printf("Pointer: %p\n", penguinsGCPDEmployees[0]);
	printf("\n");
	printEmployee(penguinsGCPDEmployees[1]);
	printf("Pointer: %p\n", penguinsGCPDEmployees[1]);
	printf("\n");

	freeEmployeePointers(10, employeesOfShield);
	return 0;
}
