#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * open_files - Opens the source and destination files.
 * @file_from: The name of the source file.
 * @file_to: The name of the destination file.
 * @fd_from: A pointer to the file descriptor for the source file.
 * @fd_to: A pointer to the file descriptor for the destination file.
 *
 * Return: 0 on success, or one of the following exit codes on failure:
 *         98 - if the file_from does not exist or cannot be read
 *         99 - if the file_to cannot be created or written to
 */
int open_files(const char *file_from, const char *file_to, int *fd_from,
		int *fd_to)
{
	*fd_from = open(file_from, O_RDONLY);
	if (*fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	*fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (*fd_to == -1)
	{
		close(*fd_from);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
	return (0);
}

/**
 * copy_file - Copies data from one file to another.
 * @fd_from: The file descriptor for the source file.
 * @fd_to: The file descriptor for the destination file.
 *
 * Return: 0 on success, or one of the following exit codes on failure:
 *         98 - if an error occurs while reading from the source file
 *         99 - if an error occurs while writing to the destination file
 */
int copy_file(int fd_from, int fd_to)
{
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			close(fd_from);
			close(fd_to);
			dprintf(STDERR_FILENO, "Error: Can't write to %d\n", fd_to);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		dprintf(STDERR_FILENO, "Error: Can't read from file %d\n", fd_from);
		exit(98);
	}

	return (0);
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or one of the following exit codes on failure:
 *         97 - if the number of arguments is incorrect
 *         98 - if the file_from does not exist or cannot be read
 *         99 - if the file_to cannot be created or written to
 *         100 - if the file_to or file_from cannot be closed
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	open_files(argv[1], argv[2], &fd_from, &fd_to);
	copy_file(fd_from, fd_to);

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
