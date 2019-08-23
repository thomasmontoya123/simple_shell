/**
 * _strspn - gets the length of a prefix substring.
 * @s: Array to be scanned
 * @accept: Char to find
 *
 * Return: Pointer to the first ocurrence,
 * otherwiise NULL
 */
unsigned int _strspn(char *s, const char *accept)
{
	unsigned int i = 0;
	unsigned int j = 0;
	int count = 0;

	while (s[i] != '\0')
	{
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				count++;
				break;
			}
		j++;
		}

		if (accept[j] == '\0')
		{
			break;
		}
	j = 0;
	i++;
	}

	return (count);
}

