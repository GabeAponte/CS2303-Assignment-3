/** mystruct.h
 * @author Mike Ciaraldi
 * @uthor Gabriel Aponte
 * Sample structs
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee *makeEmployee(int birth, int start, const char* name);
void printEmployee(struct Employee *e);
int findRandNum(int numLimit);
char *findRandString(int numLimit);
struct Employee* buildRandEmployee();
struct Employee** buildRandEmployeeList(int numEmployees);
struct Employee** shallowDupPointers(int numEmployees, struct Employee* originalEmployeesArray[numEmployees]);
struct Employee** deepDuplication(int numberOfEmployees, struct Employee* arrayOfEmployees[numberOfEmployees]);
void freeEmployeePointers(int numEmployees, struct Employee* employeesArray[numEmployees]);
struct Employee** deepDupPointers(int numEmployees, struct Employee* originalEmployeesArray[numEmployees]);



