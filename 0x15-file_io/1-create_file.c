#include "main.h"

/**
 * create_file - Creates a file and writes content to it.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - (-1).
 *         Otherwise - (1).
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	/* Check if the filename argument is NULL */
	if (filename == NULL)
		return (-1);

	/* Check if the text_content argument is not NULL */
	if (text_content != NULL)
	{
		/* Loop through text_content to find its length */
		for (len = 0; text_content[len];)
			len++;
	}

	/* Open the file with the specified flags and permissions */
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	/* Write the text_content to the file */
	w = write(fd, text_content, len);

	/* Check if either opening the file or writing to it failed */
	if (fd == -1 || w == -1)
		return (-1);

	/* Close the file */
	close(fd);

	/* Return 1 to indicate successful execution */
	return (1);
}
