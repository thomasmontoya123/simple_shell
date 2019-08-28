#include "shell_header.h"

/**
 * _strcat - concatenate two strings
 * @src: array source
 * @dest: array destination
 *   (* a blank line
 *    * Description: Longer description of the function)?
 *    (* section header: Section description)*
 * Return: string
 *
 */
char *_strcat(char *dest, char *src)
{
	int a = 0;
	int b = 0;

	while (dest[a] != '\0')
	{
		a++;
	}
	while (src[b] != 0)
	{
		dest[a] = src[b];
		a++;
		b++;
	}

	return (dest);

}
