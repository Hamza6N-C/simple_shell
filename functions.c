#include "shell.h"
/**
 * _strcmp - Compare two strings.
 * @str1: The first string.
 * @str2: The second string.
 * Return: An integer
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * _strlen - Calculate the length of a string
 * @str: the string to calculate the length of
 * Return: The length of the string
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str && *str)
	{
		len++;
		str++;
	}

	return (len);
}
