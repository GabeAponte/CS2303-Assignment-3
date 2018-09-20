/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
 * @author Gabriel Aponte
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup1(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = strlen(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup2(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen2(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/** mystrlen1 calculates the length of the string and knows the string ends at the null terminator of a C-Style String
 * @param str  a pointer to the string you want to find the length of
 * @return an unsigned long that indicates the length of the inputed C-Style string
 */

size_t mystrlen1 (const char *str){
	unsigned long len = 0;
	for (int i=0; str[i] != '\0'; i++){
		len++;
	}
	return len;
}

/** mystrlen2 calculates the length of the string and knows the string ends at the null terminator of a C-Style String
 * @param str  a pointer to the string you want to find the length of
 * @return an unsigned long that indicates the length of the inputed C-Style string
 */

size_t mystrlen2 (const char *str){
	unsigned long len = 0;
	while (*str){
		len++;
		str++;
	}
	return len;
}

/** mystrcpy copies a string from the address of stc to address dest
 * @param dest pointer to the address where the string will be copied to
 * @param stc  pointer to address of string that will be copied
 * @return  the pointer to address of dest
 */

char *mystrcpy(char *dest, char *stc){
	int i;
		for(i = 0; stc[i] != '\0'; i++){
			dest[i] = stc[i];
			i++;
		}
		dest[i] = '\0';
		return dest;
	}

/** mystrcat Appends the string pointed to by src to the end of the string pointed to by dest
 * @param dest a pointer to the destination array that contains the string and is large enough to have the appended string added to it
 * @param src  the string that will be appended
 * @return a pointer to the string that results in dest.
 */

char *mystrcat(char *dest, const char *src){
	int len = strlen(dest);
	for(int i = 0; src[i] != '\0'; i++){
		dest[len] = src[i];
		len++;
	}
	dest[len] = '\0';
	return dest;
}

/** mystrncat Appends the string pointed to by src to the end of the string pointed to by dest, with a limit of n characters
 * @param dest a pointer to the destination array that contains the string and is large enough to have the appended string added to it
 * @param src  the string that will be appended
 * @param n   the maximum number of characters that can be appended
 * @return a pointer to the string that results in dest.
 */

char *mystrncat(char *dest, const char *src, size_t n){
	size_t len = strlen(dest);
	size_t i;
	for (i = 0 ; i < n && src[i] != '\0'; i++){
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return dest;
}

/** mystrncpy copies up to n characters pointed to by src to the array pointed to by dest. When the string is less than n, the
 * 			  remaining spaces are filled by null
 * @param dest a pointer to the destination array where the string is being copied
 * @param src  the string that will be appended
 * @param n   the maximum number of characters that can be copied
 * @return
 */

char *mystrncpy(char *dest, const char *src, size_t n){
	size_t i;
		for (i = 0; i < n && src[i] != '\0'; i++){
			dest[i] = src[i];
		}
		for ( ; i < n; i++){
			dest[i] = '\0';
		}
		return dest;
	}
/** mystrndup Duplicates a C-style string up to n amount of characters.
 * @param src Pointer to string to be copied
 * @param n the maximum number of characters that can be copied
 * @return Pointer to freshly-allocated string containing a duplicate of src or null if no memory is available
 */

char *mystrndup(const char *src, size_t n){
	size_t len = strnlen (src, n);
	char *new = (char *) malloc (len + 1);
	if (new == NULL)
		return NULL;
	new[len] = '\0';
	return (char *) memcpy (new, src, len);
	}







