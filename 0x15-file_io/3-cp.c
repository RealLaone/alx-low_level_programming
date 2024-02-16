#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define ERROR_READ "Error: Can't read from file %s\n"
#define ERROR_WRITE "Error: Can't write to %s\n"
#define ERROR_CLOSE "Error: Can't close fd %d\n"
#define USAGE "Usage: cp file_from file_to\n"

char *create_buffer(char *file);
void close_file(int fd);
void copy_file(int from, int to, char *buffer);

/**
 * create_buffer - Allocates a buffer of a given size.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, ERROR_WRITE, file);
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
		dprintf(STDERR_FILENO, ERROR_CLOSE, fd);
		exit(100);
	}
}

/**
 * copy_file - Copies the contents of one file to another file.
 * @from: The file descriptor of the source file.
 * @to: The file descriptor of the destination file.
 * @buffer: The buffer to store the read bytes.
 */
void copy_file(int from, int to, char *buffer)
{
	int r, w;

	r = read(from, buffer, BUFFER_SIZE);
	while (r > 0)
	{
		w = write(to, buffer, r);
		if (w == -1)
		{
			free(buffer);
			exit(99);
		}
		r = read(from, buffer, BUFFER_SIZE);
	}
	if (r == -1)
	{
		free(buffer);
		exit(98);
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
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		dprintf(STDERR_FILENO, ERROR_READ, argv[1]);
		free(buffer);
		exit(98);
	}
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
	{
		dprintf(STDERR_FILENO, ERROR_WRITE, argv[2]);
		free(buffer);
		exit(99);
	}

	copy_file(from, to, buffer);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
