#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - (-1).
 *         If file doesn't exist or user lacks write permissions - (-1).
 *         Otherwise - (1).
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	/* Check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/* Calculate the length of text_content if it is not NULL */
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	/* Open the file with write-only mode and append if it exists */
	o = open(filename, O_WRONLY | O_APPEND);
	/* Write text_content to the file */
	w = write(o, text_content, len);

	/* Check if either opening the file or writing to it failed */
	if (o == -1 || w == -1)
		return (-1);

	/* Close the file */
	close(o);

	/* Return 1 to indicate successful execution */
	return (1);
}
