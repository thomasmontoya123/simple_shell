#include "shell_header.h"

/**
 * _strncmp - compare two strngs
 * @s1: string 1
 * @s2: string 2
 * @n: size
 * Return: integer comparison
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	char c1 = '\0', c2 = '\0';
	size_t n4;

	if (n >= 4)
	{
		n4 = n >> 2;
		do {
			c1 = (unsigned char) *s1++;
			c2 = (unsigned char) *s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);

			c1 = (unsigned char) *s1++;
			c2 = (unsigned char) *s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);

			c1 = (unsigned char) *s1++;
			c2 = (unsigned char) *s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);

			c1 = (unsigned char) *s1++;
			c2 = (unsigned char) *s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);

		} while (--n4 > 0);
	  n &= 3;
	}

	while (n > 0)
	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (c1 == '\0' || c1 != c2)
			return (c1 - c2);
		n--;
	}
	return (c1 - c2);
}
