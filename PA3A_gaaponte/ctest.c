#include <stdio.h>
#include <string.h>
// string.h covers the C-style string functions.
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 * @author Gabriel Aponte
 */

const int MAX_CHARS = 20; // Maximum number of characters in array

int main()
{
	char a1[MAX_CHARS + 1]; // Character array--initially empty
	char a2[] = "Hello"; // Character array--unsized but initialized
	char a3[MAX_CHARS + 1]; // Character array--we will underfill it
	char a4[] = "Welcome"; // Character array--unsized but initialized
	char a5[] = "Bazinga"; // Character array--unsized but initialized
	char* p1 = "Hello"; // Pointer to constant string
	char* p2 = NULL; // Will be a pointer to dynamically-allocated string
	char* p3 = "Hi"; // Pointer to another constant string
	char* p4 = NULL; // Will be a pointer to dynamically-allocated string
	char* p5 = NULL; // Will be a pointer to dynamically-allocated string
	char* p6 = NULL;// Will be a pointer to dynamically-allocated string
	char* p7 = NULL;// Will be a pointer to dynamically-allocated string
	char* p8 = NULL;// Will be a pointer to dynamically-allocated string
	char* p9 = "What a phenomenal testing experience";// Pointer to another constant string
	char* p10 = "Dope";// Pointer to another constant string
	char* p11 = "Amazing!";// Pointer to another constant string

	int copy_limit; // Maximum characters to copy.

	strcpy(a3, "Hello, one more time."); // Initialize underfilled character array

	/* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
	 */

	printf("Initial state:\n");
	printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
	printf("          p1 = %p p2 = %p\n", p1, p2);

	strcpy(a1, p3); // Initialize character array

	printf("a1 = %s\n", a1);
	printf("a2 = %s\n", a2);
	printf("a3 = %s\n", a3);
	printf("a4 = %s\n", a4);
	printf("a5 = %s\n", a5);

	// Note that strlen() returns size_t, which is typedef'd to
	//   unsigned long, so we need to print it with %ld instead of just %d.
	printf("For string /%s/, strlen() returns %ld\n", p1, strlen(p1));
	printf("For string /%s/, mystrlen1() returns %ld\n", p1, mystrlen1(p1));
	printf("For string /%s/, mystrlen2() returns %ld\n", p1, mystrlen2(p1));

	// Duplicate a string, using strdup(), then print
	printf("\nBefore calling strdup(), pointer a2 = %p, contents = %s\n", a2, a2);
	p2 = strdup(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Duplicate a string, using the mystrdup1 function, then print
	printf("\nBefore calling mystrdup1(), pointer a4 = %p, contents = %s\n", a4, a4);
	p4 = mystrdup1(a4);
	printf("Duplicated string: \n");
	printf("Pointer p4 = %p, contents = %s\n", p4, p4);

	// Duplicate a string, using the mystrdup2 function, then print
	printf("\nBefore calling mystrdup2(), pointer a5 = %p, contents = %s\n", a5, a5);
	p5 = mystrdup2(a5);
	printf("Duplicated string: \n");
	printf("Pointer p5 = %p, contents = %s\n", p5, p5);

	// Copy a string, using mystrcpy
	printf("\nBefore calling mystrcpy(), pointer a2 = %p, contents = %s\n", a2, a2);
	printf("The destination where the string will be copied too. Pointer a5 = %p, contents = %s\n", a5, a5);
	mystrcpy(a5, a2);
	printf("The destination after calling the function. Pointer a5 = %p, contents = %s\n", a5, a5);

	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';

	// Concatenate two character arrays, then print.
	strcpy(a1, p3); // Reset character array
	mystrcat(a1, a2);
	printf("\nUsing mystrcat() to concatenate a2 to the end of a1\n");
	printf("a1 = %s\n", a1);

	// Concatenate two character arrays safely, then print.
	strcpy(a1, p3); // Reset character array
	a1[MAX_CHARS] = 'A'; // Remove terminator, to prove strncat() puts it back in.
	copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
	printf("\nUsing mystrncat() to concatenate to the end of a1, with copy_limit = %d\n",
			copy_limit);
	if (copy_limit > 0) strncat(a1, a3, copy_limit);
	printf("a1 = %s\n", a1);

	printf("\nTest cases for mystrncpy()\n");

	//Base case n = src; Copy a string, using mystrncpy, then print.
	printf("\nBefore calling mystrncpy(), Pointer p11 = %p, contents = %s, Value of n: 8\n", p11, p11);
	printf("The destination, where the string will be copied too. Pointer a2 = %p, contents = %s\n", a2, a2);
	mystrncpy(a2, p11, 8);
	printf("Destination after calling the function, Pointer a2 = %p, contents = %s\n", a2, a2);

	//Corner case n < src; Copy a string, using mystrncpy, then print.
	printf("\nBefore calling mystrncpy(), pointer p9 = %p, contents = %s, Value of n: 6\n", p9, p9);
	printf("The destination, where the string will be copied too, Pointer a2 = %p, contents = %s\n", a2, a2);
	mystrncpy(a2, p9, 6);
	printf("The destination after calling the function, Pointer a2 = %p, contents = %s\n", a2, a2);

	//Corner case n > src: Copy a string, using mystrncpy, then print. Extra spaces are filled with null characters
	printf("\nBefore calling mystrncpy(), pointer p10 = %p, contents = %s, Value of n: 12\n", p10, p10);
	printf("The destination, where the string will be copied too, Pointer a2 = %p, contents = %s\n", a2, a2);
	mystrncpy(a2, p10, 12);
	printf("The destination after calling the function, Pointer a2 = %p, contents = %s\n", a2, a2);

	printf("\nTests cases for mystrndup()\n");

	//Base case n = src; Duplicate a string, using mystrndup, then print
	printf("\nThe string to be duplicated by mystrndup(): Pointer p11= %p contents = %s\n", p11, p11);
	printf("The length of String = %lu Value of n for this call of the function = 8\n", strlen(p11));
	p6 = strndup(p11, 8);
	printf("New string: Pointer = %p Contents = %s\n", p6, p6);

	//Corner case n < src; Duplicate a string, using mystrndup, then print
	printf("\nThe string to be duplicated by mystrndup(): Pointer p11 = %p contents = %s\n", p11, p11);
	printf("The length of String = %lu Value of n for this call of the function = 3\n", strlen(p11));
	p7 = strndup(p11, 3);
	printf("New string: Pointer = %p Contents = %s\n", p7, p7);

	//Corner case n > src; Duplicate a string, using mystrndup, then print
	printf("\nThe string to be duplicated by mystrndup(): Pointer p11 = %p contents = %s\n", p11, p11);
	printf("The length of String = %lu Value of n for this call of the function = 10\n", strlen(p11));
	p8 = strndup(p11, 10);
	printf("New string: Pointer p8 = %p Contents = %s\n", p8, p8);

	return 0;
}
