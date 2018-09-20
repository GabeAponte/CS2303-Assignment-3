/** mystruct.c
 * @author Mike Ciaraldi
 * @author Gabriel Aponte
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mystruct.h"

/** makeEmployee Allocates an Employee struct and fills in the fields
 * @param birth   The year the employee was born in.
 * @param start   The year the employee started working for the company.
 * @param name    A string that represents the employee's name
 * @return  A pointer to the Employee struct, that is now allocated from the heap.
 */

struct Employee* makeEmployee(int birth, int start, const char *name) {
	struct Employee *aEmployee = malloc(sizeof(struct Employee)); //Allocate memory for a new struct of type Employee.
	aEmployee->birth_year = birth; // Sets the employee's birth year
	aEmployee->start_year = start; // Sets the employee's starting year
	strcpy(aEmployee->name, name); // Sets the employee's name.
	return aEmployee;
}

/** printEmployee Prints the details about an employee to stdout
 * @param e  A pointer to the employee that you want to print out.
 */

void printEmployee(struct Employee *e) {
	printf("%s\n", e->name); // Print employee name
	printf("Birth Year: %d\n", e->birth_year); // Print employee birth year
	printf("Start Year: %d\n", e->start_year); // Print employee start year
}

/** findRandNum Gets any number between 1 and the inputed limit
 * 	@param numLimit  an integer representing the limit of numbers you want to choose from
 *	@return A random number that is within the limit.
 */

int findRandNum(int numLimit){
	return(rand()%numLimit)+1;
}

/** findRandString Gets any string between length and the inputed limit.
 * 	@param numLimit  an integer representing the limit of numbers the string length can be.
 *	@return A random string within the limit.
 */

char *findRandString(int numLimit){
	char *validChars = "QWERTYUIOPASDGHJKLZXCVBNM1234567890qwertyuiopasdfghjklzxcvbnm"; //Initializes an array of valid characters to be picked from.
	char *randString = malloc(numLimit); //Allocates enough space for an array within the limit.
	for(int i=0;i<numLimit;i++){
		randString[i] = validChars[findRandNum(strlen(validChars))]; //Sets the random string's index to that of a random character from validChars.
	}
	return randString;
}

/** buildRandEmployee creates a random employee based off the employee struct
 *	@return A new employee with random data in the fields from the employee struct.
 */

struct Employee* buildRandEmployee(){
	char *name = findRandString(20); //Sets the employee's name to a random string of length 20.
	int birth_year = findRandNum(2002); //Sets the employee's birth year to a random year between 1 and 2000. Must be at least 16 years old to work.
	int start_year = findRandNum(2019); //Sets the employee's starting year to a random year between 1 and 2019
	return makeEmployee(birth_year, start_year, name); //Return a new employee with random data.
}

/** buildRandomEmployeeList creates an array of random employees based off the employee struct
 *	@param numEmployees The total amount of employees to create and add to the array.
 *  @return an array of pointers to random employees
 */

struct Employee** buildRandEmployeeList(int numEmployees){
	struct Employee** arrayOfRandEmployees = malloc(numEmployees * sizeof(struct Employee)); //Allocates enough memory the new array.
	for(int i=0;i<numEmployees;i++){
		arrayOfRandEmployees[i] = buildRandEmployee(); // Create a random employee and add it to the array.
	}
	return arrayOfRandEmployees;
}

/** shallowdupPointers duplicates the pointers from an array of employees using shallow copying.
 *	@param numEmployees   the number of employees it will duplicate.
 *  @param originalEmployeesArray   An array of pointers to employees that will be duplicated.
 *  @return  A duplicated array of pointers of originalEmployeesArray
 */

struct Employee** shallowDupPointers(int numEmployees, struct Employee* originalEmployeesArray[numEmployees]){
	struct Employee** dupedEmployees = malloc(numEmployees*sizeof(struct Employee)); //Allocates enough memory for the new array
	for(int i=0;i<numEmployees;i++){
		dupedEmployees[i] = originalEmployeesArray[i]; //Sets the pointer to the pointer that points of the original array's element.
	}
	return dupedEmployees;
}

/** freeEmployeesPointers lets go of the memory related to the array of employees
 *	@param numEmployees The total number of employees it will free.
 *  @param employeesArray  the array of pointers to employees it will free.
 */

void freeEmployeePointers(int numEmployees, struct Employee* employeesArray[numEmployees]){
	for(int i=0;i<numEmployees;i++){
		free(employeesArray[i]); //Frees the memory of the employee.
	}
}

//EXTRA CREDIT
/** deepDupPointers duplicates the pointers from an array of employees using deep copying.
 *	@param numEmployees   the number of employees to duplicate.
 *  @param originalEmployeesArray   An array of pointers to employees that will be duplicated.
 *  @return An array of pointers that have the same elements as originalArrayOfEmployees but are duplicated.
 */

struct Employee** deepDupPointers(int numEmployees, struct Employee* originalEmployeesArray[numEmployees]){
	struct Employee** dupedEmployees = malloc(numEmployees*sizeof(struct Employee)); //Allocates enough memory for a new array
	for(int i=0;i<numEmployees;i++){
		//Makes a new employee with the data from the index of the original array and then adds the new employee to the new array.
		dupedEmployees[i] = makeEmployee(originalEmployeesArray[i]->birth_year, originalEmployeesArray[i]->start_year, originalEmployeesArray[i]->name);
	}
	return dupedEmployees;
}


