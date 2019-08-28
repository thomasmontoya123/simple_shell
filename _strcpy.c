#include "shell_header.h"
/**
 * _strcpy - function that prints n elements
 * @src: array source
 * @dest: array destination
 *   (* a blank line
 *    * Description: Longer description of the function)?
 *    (* section header: Section description)*
 * Return: char pointer
 *
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != 0; a++)
	{
		dest[a] = src[a];
	}

	dest[a] = '\0';
	return (dest);
}
