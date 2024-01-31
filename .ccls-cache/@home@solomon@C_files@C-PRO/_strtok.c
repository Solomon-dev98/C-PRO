#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split(char *str, char *delimiter, int *count)
{
	size_t len = 0;
	int i = 0, old_i, string_index =0, j = 0, alloc;
	char **strings, buffer[256];

	/* get lenght of the string. */

	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	 /* use count to keep account of the num of substr. */
	*count = 0;

	/** i will keep track of the index of the string.
	 * determin the number of substrings.
	 */
	
	i = 0;

	while (i < len)
	{
		/* skip over the next group of delimiters. */
		while (i < len)
		{
			if (strchr(delimiter, str[i]) == NULL)
				break;
			i++;
		}

		/* skip over the next group of substring. */

		old_i = i;

		while (i < len)
		{
			/* incre i until the char at index i is found in delim */
			if (strchr(delimiter, str[i]) != NULL)
				break;
			i++;
		}
		if (i >old_i)
			*count = *count + 1;
	}

	/*allocate memory for an array of pointers to strings. */
	strings = malloc(sizeof(char *) * *count);

	/* allocate space for each substring */
	i = 0;

	while (i < len)
	{
		/* skip through the group of delimiters.*/
		while (i < len)
		{
			if (strchr(delimiter, str[i]) == NULL)
				break;
			i++;
		}

		/* store the next substring into the buffer char array. */
		while (i < len && (strchr(delimiter, str[i]) != NULL))
		{
			buffer[j++] = str[i++];
		}

		if (j > 0)
		{
			/*add NULL terminator on the of buffer to X the str. */
			buffer[j] = '\0';
			/* calc how much space to be alloc */
			alloc = sizeof(char) * (strlen(buffer) + 1);

			/* allocate using malloc to store pointers into strs. */
			strings[string_index] = malloc(alloc);

			/* copy the buffer into the alloc space. */
			strcpy(strings[string_index], buffer);

			/* advance string_index so we store the next str. */
			string_index++;
		}
	}
	/* return our array of strings. */
	return (strings);
}
