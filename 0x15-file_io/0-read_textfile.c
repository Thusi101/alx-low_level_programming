#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w - actual number of bytes read and printed
 * 0 when function fails or filename is NULL.
 *
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	ssize_t nread, nwrite;
	char *buffer;

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
	{
		close(file);
		return (0);
	}

	nread = read(file, buffer, letters);
	close(file);

	if (nread == -1)
	{
		free(buffer);
		return (0);
	}

	nwrite = write(STDOUT_FILENO, buffer, nread);
	free(buffer);

	if (nwrite == -1 || nread != nwrite)
		return (0);

	return (nwrite);
}
