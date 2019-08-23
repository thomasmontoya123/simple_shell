#include "shell_header.h"

/**
 * _atoi - string to int
 * @s: string
 * Return: char pointer
 */
int _atoi(char *s)
{
	int a, neg, number;

	int breaker = 0;

	a = 0;
	neg = -1;
	number = 0;



	while (s[a] != '\0')
	{
		if (s[a] == '-')
		{
			neg = neg * -1;
		}

		if (s[a] >= '0' && s[a] <= '9')
		{
			number = number * 10;
			number = number - (s[a] - '0');
			breaker = 1;
		}
	else if (breaker == 1)
	{
		break;
	}
		a++;
	}
	number = number * neg;
	return (number);
}
