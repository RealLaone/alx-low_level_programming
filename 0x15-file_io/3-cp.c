#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		/* Print an error message to stderr and exit with code 99 */
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		/* Print an error message to stderr and exit with code 100 */
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	/* Check if the number of arguments is correct */
	if (argc != 3)
	{
		/* Print an error message to stderr and exit with code 97 */
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]); /* Allocate buffer */
	from = open(argv[1], O_RDONLY); /* Open file_from in read-only mode */
	r = read(from, buffer, 1024); /* Read data into the buffer */
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664); /* Open file_to with specific flags */

	do
	{
		/* Check for read errors */
		if (from == -1 || r == -1)
		{
			/* Print an error message to stderr, free buffer, and exit with code 98 */
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		/* Write data from the buffer to file_to */
		w = write(to, buffer, r);
		/* Check for write errors */
		if (to == -1 || w == -1)
		{
			/* Print an error message to stderr, free buffer, and exit with code 99 */
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		/* Read more data into the buffer */
		r = read(from, buffer, 1024);
		/* Open file_to in append mode */
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);

	free(buffer); /* Free the allocated buffer */
	close_file(from); /* Close file_from */
	close_file(to); /* Close file_to */

	return (0); /* Return 0 to indicate successful execution */
}
