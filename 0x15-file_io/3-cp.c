#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer s storing chars.
 * close_file - Closes a file.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
void close_file(int file)
{
	if (close(file) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file);
		exit(100);
	}
}
/**
 * check_read - Checks the result of the read function
 * @nread: The result of the read function
 * @file_from: The source file descriptor
 * @file_to: The destination file descriptor
 * @argv: The argument vector
 */
void check_read(ssize_t nread, int file_from, int file_to, char *argv[])
{
	if (nread == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close_file(file_from);
		close_file(file_to);
		exit(98);
	}
}
/**
 * main - Copies the content of a file to another file
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: 0 on success, or one of 97, 98, 99, 100 on error
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t nread, nwrite;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_file(file_from);
		exit(99);
	}
	while ((nread = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		nwrite = write(file_to, buffer, nread);
		if (nwrite != nread)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_file(file_from);
			close_file(file_to);
			exit(99);
		}
	}
	check_read(nread, file_from, file_to, argv);
	close_file(file_from);
	close_file(file_to);

	return (0);
}
