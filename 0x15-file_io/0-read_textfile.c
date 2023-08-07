#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file and print to STDOUT.
 * @filename: The name of the text file to be read.
 * @letters: The number of letters to be read and printed.
 *
 * Return: The actual number of bytes read and printed (w),
 *         0 when the function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;    /* Buffer to store the read data */
	ssize_t fd;   /* File descriptor for the opened file */
	ssize_t w;    /* Number of bytes written to STDOUT */
	ssize_t t;    /* Number of bytes read from the file */

	/* Open the file in read-only mode */
	fd = open(filename, O_RDONLY);
	if (fd == -1) /* Check if the file failed to open */
		return (0);

	/* Allocate memory for the buffer */
	buf = malloc(sizeof(char) * letters);
	if (buf == NULL) /* Check if memory allocation failed */
	{
		close(fd);
		return (0);
	}

	/* Read 'letters' number of bytes from the file into the buffer */
	t = read(fd, buf, letters);
	if (t == -1) /* Check if the read operation failed */
	{
		free(buf);
		close(fd);
		return (0);
	}

	/* Write the contents of the buffer to STDOUT */
	w = write(STDOUT_FILENO, buf, t);

	free(buf); /* Free the allocated memory */
	close(fd); /* Close the file */

	return (w); /* Return the number of bytes written to STDOUT */
}
